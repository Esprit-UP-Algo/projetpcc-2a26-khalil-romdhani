#include "gestionseanceui.h"
#include "gereseance.h"
#include "vehSQL.h"
#include "Candidat.h"
#include "GereCandidat.h"
#include "statistics.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>
#include <QVBoxLayout>
#include <QTextCharFormat>
#include <QListWidgetItem>
#include <QTime>
#include <QSqlError>
#include <QTableWidgetItem>
#include <QLabel>

GestionSeanceUI::GestionSeanceUI(Ui::MainWindow *ui, QObject *parent)
    : QObject(parent), m_ui(ui), m_isEditingSeance(false), m_currentSeanceId(-1),
    m_statsChartView(nullptr), m_statsSeries(nullptr)
{
}

GestionSeanceUI::~GestionSeanceUI()
{
    delete m_statsSeries;
    delete m_statsChartView;
}

void GestionSeanceUI::initialiserUI()
{
    // Configuration initiale
    m_ui->date_s->setDate(QDate::currentDate());
    m_ui->deb_s->setTime(QTime(8, 0));
    m_ui->fin_s->setTime(QTime(9, 0));

    // Initialiser les composants
    auto chartLayout = new QVBoxLayout(m_ui->circleStatsContainer);
    chartLayout->setContentsMargins(0, 0, 0, 0);
    chartLayout->setSpacing(0);

    m_statsChartView = new QChartView(m_ui->circleStatsContainer);
    m_statsChartView->setRenderHint(QPainter::Antialiasing);
    m_statsChartView->setStyleSheet("background: transparent;");
    chartLayout->addWidget(m_statsChartView);
    initialiserCercleStatistiques();

    afficherSeances();
    initialiserComboboxSeances();
    initialiserCarte();

    // Connexions des signaux
    connect(m_ui->date_s, &QDateEdit::dateChanged, this, &GestionSeanceUI::initialiserComboboxSeances);
    connect(m_ui->deb_s, &QTimeEdit::timeChanged, this, &GestionSeanceUI::initialiserComboboxSeances);
    connect(m_ui->fin_s, &QTimeEdit::timeChanged, this, &GestionSeanceUI::initialiserComboboxSeances);
    connect(m_ui->lon_dep, &QLineEdit::textChanged, this, &GestionSeanceUI::mettreAJourCarte);
    connect(m_ui->lat_ar, &QLineEdit::textChanged, this, &GestionSeanceUI::mettreAJourCarte);
    connect(m_ui->lon_ariv, &QLineEdit::textChanged, this, &GestionSeanceUI::mettreAJourCarte);
    connect(m_ui->lat_arriv, &QLineEdit::textChanged, this, &GestionSeanceUI::mettreAJourCarte);
}

void GestionSeanceUI::afficherSeances()
{
    QSqlQueryModel *model = m_seance.afficher();

    m_ui->tab_s->setRowCount(0);
    m_ui->tab_s->setColumnCount(13);

    QStringList headers;
    headers << "ID Séance" << "Type" << "Date" << "Heure début" << "Heure fin"
            << "Salle" << "Circuit départ" << "Longitude" << "Latitude départ"
            << "Longitude arrivée" << "Latitude arrivée"
            << "Matricule Véhicule" << "Nom Candidat";
    m_ui->tab_s->setHorizontalHeaderLabels(headers);

    m_ui->tab_s->setRowCount(model->rowCount());
    for (int i = 0; i < model->rowCount(); ++i) {
        for (int j = 0; j < 13; ++j) {
            QString data = model->data(model->index(i, j)).toString();
            m_ui->tab_s->setItem(i, j, new QTableWidgetItem(data));
        }
    }

    m_ui->tab_s->resizeColumnsToContents();
    delete model;

    chargerSeancesCalendrier();
}

void GestionSeanceUI::initialiserComboboxSeances()
{
    // Récupérer la date et l'heure depuis l'interface
    QDate date = m_ui->date_s->date();
    QString heureDebut = m_ui->deb_s->time().toString("hh:mm AP");
    QString heureFin = m_ui->fin_s->time().toString("hh:mm AP");
    int idSeanceExclue = m_isEditingSeance ? m_currentSeanceId : -1;

    // Initialiser le combobox des candidats disponibles
    Candidat c;
    QSqlQueryModel* modelCandidats;
    if (date.isValid() && !heureDebut.isEmpty() && !heureFin.isEmpty()) {
        modelCandidats = c.getCandidatsDisponibles(date, heureDebut, heureFin, idSeanceExclue);
    } else {
        modelCandidats = c.getCandidatsDisponibles();
    }
    m_ui->combo_candidat->clear();
    m_ui->combo_candidat->setEditable(false);
    m_ui->combo_candidat->addItem("Sélectionner un candidat", "");

    qDebug() << "📊 Nombre de candidats disponibles:" << modelCandidats->rowCount();
    for (int i = 0; i < modelCandidats->rowCount(); ++i) {
        QString nomCandidat = modelCandidats->data(modelCandidats->index(i, 0)).toString();
        QString nomComplet = modelCandidats->data(modelCandidats->index(i, 1)).toString();
        qDebug() << "  - Candidat:" << nomComplet << "(NOM_C:" << nomCandidat << ")";
        m_ui->combo_candidat->addItem(nomComplet, nomCandidat);
    }
    delete modelCandidats;

    // Initialiser le combobox des véhicules disponibles
    vehSQL v;
    QSqlQueryModel* modelVehicules;
    if (date.isValid() && !heureDebut.isEmpty() && !heureFin.isEmpty()) {
        modelVehicules = v.getVehiculesDisponibles(date, heureDebut, heureFin, idSeanceExclue);
    } else {
        modelVehicules = v.getVehiculesDisponibles();
    }
    m_ui->combo_vehicule->clear();
    m_ui->combo_vehicule->setEditable(false);
    m_ui->combo_vehicule->addItem("Sélectionner un véhicule", "");

    qDebug() << "📊 Nombre de véhicules disponibles:" << modelVehicules->rowCount();
    for (int i = 0; i < modelVehicules->rowCount(); ++i) {
        QString matricule = modelVehicules->data(modelVehicules->index(i, 0)).toString();
        QString vehiculeInfo = modelVehicules->data(modelVehicules->index(i, 1)).toString();
        qDebug() << "  - Véhicule:" << vehiculeInfo << "(MATRICULE:" << matricule << ")";
        m_ui->combo_vehicule->addItem(vehiculeInfo, matricule);
    }
    delete modelVehicules;
}

void GestionSeanceUI::afficherStatistiques()
{
    qDebug() << "🔄 Début de l'actualisation des statistiques...";

    // Vérification basique de la connexion
    QSqlQuery testQuery;
    if (!testQuery.exec("SELECT 1 FROM DUAL")) {
        QMessageBox::critical(nullptr, "Erreur base de données", "Impossible de se connecter à la base de données.");
        return;
    }

    // Vérifier s'il y a des séances
    testQuery.prepare("SELECT COUNT(*) FROM SEANCES");
    if (testQuery.exec() && testQuery.next()) {
        int totalSeances = testQuery.value(0).toInt();
        qDebug() << "🔍 Séances totales dans la base:" << totalSeances;

        if (totalSeances == 0) {
            QMessageBox::information(nullptr, "Base vide", "La table SEANCES est vide.\nAjoutez des séances d'abord.");

            m_ui->label_totalSessions->setText("Total des séances: 0");
            m_ui->label_totalHours->setText("Heures totales: 0h");
            mettreAJourCercleStatistiques(QMap<QString, int>());

            m_ui->stats_s->clear();
            m_ui->stats_s->setRowCount(0);
            m_ui->stats_s->setColumnCount(4);
            QStringList headers;
            headers << "Type" << "Nb séances" << "Heures totales" << "Moniteurs";
            m_ui->stats_s->setHorizontalHeaderLabels(headers);
            return;
        }
    } else {
        qDebug() << "❌ Erreur COUNT:" << testQuery.lastError().text();
        QMessageBox::critical(nullptr, "Erreur", "Impossible de compter les séances.");
        return;
    }

    Statistics stats;

    // Mettre à jour les labels principaux
    int totalSeances = stats.getTotalSeances();
    double heuresTotales = stats.getHeuresTotales();
    QMap<QString, int> statsParType = stats.getSeancesParType();

    m_ui->label_totalSessions->setText("Total des séances: " + QString::number(totalSeances));
    m_ui->label_totalHours->setText("Heures totales: " + QString::number(heuresTotales, 'f', 1) + "h");
    mettreAJourCercleStatistiques(statsParType);

    qDebug() << "📊 Totaux calculés - Séances:" << totalSeances << "Heures:" << heuresTotales;

    // Remplir le tableau des statistiques PAR TYPE
    QSqlQueryModel *model = stats.getTableauStatsParType();

    QSqlError error = model->lastError();
    if (error.isValid()) {
        qDebug() << "❌ Erreur modèle:" << error.text();
        QMessageBox::critical(nullptr, "Erreur calcul", QString("Erreur lors du calcul des statistiques:\n%1").arg(error.text()));
        delete model;
        return;
    }

    m_ui->stats_s->clear();
    m_ui->stats_s->setRowCount(0);
    m_ui->stats_s->setColumnCount(4);

    QStringList headers;
    headers << "Type" << "Nb séances" << "Heures totales" << "Moniteurs";
    m_ui->stats_s->setHorizontalHeaderLabels(headers);

    int rowCount = model->rowCount();
    m_ui->stats_s->setRowCount(rowCount);

    qDebug() << "📋 Remplissage du tableau avec" << rowCount << "lignes";

    if (rowCount > 0) {
        double totalHeuresTableau = 0.0;

        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < 4; ++col) {
                QString data = model->data(model->index(row, col)).toString();
                QTableWidgetItem *item = new QTableWidgetItem(data);

                if (col == 1 || col == 2) {
                    item->setTextAlignment(Qt::AlignCenter);

                    if (col == 2) {
                        QString heuresStr = data;
                        heuresStr.replace("h", "").replace("Calcul...", "0").replace("À calculer", "0");
                        bool ok;
                        double heures = heuresStr.toDouble(&ok);
                        if (ok) {
                            totalHeuresTableau += heures;
                        }
                    }
                } else {
                    item->setTextAlignment(Qt::AlignLeft);
                }

                m_ui->stats_s->setItem(row, col, item);
            }
        }

        m_ui->stats_s->resizeColumnsToContents();
        m_ui->stats_s->setAlternatingRowColors(true);
        m_ui->stats_s->horizontalHeader()->setStretchLastSection(true);

        if (qAbs(heuresTotales - totalHeuresTableau) > 0.1) {
            qDebug() << "⚠️ Différence détectée - Total général:" << heuresTotales << "vs Tableau:" << totalHeuresTableau;
        }

        bool hasUnspecified = false;
        for (int row = 0; row < rowCount; ++row) {
            QString type = m_ui->stats_s->item(row, 0)->text();
            if (type == "Non spécifié" || type.contains("spécifié", Qt::CaseInsensitive)) {
                hasUnspecified = true;
                break;
            }
        }

        QString message;
        if (hasUnspecified) {
            message = QString("Statistiques affichées !\n%1 catégories trouvées (dont 'Non spécifié').\nTotal: %2 séances, %3 heures\nPensez à renseigner les types de séances pour plus de détails.")
                          .arg(rowCount).arg(totalSeances).arg(heuresTotales, 0, 'f', 1);
        } else {
            message = QString("Statistiques actualisées !\n%1 types de séances trouvés.\nTotal: %2 séances, %3 heures")
                          .arg(rowCount).arg(totalSeances).arg(heuresTotales, 0, 'f', 1);
        }

        QMessageBox::information(nullptr, "Statistiques", message);

    } else {
        QString message = QString("Total général: %1 séances, %2 heures\nLe détail par type n'est pas disponible.\nVérifiez que les séances ont des types définis.")
                              .arg(totalSeances).arg(heuresTotales, 0, 'f', 1);

        QMessageBox::information(nullptr, "Statistiques générales", message);

        m_ui->stats_s->setRowCount(1);
        m_ui->stats_s->setItem(0, 0, new QTableWidgetItem("Total général"));
        m_ui->stats_s->setItem(0, 1, new QTableWidgetItem(QString::number(totalSeances)));
        m_ui->stats_s->setItem(0, 2, new QTableWidgetItem(QString::number(heuresTotales, 'f', 1) + "h"));
        m_ui->stats_s->setItem(0, 3, new QTableWidgetItem("Types non spécifiés"));
    }

    delete model;
    qDebug() << "✅ Actualisation des statistiques terminée";
}

void GestionSeanceUI::initialiserCercleStatistiques()
{
    m_statsSeries = new QPieSeries(this);
    m_statsSeries->setHoleSize(0.45);
    m_statsSeries->setPieSize(0.9);
    m_statsSeries->setLabelsVisible(true);
    m_statsSeries->setLabelsPosition(QPieSlice::LabelOutside);

    auto chart = new QChart();
    chart->addSeries(m_statsSeries);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setBackgroundRoundness(0);
    chart->setBackgroundBrush(Qt::NoBrush);
    chart->setPlotAreaBackgroundVisible(false);
    chart->setTitle("Répartition des séances par type");
    chart->setTitleBrush(QBrush(Qt::white));

    if (auto legend = chart->legend()) {
        legend->setVisible(true);
        legend->setAlignment(Qt::AlignBottom);
        legend->setLabelColor(Qt::white);
    }

    m_statsChartView->setChart(chart);
}

void GestionSeanceUI::mettreAJourCercleStatistiques(const QMap<QString, int> &statsParType)
{
    if (!m_statsSeries) return;

    m_statsSeries->clear();

    auto chart = m_statsChartView ? m_statsChartView->chart() : nullptr;
    if (statsParType.isEmpty()) {
        if (chart) chart->setTitle("Aucune donnée disponible");
        auto slice = m_statsSeries->append("Aucune séance", 1);
        slice->setBrush(QColor("#2B3A55"));
        slice->setLabelColor(Qt::white);
        slice->setPen(QPen(Qt::white, 1));
        return;
    }

    if (chart) chart->setTitle("Répartition des séances par type");

    int totalSeances = 0;
    for (auto value : statsParType) totalSeances += value;

    const QList<QColor> palette = {
        QColor("#00C851"), QColor("#33B5E5"), QColor("#FFBB33"),
        QColor("#AA66CC"), QColor("#FF4444"), QColor("#2BBBAD"), QColor("#4285F4")
    };

    int colorIndex = 0;
    for (auto it = statsParType.constBegin(); it != statsParType.constEnd(); ++it) {
        auto slice = m_statsSeries->append(it.key(), it.value());
        slice->setBrush(palette.at(colorIndex % palette.size()));
        slice->setPen(QPen(Qt::white, 1));

        double pourcentage = totalSeances == 0 ? 0.0 : (static_cast<double>(it.value()) / totalSeances) * 100.0;

        slice->setLabel(QString("%1\n%2 séances (%3%)").arg(it.key()).arg(it.value()).arg(QString::number(pourcentage, 'f', pourcentage < 10.0 ? 1 : 0)));
        slice->setLabelColor(Qt::white);
        slice->setLabelFont(QFont("Segoe UI", 8, QFont::Bold));
        ++colorIndex;
    }
}

void GestionSeanceUI::chargerSeancesCalendrier()
{
    m_seancesCalendrier.clear();

    QSqlQuery query;
    QString queryStr = "SELECT ID_SEANCE, NVL(TYPE_S, 'Non spécifié') AS TYPE_S, DATE_S, "
                       "HEURE_DEBUT_S, HEURE_FIN_S, NVL(SALLE_S, 'Non spécifiée') AS SALLE_S, "
                       "NVL(NOM_C, 'Non spécifié') AS NOM_CANDIDAT, "
                       "NVL(MATRICULE, 'Non spécifiée') AS MATRICULE_VEHICULE "
                       "FROM SEANCES ORDER BY DATE_S, HEURE_DEBUT_S";

    if (!query.exec(queryStr)) {
        qDebug() << "❌ Erreur chargement calendrier:" << query.lastError().text();
        mettreEnEvidenceDatesSeances();
        afficherSeancesPourDate(m_ui->calendar_s->selectedDate());
        return;
    }

    while (query.next()) {
        int id = query.value(0).toInt();
        QString type = query.value(1).toString().trimmed();
        if (type.isEmpty()) type = "Non spécifié";

        QDate date = query.value(2).toDate();
        if (!date.isValid()) {
            QDateTime dt = query.value(2).toDateTime();
            if (dt.isValid()) date = dt.date();
        }
        if (!date.isValid()) {
            QString dateStr = query.value(2).toString();
            date = QDate::fromString(dateStr, "dd/MM/yyyy");
        }
        if (!date.isValid()) continue;

        QString heureDebut = query.value(3).toString();
        QString heureFin = query.value(4).toString();
        QString salle = query.value(5).toString().trimmed();
        if (salle.isEmpty()) salle = "Non spécifiée";
        QString candidat = query.value(6).toString().trimmed();
        if (candidat.isEmpty()) candidat = "Non spécifié";
        QString matricule = query.value(7).toString().trimmed();
        if (matricule.isEmpty()) matricule = "Non spécifiée";

        QString detail = QString("ID: %1 | Type: %2 | Salle: %3 | Candidat: %4 | Véhicule: %5 | %6-%7")
                             .arg(id).arg(type).arg(salle).arg(candidat).arg(matricule)
                             .arg(heureDebut.isEmpty() ? "??" : heureDebut)
                             .arg(heureFin.isEmpty() ? "??" : heureFin);

        m_seancesCalendrier[date].append(detail);
    }

    mettreEnEvidenceDatesSeances();
    afficherSeancesPourDate(m_ui->calendar_s->selectedDate());
}

void GestionSeanceUI::mettreEnEvidenceDatesSeances()
{
    QTextCharFormat defaultFormat;
    for (const QDate &date : m_datesMarquees) {
        m_ui->calendar_s->setDateTextFormat(date, defaultFormat);
    }
    m_datesMarquees.clear();

    if (m_seancesCalendrier.isEmpty()) return;

    QTextCharFormat highlightFormat;
    highlightFormat.setBackground(QColor("#00C851"));
    highlightFormat.setForeground(Qt::white);
    highlightFormat.setFontWeight(QFont::Bold);

    for (auto it = m_seancesCalendrier.constBegin(); it != m_seancesCalendrier.constEnd(); ++it) {
        QString tooltip = QString("Séance(s) prévue(s) le %1:\n\n").arg(it.key().toString("dd/MM/yyyy"));
        for (const QString &detail : it.value()) {
            tooltip += "• " + detail + "\n";
        }
        highlightFormat.setToolTip(tooltip);

        m_ui->calendar_s->setDateTextFormat(it.key(), highlightFormat);
        m_datesMarquees.insert(it.key());
    }
}

void GestionSeanceUI::afficherSeancesPourDate(const QDate &date)
{
    if (!m_ui || !m_ui->listWidget_sessions) return;

    m_ui->listWidget_sessions->clear();
    const QStringList details = m_seancesCalendrier.value(date);

    if (details.isEmpty()) {
        QListWidgetItem *item = new QListWidgetItem("Aucune séance planifiée pour cette date.");
        item->setForeground(QColor("#888888"));
        m_ui->listWidget_sessions->addItem(item);
        return;
    }

    QString header = QString("📅 %1 séance(s) le %2").arg(details.size()).arg(date.toString("dd/MM/yyyy"));
    QListWidgetItem *headerItem = new QListWidgetItem(header);
    QFont headerFont = headerItem->font();
    headerFont.setBold(true);
    headerFont.setPointSize(headerFont.pointSize() + 2);
    headerItem->setFont(headerFont);
    headerItem->setForeground(QColor("#FFFFFF"));
    headerItem->setBackground(QColor("#00C851"));
    m_ui->listWidget_sessions->addItem(headerItem);

    for (const QString &detail : details) {
        QListWidgetItem *item = new QListWidgetItem("  • " + detail);
        item->setForeground(QColor("#000000"));
        item->setBackground(QColor("#E3F2FD"));
        QFont itemFont = item->font();
        itemFont.setBold(true);
        itemFont.setPointSize(itemFont.pointSize() + 1);
        item->setFont(itemFont);
        m_ui->listWidget_sessions->addItem(item);
    }
}

void GestionSeanceUI::initialiserCarte()
{
    QLabel *mapLabel = new QLabel(m_ui->groupBox_map);
    mapLabel->setObjectName("mapLabel");
    mapLabel->setGeometry(20, 80, 700, 400);
    mapLabel->setStyleSheet("border: 2px solid #0074D9; border-radius: 5px; background-color: #E8F4FD; color: #0074D9; font-size: 14px; font-weight: bold;");
    mapLabel->setAlignment(Qt::AlignCenter);
    mapLabel->setWordWrap(true);

    mettreAJourCarte();
}

void GestionSeanceUI::mettreAJourCarte()
{
    QLabel *mapLabel = m_ui->groupBox_map->findChild<QLabel*>("mapLabel");
    if (mapLabel) {
        QString lonDep = m_ui->lon_dep->text().trimmed();
        QString latDep = m_ui->lat_ar->text().trimmed();
        QString lonArr = m_ui->lon_ariv->text().trimmed();
        QString latArr = m_ui->lat_arriv->text().trimmed();

        if (lonDep.isEmpty()) lonDep = "10.1650";
        if (latDep.isEmpty()) latDep = "36.8065";
        if (lonArr.isEmpty()) lonArr = "10.1750";
        if (latArr.isEmpty()) latArr = "36.8165";

        QString typeCarte = m_ui->mapType_s->currentText();

        QString displayText = QString(
                                  "<html><body style='font-family: Arial, sans-serif;'>"
                                  "<h2 style='color: #0074D9; margin-bottom: 20px;'>🗺️ Planification des Trajets</h2>"
                                  "<div style='background: white; padding: 15px; border-radius: 8px; margin: 10px;'>"
                                  "<h3 style='color: #FF4444; margin: 0;'>📍 Point de départ</h3>"
                                  "<p style='margin: 5px 0;'>Longitude: <strong>%1</strong></p>"
                                  "<p style='margin: 5px 0;'>Latitude: <strong>%2</strong></p>"
                                  "</div>"
                                  "<div style='background: white; padding: 15px; border-radius: 8px; margin: 10px;'>"
                                  "<h3 style='color: #44FF44; margin: 0;'>📍 Point d'arrivée</h3>"
                                  "<p style='margin: 5px 0;'>Longitude: <strong>%3</strong></p>"
                                  "<p style='margin: 5px 0;'>Latitude: <strong>%4</strong></p>"
                                  "</div>"
                                  "<div style='background: #F0F8FF; padding: 10px; border-radius: 5px; margin: 10px;'>"
                                  "<p style='margin: 0; color: #666;'>Type de carte: <strong>%5</strong></p>"
                                  "<p style='margin: 5px 0; font-size: 12px; color: #888;'>"
                                  "💡 Les coordonnées sont automatiquement mises à jour<br>"
                                  "lorsque vous modifiez les champs longitude/latitude."
                                  "</p>"
                                  "</div>"
                                  "</body></html>"
                                  ).arg(lonDep, latDep, lonArr, latArr, typeCarte);

        mapLabel->setText(displayText);
    }
}

// ==================== SLOTS ====================

void GestionSeanceUI::on_refresh_s_clicked()
{
    afficherStatistiques();
}

void GestionSeanceUI::on_confirm_ajout_s_clicked()
{
    if (GereSeance::confirmerSeance(m_ui, m_seance, m_isEditingSeance, m_currentSeanceId)) {
        afficherSeances();
        initialiserComboboxSeances();
    }
}

void GestionSeanceUI::on_confirm_s_clicked()
{
    QString valeur = m_ui->recherche_s->text().trimmed();

    if (valeur.isEmpty()) {
        QMessageBox::warning(nullptr, "Champ vide", "Veuillez saisir un ID ou un type de séance à rechercher !");
        m_ui->recherche_s->setFocus();
        return;
    }

    bool isNumeric;
    valeur.toInt(&isNumeric);

    if (isNumeric && valeur.toInt() > 0 && !valeur.contains(" ") && !valeur.contains("-") && !valeur.contains("/")) {
        QSqlQueryModel *model = m_seance.rechercher("ID", valeur);

        m_ui->tab_s->setRowCount(0);
        m_ui->tab_s->setRowCount(model->rowCount());

        for (int i = 0; i < model->rowCount(); ++i) {
            for (int j = 0; j < 13; ++j) {
                QString data = model->data(model->index(i, j)).toString();
                m_ui->tab_s->setItem(i, j, new QTableWidgetItem(data));
            }
        }

        if (model->rowCount() == 0) {
            QMessageBox::information(nullptr, "Recherche par ID", "Aucune séance trouvée avec cet ID !");
        } else {
            QMessageBox::information(nullptr, "Recherche par ID", QString("%1 séance(s) trouvée(s) avec l'ID : %2").arg(model->rowCount()).arg(valeur));
        }

        delete model;
    } else {
        GereSeance::rechercherSeanceParType(m_ui, m_seance, valeur);
    }
}

void GestionSeanceUI::on_tab_s_clicked(const QModelIndex &index)
{
    GereSeance::chargerSeancePourModification(m_ui, index, m_isEditingSeance, m_currentSeanceId);
}

void GestionSeanceUI::on_supp_s_clicked()
{
    if (GereSeance::supprimerSeance(m_ui, m_seance, m_isEditingSeance, m_currentSeanceId)) {
        afficherSeances();
        initialiserComboboxSeances();
    }
}

void GestionSeanceUI::on_reins_s_clicked()
{
    GereSeance::reinitialiserFormulaire(m_ui);
    m_isEditingSeance = false;
    m_currentSeanceId = -1;
    QMessageBox::information(nullptr, "Réinitialisation", "Formulaire réinitialisé avec succès !");
}

void GestionSeanceUI::on_filtre_s_clicked()
{
    QString valeur = m_ui->recherche_s->text().trimmed();

    if (valeur.isEmpty()) {
        QMessageBox::warning(nullptr, "Champ vide", "Veuillez saisir un ID ou un type de séance à rechercher !");
        m_ui->recherche_s->setFocus();
        return;
    }

    bool isNumeric;
    valeur.toInt(&isNumeric);

    if (isNumeric && valeur.toInt() > 0 && !valeur.contains(" ") && !valeur.contains("-") && !valeur.contains("/")) {
        QSqlQueryModel *model = m_seance.rechercher("ID", valeur);

        m_ui->tab_s->setRowCount(0);
        m_ui->tab_s->setRowCount(model->rowCount());

        for (int i = 0; i < model->rowCount(); ++i) {
            for (int j = 0; j < 13; ++j) {
                QString data = model->data(model->index(i, j)).toString();
                m_ui->tab_s->setItem(i, j, new QTableWidgetItem(data));
            }
        }

        if (model->rowCount() == 0) {
            QMessageBox::information(nullptr, "Recherche par ID", "Aucune séance trouvée avec cet ID !");
        } else {
            QMessageBox::information(nullptr, "Recherche par ID", QString("%1 séance(s) trouvée(s) avec l'ID : %2").arg(model->rowCount()).arg(valeur));
        }

        delete model;
    } else {
        GereSeance::rechercherSeanceParType(m_ui, m_seance, valeur);
    }
}

void GestionSeanceUI::on_tri_s_currentIndexChanged(int index)
{
    QString critere;
    QString ordre = "ASC";

    switch(index) {
    case 1: critere = "DATE_S"; break;
    case 2: critere = "TYPE_S"; break;
    default: return;
    }

    QSqlQueryModel *model = m_seance.trier(critere, ordre);

    m_ui->tab_s->setRowCount(0);
    m_ui->tab_s->setRowCount(model->rowCount());

    for (int i = 0; i < model->rowCount(); ++i) {
        for (int j = 0; j < 13; ++j) {
            QString data = model->data(model->index(i, j)).toString();
            m_ui->tab_s->setItem(i, j, new QTableWidgetItem(data));
        }
    }

    delete model;
}

void GestionSeanceUI::on_exp_s_clicked()
{
    GereSeance::exporterSeanceExcel(m_ui);
}

void GestionSeanceUI::on_calendar_s_clicked(const QDate &date)
{
    afficherSeancesPourDate(date);
}

void GestionSeanceUI::on_calendar_s_selectionChanged()
{
    afficherSeancesPourDate(m_ui->calendar_s->selectedDate());
}

void GestionSeanceUI::on_mapType_s_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    mettreAJourCarte();
}
void GestionSeanceUI::on_centerMap_s_clicked()
{
    mettreAJourCarte();
    m_ui->label_routeStatus->setText("📍 Affichage actualisé\n🗺️ Coordonnées mises à jour");
}

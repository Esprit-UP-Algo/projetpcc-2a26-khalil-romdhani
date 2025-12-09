#include "StatCandidat.h"
#include <QGuiApplication>
#include <cmath>
#include <QAbstractItemModel>
#include <QLinearGradient>
#include <QRadialGradient>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

StatCandidat::StatCandidat(QWidget *parent)
    : QWidget(parent),
    m_animationProgress(0.0),
    m_animationEnabled(true),
    m_tempsReelEnabled(true),
    m_tableParent(nullptr)
{
    initialiserCouleurs();
    initialiserAnimations();
    initialiserTempsReel();

    setMinimumSize(500, 300);
    setMouseTracking(true);
}

StatCandidat::~StatCandidat()
{
    if (m_timerTempsReel) {
        m_timerTempsReel->stop();
        delete m_timerTempsReel;
    }
    if (m_timerMAJ) {
        m_timerMAJ->stop();
        delete m_timerMAJ;
    }
}

void StatCandidat::initialiserCouleurs()
{
    m_couleurA = QColor(74, 124, 255);
    m_couleurB = QColor(46, 204, 113);
    m_couleurC = QColor(255, 94, 87);
    m_couleurD = QColor(155, 89, 182);

    m_couleurFond = QColor(255, 255, 255);
    m_couleurTexte = QColor(33, 37, 41);
    m_couleurTitre = QColor(33, 37, 41);
    m_couleurSousTitre = QColor(108, 117, 125);
}

void StatCandidat::initialiserAnimations()
{
    m_animation = new QPropertyAnimation(this, "animationProgress");
    m_animation->setDuration(1500);
    m_animation->setEasingCurve(QEasingCurve::OutBack);
    m_animation->setStartValue(0.0);
    m_animation->setEndValue(1.0);

    connect(m_animation, &QPropertyAnimation::valueChanged,
            this, &StatCandidat::onAnimationValueChanged);
}

void StatCandidat::initialiserTempsReel()
{
    m_timerMAJ = new QTimer(this);
    m_timerMAJ->setInterval(3000);
    connect(m_timerMAJ, &QTimer::timeout, this, &StatCandidat::onTimerMAJ);

    m_timerTempsReel = new QTimer(this);
    m_timerTempsReel->setInterval(1000);
    connect(m_timerTempsReel, &QTimer::timeout, this, [this]() {
        update();
    });

    m_timerMAJ->start();
    m_timerTempsReel->start();
}

void StatCandidat::setTempsReelEnabled(bool enabled)
{
    m_tempsReelEnabled = enabled;
    if (enabled) {
        m_timerMAJ->start();
        m_timerTempsReel->start();
    } else {
        m_timerMAJ->stop();
        m_timerTempsReel->stop();
    }
    update();
}

void StatCandidat::setIntervalleMAJ(int milliseconds)
{
    m_timerMAJ->setInterval(milliseconds);
}

// 🔥 CORRECTION PRINCIPALE : Utiliser le paramètre table au lieu de l'ignorer
void StatCandidat::mettreAJourDonnees(QTableWidget *table)
{
    // SUPPRIMER: Q_UNUSED(table); - NE PAS IGNORER LE PARAMÈTRE

    DonneesPermis anciennesDonnees = m_donnees;

    // 🔥 CORRECTION : Utiliser le tableau fourni
    calculerDonneesFromTable(table);

    bool donneesChangees = (m_donnees.total != anciennesDonnees.total ||
                            m_donnees.countA != anciennesDonnees.countA ||
                            m_donnees.countB != anciennesDonnees.countB ||
                            m_donnees.countC != anciennesDonnees.countC ||
                            m_donnees.countD != anciennesDonnees.countD);

    if (donneesChangees) {
        m_donnees.derniereMAJ = QDateTime::currentDateTime();

        if (m_animationEnabled) {
            m_animation->start();
        } else {
            m_animationProgress = 1.0;
            update();
        }

        emit donneesMAJ(m_donnees);
    }

    update(); // FORCER le redessin
}

void StatCandidat::connecterSignauxTable(QTableWidget *table)
{
    if (!table) return;

    if (m_tableParent) {
        disconnect(m_tableParent->model(), nullptr, this, nullptr);
    }

    m_tableParent = table;

    connect(table->model(), &QAbstractItemModel::dataChanged,
            this, [this](const QModelIndex &topLeft, const QModelIndex &bottomRight) {
                Q_UNUSED(topLeft)
                Q_UNUSED(bottomRight)
                this->mettreAJourDonnees(m_tableParent);
            });

    connect(table->model(), &QAbstractItemModel::rowsInserted,
            this, [this](const QModelIndex &parent, int first, int last) {
                Q_UNUSED(parent)
                Q_UNUSED(first)
                Q_UNUSED(last)
                this->mettreAJourDonnees(m_tableParent);
            });

    connect(table->model(), &QAbstractItemModel::rowsRemoved,
            this, [this](const QModelIndex &parent, int first, int last) {
                Q_UNUSED(parent)
                Q_UNUSED(first)
                Q_UNUSED(last)
                this->mettreAJourDonnees(m_tableParent);
            });

    connect(table->model(), &QAbstractItemModel::modelReset,
            this, [this]() {
                this->mettreAJourDonnees(m_tableParent);
            });
}

void StatCandidat::onTimerMAJ()
{
    if (m_tableParent && m_tempsReelEnabled) {
        mettreAJourDonnees(m_tableParent);
    }
}

// 🔥 CORRECTION : Méthode qui utilise soit le tableau filtré soit la BDD complète
void StatCandidat::calculerDonneesFromTable(QTableWidget *table)
{
    DonneesPermis nouvellesDonnees;

    // Si un tableau est fourni et a des données, utiliser le tableau filtré
    if (table && table->rowCount() > 0) {
        qDebug() << "📊 Calcul des statistiques depuis le tableau filtré, lignes:" << table->rowCount();

        // Calculer depuis le tableau (données filtrées)
        nouvellesDonnees.countA = 0;
        nouvellesDonnees.countB = 0;
        nouvellesDonnees.countC = 0;
        nouvellesDonnees.countD = 0;

        for (int i = 0; i < table->rowCount(); ++i) {
            QTableWidgetItem* itemPermis = table->item(i, 7); // Colonne 7 = NV_PERMIS
            if (itemPermis) {
                QString permis = itemPermis->text().trimmed().toUpper();
                if (permis == "A") nouvellesDonnees.countA++;
                else if (permis == "B") nouvellesDonnees.countB++;
                else if (permis == "C") nouvellesDonnees.countC++;
                else if (permis == "D") nouvellesDonnees.countD++;
            }
        }

        nouvellesDonnees.total = table->rowCount();
        qDebug() << "📊 Statistiques tableau - A:" << nouvellesDonnees.countA
                 << "B:" << nouvellesDonnees.countB
                 << "C:" << nouvellesDonnees.countC
                 << "D:" << nouvellesDonnees.countD
                 << "Total:" << nouvellesDonnees.total;
    } else {
        // Sinon, utiliser la BDD (toutes les données)
        qDebug() << "📊 Calcul des statistiques depuis la BDD complète";

        QSqlQuery query("SELECT NV_PERMIS, COUNT(*) FROM CANDIDATS GROUP BY NV_PERMIS");

        // Réinitialiser les compteurs
        nouvellesDonnees.countA = 0;
        nouvellesDonnees.countB = 0;
        nouvellesDonnees.countC = 0;
        nouvellesDonnees.countD = 0;

        while (query.next()) {
            QString permis = query.value(0).toString().trimmed().toUpper();
            int count = query.value(1).toInt();

            if (permis == "A") nouvellesDonnees.countA = count;
            else if (permis == "B") nouvellesDonnees.countB = count;
            else if (permis == "C") nouvellesDonnees.countC = count;
            else if (permis == "D") nouvellesDonnees.countD = count;
        }

        // Compter le total directement en SQL
        QSqlQuery countQuery("SELECT COUNT(*) FROM CANDIDATS");
        if (countQuery.exec() && countQuery.next()) {
            nouvellesDonnees.total = countQuery.value(0).toInt();
        } else {
            nouvellesDonnees.total = 0;
            qDebug() << "❌ Erreur comptage total candidats:" << countQuery.lastError().text();
        }

        qDebug() << "📊 Statistiques BDD - A:" << nouvellesDonnees.countA
                 << "B:" << nouvellesDonnees.countB
                 << "C:" << nouvellesDonnees.countC
                 << "D:" << nouvellesDonnees.countD
                 << "Total:" << nouvellesDonnees.total;
    }

    // Calculer les pourcentages
    if (nouvellesDonnees.total > 0) {
        nouvellesDonnees.pourcentageA = (nouvellesDonnees.countA * 100.0) / nouvellesDonnees.total;
        nouvellesDonnees.pourcentageB = (nouvellesDonnees.countB * 100.0) / nouvellesDonnees.total;
        nouvellesDonnees.pourcentageC = (nouvellesDonnees.countC * 100.0) / nouvellesDonnees.total;
        nouvellesDonnees.pourcentageD = (nouvellesDonnees.countD * 100.0) / nouvellesDonnees.total;
    } else {
        nouvellesDonnees.pourcentageA = 0;
        nouvellesDonnees.pourcentageB = 0;
        nouvellesDonnees.pourcentageC = 0;
        nouvellesDonnees.pourcentageD = 0;
    }

    nouvellesDonnees.derniereMAJ = QDateTime::currentDateTime();
    m_donnees = nouvellesDonnees;
}

void StatCandidat::setAnimationProgress(double progress)
{
    m_animationProgress = progress;

    m_donneesAnimation.countA = static_cast<int>(m_donnees.countA * progress);
    m_donneesAnimation.countB = static_cast<int>(m_donnees.countB * progress);
    m_donneesAnimation.countC = static_cast<int>(m_donnees.countC * progress);
    m_donneesAnimation.countD = static_cast<int>(m_donnees.countD * progress);
    m_donneesAnimation.total = static_cast<int>(m_donnees.total * progress);

    if (m_donnees.total > 0) {
        m_donneesAnimation.pourcentageA = m_donnees.pourcentageA * progress;
        m_donneesAnimation.pourcentageB = m_donnees.pourcentageB * progress;
        m_donneesAnimation.pourcentageC = m_donnees.pourcentageC * progress;
        m_donneesAnimation.pourcentageD = m_donnees.pourcentageD * progress;
    }
}

void StatCandidat::onAnimationValueChanged()
{
    update();
}

void StatCandidat::setAnimationEnabled(bool enabled)
{
    m_animationEnabled = enabled;
    if (!enabled) {
        m_animation->stop();
        m_animationProgress = 1.0;
        update();
    }
}

void StatCandidat::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Fond blanc pur
    painter.fillRect(rect(), QColor(255, 255, 255));

    // Dimensions pour camembert à gauche et légendes à droite
    m_rayon = qMin(width() * 0.35, height() * 0.35);
    m_centre = QPointF(width() * 0.35, height() / 2.0);
    m_rectCamembert = QRectF(m_centre.x() - m_rayon, m_centre.y() - m_rayon,
                             m_rayon * 2, m_rayon * 2);

    // Dessin des éléments dans l'ordre
    dessinerTitre(painter);
    dessinerSeparateur(painter);
    dessinerCamembert(painter);
    dessinerCercleCentral(painter);
    dessinerLegende(painter);
}

void StatCandidat::dessinerTitre(QPainter &painter)
{
    painter.save();

    // Titre principal
    QFont titreFont("Arial", 14, QFont::Bold);
    painter.setFont(titreFont);
    painter.setPen(m_couleurTitre);

    QString titre = "Répartition des Permis";
    painter.drawText(QRect(0, 25, width(), 30), Qt::AlignCenter, titre);

    // Sous-titre
    QFont sousTitreFont("Arial", 9);
    painter.setFont(sousTitreFont);
    painter.setPen(m_couleurSousTitre);

    QString sousTitre = QString("Total: %1 candidats")
                            .arg(m_donnees.total);
    painter.drawText(QRect(0, 50, width(), 20), Qt::AlignCenter, sousTitre);

    painter.restore();
}

void StatCandidat::dessinerSeparateur(QPainter &painter)
{
    painter.save();

    // Séparateur
    painter.setPen(QPen(QColor(222, 226, 230), 1));
    int ySeparateur = 75;
    painter.drawLine(20, ySeparateur, width() - 20, ySeparateur);

    painter.restore();
}

void StatCandidat::dessinerCamembert(QPainter &painter)
{
    if (m_donneesAnimation.total == 0) {
        // Style sobre pour "Aucune donnée"
        painter.setBrush(QColor(248, 249, 250));
        painter.setPen(QPen(QColor(222, 226, 230), 2));
        painter.drawEllipse(m_rectCamembert);

        painter.setPen(QColor(173, 181, 189));
        QFont font("Arial", 10, QFont::Normal);
        font.setItalic(true);
        painter.setFont(font);
        painter.drawText(m_rectCamembert, Qt::AlignCenter, "Aucune donnée");
        return;
    }

    double startAngle = 90 * 16;

    // Permis A
    if (m_donneesAnimation.countA > 0) {
        double spanAngle = -m_donneesAnimation.pourcentageA * 360 * 16 / 100;
        painter.setBrush(m_couleurA);
        painter.setPen(QPen(m_couleurA.darker(130), 1.5));
        painter.drawPie(m_rectCamembert, startAngle, spanAngle);
        startAngle += spanAngle;
    }

    // Permis B
    if (m_donneesAnimation.countB > 0) {
        double spanAngle = -m_donneesAnimation.pourcentageB * 360 * 16 / 100;
        painter.setBrush(m_couleurB);
        painter.setPen(QPen(m_couleurB.darker(130), 1.5));
        painter.drawPie(m_rectCamembert, startAngle, spanAngle);
        startAngle += spanAngle;
    }

    // Permis C
    if (m_donneesAnimation.countC > 0) {
        double spanAngle = -m_donneesAnimation.pourcentageC * 360 * 16 / 100;
        painter.setBrush(m_couleurC);
        painter.setPen(QPen(m_couleurC.darker(130), 1.5));
        painter.drawPie(m_rectCamembert, startAngle, spanAngle);
        startAngle += spanAngle;
    }

    // Permis D
    if (m_donneesAnimation.countD > 0) {
        double spanAngle = -m_donneesAnimation.pourcentageD * 360 * 16 / 100;
        painter.setBrush(m_couleurD);
        painter.setPen(QPen(m_couleurD.darker(130), 1.5));
        painter.drawPie(m_rectCamembert, startAngle, spanAngle);
    }
}

void StatCandidat::dessinerCercleCentral(QPainter &painter)
{
    double rayonCentral = m_rayon * 0.55;

    // Cercle central blanc
    painter.setBrush(QColor(255, 255, 255));
    painter.setPen(QPen(QColor(222, 226, 230), 1));
    painter.drawEllipse(m_centre, rayonCentral, rayonCentral);

    // Texte central
    painter.setPen(m_couleurTitre);

    // Chiffre principal en gras
    QFont chiffreFont("Arial", 16, QFont::Bold);
    painter.setFont(chiffreFont);

    painter.drawText(QRectF(m_centre.x() - rayonCentral, m_centre.y() - rayonCentral - 5,
                            rayonCentral * 2, rayonCentral * 2),
                     Qt::AlignCenter, QString::number(m_donneesAnimation.total));

    // Label "Candidats" en plus petit
    QFont labelFont("Arial", 9);
    painter.setFont(labelFont);
    painter.setPen(m_couleurSousTitre);

    painter.drawText(QRectF(m_centre.x() - rayonCentral, m_centre.y() - rayonCentral + 15,
                            rayonCentral * 2, rayonCentral * 2),
                     Qt::AlignCenter, "Candidats");
}

void StatCandidat::dessinerLegende(QPainter &painter)
{
    painter.save();

    QFont font("Arial", 9);
    QFont titreFont("Arial", 10, QFont::Bold);
    painter.setFont(font);

    // Position de départ pour les légendes à droite
    double startX = width() * 0.65;
    double startY = height() * 0.35;
    double espacementVertical = 35;

    // Légende A
    QRectF rectA(startX, startY, 12, 12);
    painter.setBrush(m_couleurA);
    painter.setPen(QPen(m_couleurA.darker(130), 1));
    painter.drawRoundedRect(rectA, 2, 2);

    painter.setPen(m_couleurTexte);
    painter.setFont(titreFont);
    painter.drawText(QRectF(startX + 20, startY - 8, 100, 20), Qt::AlignLeft, "A");

    painter.setFont(font);
    QString texteA = QString("%1 candidats (%2 %)")
                         .arg(m_donneesAnimation.countA)
                         .arg(m_donneesAnimation.pourcentageA, 0, 'f', 1);
    painter.drawText(QRectF(startX + 20, startY + 5, 150, 20), Qt::AlignLeft, texteA);

    // Légende B
    QRectF rectB(startX, startY + espacementVertical, 12, 12);
    painter.setBrush(m_couleurB);
    painter.setPen(QPen(m_couleurB.darker(130), 1));
    painter.drawRoundedRect(rectB, 2, 2);

    painter.setPen(m_couleurTexte);
    painter.setFont(titreFont);
    painter.drawText(QRectF(startX + 20, startY + espacementVertical - 8, 100, 20), Qt::AlignLeft, "B");

    painter.setFont(font);
    QString texteB = QString("%1 candidats (%2 %)")
                         .arg(m_donneesAnimation.countB)
                         .arg(m_donneesAnimation.pourcentageB, 0, 'f', 1);
    painter.drawText(QRectF(startX + 20, startY + espacementVertical + 5, 150, 20), Qt::AlignLeft, texteB);

    // Légende C
    QRectF rectC(startX, startY + espacementVertical * 2, 12, 12);
    painter.setBrush(m_couleurC);
    painter.setPen(QPen(m_couleurC.darker(130), 1));
    painter.drawRoundedRect(rectC, 2, 2);

    painter.setPen(m_couleurTexte);
    painter.setFont(titreFont);
    painter.drawText(QRectF(startX + 20, startY + espacementVertical * 2 - 8, 100, 20), Qt::AlignLeft, "C");

    painter.setFont(font);
    QString texteC = QString("%1 candidats (%2 %)")
                         .arg(m_donneesAnimation.countC)
                         .arg(m_donneesAnimation.pourcentageC, 0, 'f', 1);
    painter.drawText(QRectF(startX + 20, startY + espacementVertical * 2 + 5, 150, 20), Qt::AlignLeft, texteC);

    // Légende D
    QRectF rectD(startX, startY + espacementVertical * 3, 12, 12);
    painter.setBrush(m_couleurD);
    painter.setPen(QPen(m_couleurD.darker(130), 1));
    painter.drawRoundedRect(rectD, 2, 2);

    painter.setPen(m_couleurTexte);
    painter.setFont(titreFont);
    painter.drawText(QRectF(startX + 20, startY + espacementVertical * 3 - 8, 100, 20), Qt::AlignLeft, "D");

    painter.setFont(font);
    QString texteD = QString("%1 candidats (%2 %)")
                         .arg(m_donneesAnimation.countD)
                         .arg(m_donneesAnimation.pourcentageD, 0, 'f', 1);
    painter.drawText(QRectF(startX + 20, startY + espacementVertical * 3 + 5, 150, 20), Qt::AlignLeft, texteD);

    painter.restore();
}

void StatCandidat::mouseMoveEvent(QMouseEvent *event)
{
    QString tooltip = obtenirTooltip(event->pos());
    if (!tooltip.isEmpty()) {
        QToolTip::showText(event->globalPos(), tooltip, this);
    } else {
        QToolTip::hideText();
    }

    QWidget::mouseMoveEvent(event);
}

QString StatCandidat::obtenirTooltip(const QPoint &pos)
{
    if (m_donneesAnimation.total == 0) {
        return "Aucune donnée disponible";
    }

    QPointF relativePos = pos - m_centre;
    double distance = std::sqrt(relativePos.x() * relativePos.x() + relativePos.y() * relativePos.y());

    if (distance > m_rayon * 1.1 || distance < m_rayon * 0.4) {
        return QString("Répartition des Permis\nTotal: %1 candidats")
            .arg(m_donnees.total);
    }

    double angle = std::atan2(-relativePos.y(), relativePos.x()) * 180 / M_PI;
    if (angle < 0) angle += 360;

    double camembertAngle = std::fmod(angle + 90, 360);
    double cumulative = 0;

    if (camembertAngle < m_donneesAnimation.pourcentageA * 3.6 && m_donneesAnimation.countA > 0) {
        return QString("Permis A\n%1 candidats (%2 %)")
        .arg(m_donnees.countA)
            .arg(m_donnees.pourcentageA, 0, 'f', 1);
    }
    cumulative += m_donneesAnimation.pourcentageA;

    if (camembertAngle < cumulative * 3.6 && m_donneesAnimation.countB > 0) {
        return QString("Permis B\n%1 candidats (%2 %)")
        .arg(m_donnees.countB)
            .arg(m_donnees.pourcentageB, 0, 'f', 1);
    }
    cumulative += m_donneesAnimation.pourcentageB;

    if (camembertAngle < cumulative * 3.6 && m_donneesAnimation.countC > 0) {
        return QString("Permis C\n%1 candidats (%2 %)")
        .arg(m_donnees.countC)
            .arg(m_donnees.pourcentageC, 0, 'f', 1);
    }
    cumulative += m_donneesAnimation.pourcentageC;

    if (camembertAngle < cumulative * 3.6 && m_donneesAnimation.countD > 0) {
        return QString("Permis D\n%1 candidats (%2 %)")
        .arg(m_donnees.countD)
            .arg(m_donnees.pourcentageD, 0, 'f', 1);
    }

    return QString();
}

void StatCandidat::resizeEvent(QResizeEvent *event)
{
    update();
    QWidget::resizeEvent(event);
}

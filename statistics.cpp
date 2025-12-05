#include "statistics.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include <QTime>
#include <QSet>
#include <QStandardItemModel>

Statistics::Statistics(QObject *parent) : QObject(parent)
{
}

int Statistics::getTotalSeances()
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM SEANCES");

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    qDebug() << "❌ Erreur getTotalSeances:" << query.lastError().text();
    return 0;
}

double Statistics::getHeuresTotales()
{
    QSqlQuery query;
    query.prepare("SELECT HEURE_DEBUT_S, HEURE_FIN_S FROM SEANCES");

    double totalHeures = 0.0;
    int seancesAvecErreur = 0;

    if (query.exec()) {
        while (query.next()) {
            QString debut = query.value(0).toString();
            QString fin = query.value(1).toString();

            double duree = calculerDureeSeance(debut, fin);
            if (duree > 0) {
                totalHeures += duree;
                qDebug() << "⏱️ Séance:" << debut << "-" << fin << "=" << duree << "h";
            } else {
                seancesAvecErreur++;
            }
        }

        if (seancesAvecErreur > 0) {
            qDebug() << "⚠️" << seancesAvecErreur << "séances avec des heures invalides";
        }
    } else {
        qDebug() << "❌ Erreur getHeuresTotales:" << query.lastError().text();
    }

    qDebug() << "✅ Heures totales calculées:" << totalHeures << "h";
    return totalHeures;
}

QSqlQueryModel* Statistics::getTableauStatsParType()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // REQUÊTE qui calcule directement les heures dans SQL
    QString queryStr =
        "SELECT "
        "  NVL(TYPE_S, 'Non spécifié') as Type, "
        "  COUNT(ID_SEANCE) as Nb_Seances, "
        "  ROUND(SUM(("
        "    (TO_NUMBER(SUBSTR(HEURE_FIN_S, 1, 2)) + TO_NUMBER(SUBSTR(HEURE_FIN_S, 4, 2)) / 60.0) - "
        "    (TO_NUMBER(SUBSTR(HEURE_DEBUT_S, 1, 2)) + TO_NUMBER(SUBSTR(HEURE_DEBUT_S, 4, 2)) / 60.0)"
        "  )), 1) || 'h' as Heures_Totales, "
        "  LISTAGG(DISTINCT 'Moniteur ' || ID_MONITEUR, ', ') WITHIN GROUP (ORDER BY ID_MONITEUR) as Moniteurs "
        "FROM SEANCES "
        "WHERE HEURE_DEBUT_S IS NOT NULL AND HEURE_FIN_S IS NOT NULL "
        "GROUP BY NVL(TYPE_S, 'Non spécifié') "
        "ORDER BY COUNT(ID_SEANCE) DESC";

    qDebug() << "📊 Exécution requête SQL avec calcul d'heures...";
    model->setQuery(queryStr);

    if (model->lastError().isValid()) {
        qDebug() << "❌ Erreur requête avec calcul d'heures:" << model->lastError().text();

        // Fallback: sans calcul d'heures complexe
        QString querySimple =
            "SELECT "
            "  NVL(TYPE_S, 'Non spécifié') as Type, "
            "  COUNT(ID_SEANCE) as Nb_Seances, "
            "  'Calcul en cours...' as Heures_Totales, "
            "  LISTAGG(DISTINCT 'Moniteur ' || ID_MONITEUR, ', ') WITHIN GROUP (ORDER BY ID_MONITEUR) as Moniteurs "
            "FROM SEANCES "
            "GROUP BY NVL(TYPE_S, 'Non spécifié') "
            "ORDER BY COUNT(ID_SEANCE) DESC";

        qDebug() << "🔄 Tentative avec requête simple...";
        model->setQuery(querySimple);
    }

    // Si toujours erreur, utiliser le fallback manuel
    if (model->lastError().isValid()) {
        qDebug() << "🔄 Utilisation du calcul manuel fallback";
        delete model;
        return getTableauStatsParTypeFallback();
    }

    if (!model->lastError().isValid()) {
        qDebug() << "✅ Requête exécutée avec succès, lignes:" << model->rowCount();

        // Si on a utilisé la requête simple sans calcul d'heures, calculer manuellement
        if (model->rowCount() > 0) {
            QString premierHeures = model->data(model->index(0, 2)).toString();
            if (premierHeures == "Calcul en cours..." || premierHeures.contains("Calcul")) {
                calculerEtMettreAJourHeuresTotales(model);
            }
        }
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nb séances"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Heures totales"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Moniteurs"));

    return model;
}

void Statistics::calculerEtMettreAJourHeuresTotales(QSqlQueryModel* model)
{
    qDebug() << "🔄 Calcul manuel des heures pour chaque type...";

    // Pour chaque type de séance, calculer les heures totales
    for (int row = 0; row < model->rowCount(); ++row) {
        QString type = model->data(model->index(row, 0)).toString();

        // Préparer la condition WHERE selon le type
        QString condition;
        if (type == "Non spécifié") {
            condition = "TYPE_S IS NULL OR TYPE_S = ''";
        } else {
            condition = "TYPE_S = :type";
        }

        // Calculer les heures totales pour ce type
        QSqlQuery query;
        query.prepare("SELECT HEURE_DEBUT_S, HEURE_FIN_S FROM SEANCES WHERE " + condition);
        if (type != "Non spécifié") {
            query.bindValue(":type", type);
        }

        double heuresTotalesType = 0.0;
        int seancesCalculees = 0;

        if (query.exec()) {
            while (query.next()) {
                QString debut = query.value(0).toString();
                QString fin = query.value(1).toString();

                double duree = calculerDureeSeance(debut, fin);
                heuresTotalesType += duree;
                seancesCalculees++;
            }

            // Mettre à jour l'affichage des heures
            QString heuresText = QString::number(heuresTotalesType, 'f', 1) + "h";
            model->setData(model->index(row, 2), heuresText);

            qDebug() << "   Type:" << type << "| Séances:" << seancesCalculees << "| Heures:" << heuresText;
        } else {
            qDebug() << "❌ Erreur calcul heures pour type" << type << ":" << query.lastError().text();
        }
    }

    qDebug() << "✅ Calcul manuel des heures terminé";
}

QSqlQueryModel* Statistics::getTableauStatsParTypeFallback()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // Créer une structure de modèle avec les bonnes colonnes
    QString queryStructure =
        "SELECT "
        "  'Calcul manuel' as Type, "
        "  0 as Nb_Seances, "
        "  '0h' as Heures_Totales, "
        "  'Moniteurs' as Moniteurs "
        "FROM DUAL "
        "WHERE 1=0";  // Aucune ligne

    model->setQuery(queryStructure);

    // Récupérer tous les types de séances
    QSqlQuery queryTypes;
    queryTypes.prepare("SELECT DISTINCT NVL(TYPE_S, 'Non spécifié') as type FROM SEANCES ORDER BY type");

    if (queryTypes.exec()) {
        QMap<QString, int> nbSeances;
        QMap<QString, double> heuresTotales;
        QMap<QString, QSet<QString>> moniteursParType;

        // Compter les séances par type
        QSqlQuery queryCount;
        queryCount.prepare("SELECT NVL(TYPE_S, 'Non spécifié'), COUNT(*) FROM SEANCES GROUP BY NVL(TYPE_S, 'Non spécifié')");

        if (queryCount.exec()) {
            while (queryCount.next()) {
                QString type = queryCount.value(0).toString();
                nbSeances[type] = queryCount.value(1).toInt();
            }
        }

        // Calculer les heures et récupérer les moniteurs pour chaque type
        for (auto it = nbSeances.begin(); it != nbSeances.end(); ++it) {
            QString type = it.key();
            QString condition;

            if (type == "Non spécifié") {
                condition = "TYPE_S IS NULL OR TYPE_S = ''";
            } else {
                condition = "TYPE_S = :type";
            }

            QSqlQuery queryDetails;
            queryDetails.prepare("SELECT HEURE_DEBUT_S, HEURE_FIN_S, ID_MONITEUR FROM SEANCES WHERE " + condition);
            if (type != "Non spécifié") {
                queryDetails.bindValue(":type", type);
            }

            if (queryDetails.exec()) {
                while (queryDetails.next()) {
                    QString debut = queryDetails.value(0).toString();
                    QString fin = queryDetails.value(1).toString();
                    QString moniteur = queryDetails.value(2).toString();

                    heuresTotales[type] += calculerDureeSeance(debut, fin);
                    moniteursParType[type].insert("Moniteur " + moniteur);
                }
            }
        }

        // Créer un modèle avec les vraies données
        if (!nbSeances.isEmpty()) {
            // Pour retourner un QSqlQueryModel valide, on crée une requête avec les données
            QStringList values;
            for (auto it = nbSeances.begin(); it != nbSeances.end(); ++it) {
                QString type = it.key();
                int count = it.value();
                double heures = heuresTotales[type];
                QStringList moniteursList = moniteursParType[type].values();
                moniteursList.sort();
                QString moniteursStr = moniteursList.join(", ");
                if (moniteursStr.isEmpty()) moniteursStr = "Aucun moniteur";

                values << QString("SELECT '%1' as Type, %2 as Nb_Seances, '%3h' as Heures_Totales, '%4' as Moniteurs FROM DUAL")
                              .arg(type).arg(count).arg(heures, 0, 'f', 1).arg(moniteursStr);
            }

            QString unionQuery = values.join(" UNION ALL ");
            unionQuery += " ORDER BY Nb_Seances DESC";

            model->setQuery(unionQuery);

            if (!model->lastError().isValid()) {
                qDebug() << "✅ Fallback réussi:" << nbSeances.size() << "types calculés manuellement";
            }
        }
    }

    return model;
}

double Statistics::calculerDureeSeance(const QString& debut, const QString& fin)
{
    if (debut.isEmpty() || fin.isEmpty()) {
        qDebug() << "⚠️ Heure début ou fin vide";
        return 0.0;
    }

    // Nettoyer les chaînes
    QString cleanDebut = debut.trimmed();
    QString cleanFin = fin.trimmed();

    qDebug() << "🔍 Calcul durée:" << cleanDebut << "->" << cleanFin;

    // Essayer différents formats
    QTime timeDebut = QTime::fromString(cleanDebut, "hh:mm");
    if (!timeDebut.isValid()) {
        timeDebut = QTime::fromString(cleanDebut, "h:mm");
    }
    if (!timeDebut.isValid()) {
        timeDebut = QTime::fromString(cleanDebut, "hh:mm:ss");
    }

    QTime timeFin = QTime::fromString(cleanFin, "hh:mm");
    if (!timeFin.isValid()) {
        timeFin = QTime::fromString(cleanFin, "h:mm");
    }
    if (!timeFin.isValid()) {
        timeFin = QTime::fromString(cleanFin, "hh:mm:ss");
    }

    if (!timeDebut.isValid() || !timeFin.isValid()) {
        qDebug() << "❌ Format d'heure invalide - Début:" << debut << "Fin:" << fin;
        qDebug() << "   Clean Début:" << cleanDebut << "Clean Fin:" << cleanFin;
        return 1.0; // Valeur par défaut
    }

    // Calculer la durée
    int debutSecs = timeDebut.hour() * 3600 + timeDebut.minute() * 60 + timeDebut.second();
    int finSecs = timeFin.hour() * 3600 + timeFin.minute() * 60 + timeFin.second();

    int dureeSecs = finSecs - debutSecs;

    // Gérer le cas où la séance passe minuit
    if (dureeSecs < 0) {
        dureeSecs += 24 * 3600; // Ajouter 24 heures
    }

    double dureeHeures = dureeSecs / 3600.0;

    qDebug() << "   Durée calculée:" << timeDebut.toString("hh:mm:ss") << "->"
             << timeFin.toString("hh:mm:ss") << "=" << dureeHeures << "h";

    // Validation
    if (dureeHeures <= 0) {
        qDebug() << "⚠️ Durée négative, utilisation de 1h par défaut";
        return 1.0;
    }

    if (dureeHeures > 24) {
        qDebug() << "⚠️ Durée trop longue (>24h), utilisation de 1h par défaut";
        return 1.0;
    }

    return dureeHeures;
}

// Les autres méthodes restent inchangées...
QMap<QString, int> Statistics::getSeancesParType()
{
    QMap<QString, int> stats;

    QSqlQuery query;
    query.prepare("SELECT NVL(TYPE_S, 'Non spécifié'), COUNT(*) FROM SEANCES GROUP BY NVL(TYPE_S, 'Non spécifié')");

    if (query.exec()) {
        while (query.next()) {
            stats[query.value(0).toString()] = query.value(1).toInt();
        }
    } else {
        qDebug() << "❌ Erreur getSeancesParType:" << query.lastError().text();
    }

    return stats;
}

QMap<QString, int> Statistics::getSeancesParMois()
{
    QMap<QString, int> stats;

    QSqlQuery query;
    query.prepare("SELECT TO_CHAR(DATE_S, 'YYYY-MM'), COUNT(*) FROM SEANCES "
                  "GROUP BY TO_CHAR(DATE_S, 'YYYY-MM') "
                  "ORDER BY TO_CHAR(DATE_S, 'YYYY-MM')");

    if (query.exec()) {
        while (query.next()) {
            QString mois = query.value(0).toString();
            stats[mois] = query.value(1).toInt();
        }
    } else {
        qDebug() << "❌ Erreur getSeancesParMois:" << query.lastError().text();
    }

    return stats;
}

QMap<QString, int> Statistics::getSeancesParMoniteur()
{
    QMap<QString, int> stats;

    QSqlQuery query;
    query.prepare("SELECT ID_MONITEUR, COUNT(*) FROM SEANCES GROUP BY ID_MONITEUR");

    if (query.exec()) {
        while (query.next()) {
            QString moniteur = "Moniteur " + query.value(0).toString();
            stats[moniteur] = query.value(1).toInt();
        }
    } else {
        qDebug() << "❌ Erreur getSeancesParMoniteur:" << query.lastError().text();
    }

    return stats;
}

QVector<QPair<QString, int>> Statistics::getTopMoniteurs(int limit)
{
    QVector<QPair<QString, int>> top;

    QSqlQuery query;
    query.prepare("SELECT ID_MONITEUR, COUNT(*) as nb_seances "
                  "FROM SEANCES GROUP BY ID_MONITEUR "
                  "ORDER BY nb_seances DESC");

    if (query.exec()) {
        int count = 0;
        while (query.next() && count < limit) {
            QString moniteur = "Moniteur " + query.value(0).toString();
            int nbSeances = query.value(1).toInt();
            top.append(qMakePair(moniteur, nbSeances));
            count++;
        }
    } else {
        qDebug() << "❌ Erreur getTopMoniteurs:" << query.lastError().text();
    }

    return top;
}

double Statistics::getMoyenneHeuresParSeance()
{
    int totalSeances = getTotalSeances();
    if (totalSeances == 0) return 0.0;

    double totalHeures = getHeuresTotales();
    return totalHeures / totalSeances;
}

int Statistics::getSeancesCeMois()
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM SEANCES "
                  "WHERE EXTRACT(MONTH FROM DATE_S) = EXTRACT(MONTH FROM SYSDATE) "
                  "AND EXTRACT(YEAR FROM DATE_S) = EXTRACT(YEAR FROM SYSDATE)");

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    qDebug() << "❌ Erreur getSeancesCeMois:" << query.lastError().text();
    return 0;
}

int Statistics::getSeancesCetteSemaine()
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM SEANCES "
                  "WHERE DATE_S >= TRUNC(SYSDATE, 'IW')");

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    qDebug() << "❌ Erreur getSeancesCetteSemaine:" << query.lastError().text();
    return 0;
}

double Statistics::convertirHeuresEnDecimal(const QString& heure)
{
    return calculerDureeSeance("00:00", heure);
}

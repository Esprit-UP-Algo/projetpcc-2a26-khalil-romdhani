#include "JournalCandidat.h"
#include <QDir>

JournalCandidat::JournalCandidat(QObject *parent)
    : QObject(parent), m_listWidget(nullptr)
{
}

JournalCandidat::~JournalCandidat()
{
    if (m_fichierLog.isOpen()) {
        m_fichierLog.close();
    }
}

void JournalCandidat::setListWidget(QListWidget *listWidget)
{
    m_listWidget = listWidget;
}

QString JournalCandidat::getCheminFichierLog() const
{
    return QApplication::applicationDirPath() + "/journal_candidats.log";
}

void JournalCandidat::ajouterEntree(const QString &action, int idCandidat, const QString &nomCandidat)
{
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString message = QString("[%1] %2 - Candidat #%3 (%4)")
                          .arg(timestamp, action, QString::number(idCandidat), nomCandidat);

    // Ajouter à la liste widget
    if (m_listWidget) {
        m_listWidget->insertItem(0, message);

        // Limiter à 50 entrées maximum
        if (m_listWidget->count() > 50) {
            QListWidgetItem *item = m_listWidget->item(50);
            if (item) {
                delete item;
            }
        }
    }

    // Sauvegarder dans le fichier
    sauvegarderEntree(message);
}

void JournalCandidat::sauvegarderEntree(const QString &message)
{
    m_fichierLog.setFileName(getCheminFichierLog());

    if (m_fichierLog.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&m_fichierLog);
        stream.setEncoding(QStringConverter::Utf8);
        stream << message << "\n";
        m_fichierLog.close();
    }
}

void JournalCandidat::chargerHistorique()
{
    if (!m_listWidget) return;

    m_listWidget->clear();

    m_fichierLog.setFileName(getCheminFichierLog());
    if (m_fichierLog.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&m_fichierLog);
        stream.setEncoding(QStringConverter::Utf8);

        QStringList historique;
        while (!stream.atEnd()) {
            QString ligne = stream.readLine();
            if (!ligne.isEmpty()) {
                historique.prepend(ligne);
            }
        }

        // Limiter aux 50 dernières entrées
        int start = qMax(0, historique.size() - 50);
        for (int i = start; i < historique.size(); ++i) {
            m_listWidget->addItem(historique[i]);
        }

        m_fichierLog.close();
    }
}

void JournalCandidat::viderJournal()
{
    if (m_listWidget) {
        m_listWidget->clear();
    }

    // Vider le fichier log
    m_fichierLog.setFileName(getCheminFichierLog());
    if (m_fichierLog.open(QIODevice::WriteOnly | QIODevice::Text)) {
        m_fichierLog.resize(0);
        m_fichierLog.close();
    }
}

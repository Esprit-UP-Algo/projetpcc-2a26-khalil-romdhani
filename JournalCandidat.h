#ifndef JOURNALCANDIDAT_H
#define JOURNALCANDIDAT_H

#include <QObject>
#include <QListWidget>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QApplication>

class JournalCandidat : public QObject
{
    Q_OBJECT

public:
    explicit JournalCandidat(QObject *parent = nullptr);
    ~JournalCandidat();

    void setListWidget(QListWidget *listWidget);
    void ajouterEntree(const QString &action, int idCandidat, const QString &nomCandidat);
    void chargerHistorique();
    void viderJournal();

private:
    QListWidget *m_listWidget;
    QFile m_fichierLog;
    QString getCheminFichierLog() const;
    void sauvegarderEntree(const QString &message);
};

#endif // JOURNALCANDIDAT_H

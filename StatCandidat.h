#ifndef STATCANDIDAT_H
#define STATCANDIDAT_H

#include <QWidget>
#include <QTableWidget>
#include <QPainter>
#include <QPropertyAnimation>
#include <QTimer>
#include <QMouseEvent>
#include <QToolTip>
#include <QDateTime>
#include <QLinearGradient>

class StatCandidat : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(double animationProgress READ getAnimationProgress WRITE setAnimationProgress)

public:
    struct DonneesPermis {
        int countA;
        int countB;
        int countC;
        int countD;
        int total;
        double pourcentageA;
        double pourcentageB;
        double pourcentageC;
        double pourcentageD;
        QDateTime derniereMAJ;

        DonneesPermis() : countA(0), countB(0), countC(0), countD(0), total(0),
            pourcentageA(0), pourcentageB(0), pourcentageC(0), pourcentageD(0) {}
    };

    explicit StatCandidat(QWidget *parent = nullptr);
    ~StatCandidat();

    void mettreAJourDonnees(QTableWidget *table);
    void setAnimationEnabled(bool enabled);
    void setTempsReelEnabled(bool enabled);
    void setIntervalleMAJ(int milliseconds);

    DonneesPermis getDonnees() const { return m_donnees; }

signals:
    void donneesMAJ(const DonneesPermis &donnees);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onAnimationValueChanged();
    void onTimerMAJ();

private:
    DonneesPermis m_donnees;
    DonneesPermis m_donneesAnimation;
    double m_animationProgress;
    QPropertyAnimation *m_animation;
    QTimer *m_timerMAJ;
    QTimer *m_timerTempsReel;
    bool m_animationEnabled;
    bool m_tempsReelEnabled;
    QTableWidget *m_tableParent;

    QColor m_couleurA;
    QColor m_couleurB;
    QColor m_couleurC;
    QColor m_couleurD;
    QColor m_couleurFond;
    QColor m_couleurTexte;
    QColor m_couleurTitre;
    QColor m_couleurSousTitre;

    QRectF m_rectCamembert;
    double m_rayon;
    QPointF m_centre;

    double getAnimationProgress() const { return m_animationProgress; }
    void setAnimationProgress(double progress);
    void calculerDonneesFromTable(QTableWidget *table);
    void dessinerCamembert(QPainter &painter);
    void dessinerLegende(QPainter &painter);
    void dessinerCercleCentral(QPainter &painter);
    void dessinerTitre(QPainter &painter);
    void dessinerSeparateur(QPainter &painter); // AJOUTÉ
    QString obtenirTooltip(const QPoint &pos);
    void initialiserCouleurs();
    void initialiserAnimations();
    void initialiserTempsReel();
    void connecterSignauxTable(QTableWidget *table);
};

#endif // STATCANDIDAT_H

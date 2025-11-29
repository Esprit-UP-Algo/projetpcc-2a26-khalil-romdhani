#ifndef GROQ_MANAGER_H
#define GROQ_MANAGER_H

#include <QObject>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

class GroqPredictor;

class GroqManager : public QObject
{
    Q_OBJECT
public:
    explicit GroqManager(QObject *parent = nullptr);
    void setupUI(QLineEdit* matriculeInput, QTextEdit* resultOutput,
                 QPushButton* predictButton, QPushButton* clearButton);
private slots:
    void onPredictClicked();
    void onClearClicked();
    void onPredictionReady(const QString& result);
    void onPredictionError(const QString& error);
private:
    QLineEdit* m_matriculeInput;
    QTextEdit* m_resultOutput;
    GroqPredictor* m_predictor;
};

#endif

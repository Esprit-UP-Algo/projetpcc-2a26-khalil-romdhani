#include "chatbot.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QRegularExpression>
#include <QDebug>
#include <QTimer>

static const QString API_KEY = "Sx77QnhwffNohEkrJQldxKo3BhIncGcf";

ChatBot::ChatBot(QObject *parent)
    : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    timeoutTimer = new QTimer(this);
    timeoutTimer->setSingleShot(true);

    connect(timeoutTimer, &QTimer::timeout, this, [this]() {
        qDebug() << "⏰ Timeout de l'API";
        emit errorOccured("Délai d'attente dépassé - Veuillez réessayer");
    });
}

void ChatBot::setDatabase(const QSqlDatabase &db)
{
    m_db = db;
}

void ChatBot::ask(const QString &message)
{
    QString sql = detectSql(message);
    QString sqlResult;

    // ✅ DÉTECTION DES QUESTIONS GÉNÉRALES
    bool isGeneralQuestion = isGeneralKnowledgeQuestion(message);

    if (!sql.isEmpty()) {
        sqlResult = execSql(sql);
        qDebug() << "📊 Résultat SQL:" << sqlResult;
    }

    QString finalPrompt = buildPrompt(message, sqlResult, isGeneralQuestion);
    qDebug() << "📝 Prompt final:" << finalPrompt;

    // API Mistral
    QUrl url("https://api.mistral.ai/v1/chat/completions");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg(API_KEY).toUtf8());

    request.setAttribute(QNetworkRequest::Http2AllowedAttribute, true);
    request.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::AlwaysNetwork);

    QJsonObject sys;
    sys["role"] = "system";
    sys["content"] =
        "Tu es un assistant spécialisé dans l'auto-école Smart Drive. "

        "**POUR LES DONNÉES SPÉCIFIQUES** (candidats, moniteurs, véhicules, employés, séances) : "
        "Utilise UNIQUEMENT les données SQL fournies. Sois précis avec les chiffres et noms."

        "**POUR LES QUESTIONS GÉNÉRALES** : "
        "Tu as des connaissances étendues sur : "
        "- Le permis de conduire (toutes catégories A, B, C, D, E) "
        "- Les réglementations en Tunisie "
        "- Les procédures d'inscription, examens théoriques et pratiques "
        "- Les conditions d'âge, médicales, et administratives "
        "- Les durées de formation, forfaits, coûts "
        "- Les techniques de conduite et conseils pédagogiques "
        "- Les statistiques de réussite et difficultés "
        "- La sécurité routière et conditions météo "

        "Pour les questions générales, réponds de façon naturelle, utile et précise "
        "en t'appuyant sur tes connaissances des auto-écoles et du permis de conduire. "
        "Sois toujours courtois, professionnel et adapte ta réponse au pays concerné.";
    QJsonObject usr;
    usr["role"] = "user";
    usr["content"] = finalPrompt;

    QJsonArray msgs;
    msgs.append(sys);
    msgs.append(usr);

    QJsonObject body;
    body["model"] = "mistral-small-latest";
    body["messages"] = msgs;
    body["max_tokens"] = 300;
    body["temperature"] = 0.7;

    QJsonDocument jsonDoc(body);
    QByteArray jsonData = jsonDoc.toJson();

    qDebug() << "🌐 Envoi requête API...";

    timeoutTimer->start(15000);

    QNetworkReply *reply = manager->post(request, jsonData);

    disconnect(manager, &QNetworkAccessManager::finished, 0, 0);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        timeoutTimer->stop();
        onFinished(reply);
    });
}

// ✅ NOUVELLE FONCTION : Détection des questions générales
bool ChatBot::isGeneralKnowledgeQuestion(const QString &question) const
{
    QString s = question.toLower().trimmed();
    s.remove(QRegularExpression("[.,!?;]")); // Nettoyage de la ponctuation

    // ==========================================================================
    // 1. QUESTIONS SUR L'IDENTITÉ ET FONCTIONNALITÉS DU CHATBOT
    // ==========================================================================
    if ((s.contains("qui est") && (s.contains("tu") || s.contains("vous"))) ||
        (s.contains("qu'est") && (s.contains("tu") || s.contains("vous"))) ||
        s.contains("ton nom") || s.contains("votre nom") ||
        s.contains("tu t'appelle") || s.contains("vous appelez") ||
        s.contains("présente toi") || s.contains("presente toi") ||
        s.contains("qui es-tu") || s.contains("qui êtes-vous")) {
        return true;
    }

    // ==========================================================================
    // 2. QUESTIONS SUR SMART DRIVE (GÉNÉRALES)
    // ==========================================================================
    if ((s.contains("smart drive") || s.contains("smartdrive") ||
         s.contains("auto[ -]?école") || s.contains("ecole de conduite")) &&
        !s.contains("candidat") && !s.contains("moniteur") &&
        !s.contains("véhicule") && !s.contains("vehicule") &&
        !s.contains("employé") && !s.contains("employe")) {
        return true;
    }

    // ==========================================================================
    // 3. SALUTATIONS ET FORMULES DE POLITESSE
    // ==========================================================================
    if (s == "bonjour" || s == "salut" || s == "hello" || s == "hi" ||
        s == "coucou" || s == "bjr" || s == "slt" ||
        s.contains("bonsoir") || s.contains("good morning") || s.contains("good evening") ||
        s.contains("ça va") || s.contains("ca va") || s.contains("comment ça va") ||
        s.contains("comment vas-tu") || s.contains("comment allez-vous") ||
        s.contains("bienvenue") || s.contains("welcome")) {
        return true;
    }

    // ==========================================================================
    // 4. QUESTIONS D'AIDE ET FONCTIONNALITÉS
    // ==========================================================================
    if (s.contains("aide") || s.contains("help") ||
        s.contains("que puis") || s.contains("que peux") ||
        s.contains("tu peux faire") || s.contains("vous pouvez faire") ||
        s.contains("à quoi tu sers") || s.contains("a quoi tu sers") ||
        s.contains("fonctionnalit") || s.contains("capacité") ||
        s.contains("comment utiliser") || s.contains("utiliser le chat") ||
        s.contains("que sais-tu") || s.contains("que savez-vous")) {
        return true;
    }

    // ==========================================================================
    // 5. PERMIS DE CONDUIRE - GÉNÉRALITÉS
    // ==========================================================================
    if (s.contains("permis") || s.contains("conduire") || s.contains("code") ||
        s.contains("examen") || s.contains("théorique") || s.contains("pratique") ||
        s.contains("épreuve") || s.contains("epreuve") || s.contains("test") ||
        s.contains("formation") || s.contains("cours") || s.contains("leçon") ||
        s.contains("heure de conduite") || s.contains("heures de conduite") ||
        s.contains("forfait") || s.contains("tarif") || s.contains("prix") ||
        s.contains("coût") || s.contains("cout") || s.contains("budget")) {
        return true;
    }

    // ==========================================================================
    // 6. RÈGLEMENTATIONS ET OBLIGATIONS
    // ==========================================================================
    if (s.contains("obligatoire") || s.contains("nécessaire") || s.contains("faut-il") ||
        s.contains("doit-on") || s.contains("procédure") || s.contains("réglementation") ||
        s.contains("règlement") || s.contains("reglement") || s.contains("loi") ||
        s.contains("droit") || s.contains("légal") || s.contains("legal") ||
        s.contains("condition") || s.contains("prérequis") || s.contains("prerequis") ||
        s.contains("exigence") || s.contains("requis") || s.contains("demande") ||
        s.contains("formulaire") || s.contains("dossier") || s.contains("inscription")) {
        return true;
    }

    // ==========================================================================
    // 7. QUESTIONS GÉOGRAPHIQUES ET PAR PAYS
    // ==========================================================================
    if (
        s.contains("en tunisie") || s.contains("tunisie") || s.contains("tunisien") ||

        s.contains("pays") || s.contains("national")) {
        return true;
    }

    // ==========================================================================
    // 8. ÂGE ET CONDITIONS D'ACCÈS
    // ==========================================================================
    if (s.contains("âge") || s.contains("age") || s.contains("quel âge") ||
        s.contains("mineur") || s.contains("majeur") || s.contains("mineure") ||
        s.contains("année") || s.contains("annee") || s.contains("ans") ||
        s.contains("trop vieux") || s.contains("trop jeune") || s.contains("limite d'âge")) {
        return true;
    }

    // ==========================================================================
    // 9. SANTÉ ET MÉDICAL
    // ==========================================================================
    if (s.contains("santé") || s.contains("sante") || s.contains("médical") ||
        s.contains("medical") || s.contains("vision") || s.contains("vue") ||
        s.contains("handicap") || s.contains("handicapé") || s.contains("invalid") ||
        s.contains("visite médicale") || s.contains("certificat médical") ||
        s.contains("yeux") || s.contains("lunettes") || s.contains("verres")) {
        return true;
    }

    // ==========================================================================
    // 10. CATÉGORIES DE PERMIS
    // ==========================================================================
    if (s.contains("permis a") || s.contains("permis b") || s.contains("permis c") ||
        s.contains("permis d") || s.contains("permis e") || s.contains("catégorie") ||
        s.contains("categorie") || s.contains("moto") || s.contains("voiture") ||
        s.contains("camion") || s.contains("poids lourd") || s.contains("bus") ||
        s.contains("scooter") || s.contains("cyclomoteur") || s.contains("125")) {
        return true;
    }

    // ==========================================================================
    // 11. DURÉES ET DÉLAIS
    // ==========================================================================
    if (s.contains("combien de temps") || s.contains("durée") || s.contains("duree") ||
        s.contains("délai") || s.contains("delai") || s.contains("temps") ||
        s.contains("rapide") || s.contains("accéléré") || s.contains("accelere") ||
        s.contains("intensif") || s.contains("stage") || s.contains("formation accélérée") ||
        s.contains("mois") || s.contains("semaine") || s.contains("jour")) {
        return true;
    }

    // ==========================================================================
    // 12. RÉUSSITE ET STATISTIQUES
    // ==========================================================================
    if (s.contains("réussite") || s.contains("reussite") || s.contains("taux") ||
        s.contains("statistique") || s.contains("pourcentage") || s.contains("chance") ||
        s.contains("difficile") || s.contains("facile") || s.contains("échec") ||
        s.contains("echec") || s.contains("raté") || s.contains("rate") ||
        s.contains("recommencer") || s.contains("redoubler") || s.contains("repêchage")) {
        return true;
    }

    // ==========================================================================
    // 13. QUESTIONS PÉDAGOGIQUES
    // ==========================================================================
    if (s.contains("apprendre") || s.contains("apprentissage") || s.contains("pédagogie") ||
        s.contains("pedagogie") || s.contains("méthode") || s.contains("methode") ||
        s.contains("technique") || s.contains("conseil") || s.contains("astuce") ||
        s.contains("réviser") || s.contains("reviser") || s.contains("préparation") ||
        s.contains("preparation") || s.contains("entraînement") || s.contains("entrainement")) {
        return true;
    }

    // ==========================================================================
    // 14. QUESTIONS DE FIN DE CONVERSATION
    // ==========================================================================
    if (s.contains("merci") || s.contains("thank") || s.contains("thanks") ||
        s.contains("au revoir") || s.contains("aurevoir") || s.contains("bye") ||
        s.contains("goodbye") || s.contains("à bientôt") || s.contains("a bientot") ||
        s.contains("fin") || s.contains("terminer") || s.contains("stop") ||
        s.contains("ça va aller") || s.contains("ca va aller") || s.contains("c'est bon")) {
        return true;
    }

    // ==========================================================================
    // 15. QUESTIONS DIVERSES SUR LA CONDUITE
    // ==========================================================================
    if (s.contains("route") || s.contains("autoroute") || s.contains("ville") ||
        s.contains("campagne") || s.contains("nuit") || s.contains("pluie") ||
        s.contains("neige") || s.contains("brouillard") || s.contains("danger") ||
        s.contains("accident") || s.contains("risque") || s.contains("sécurité") ||
        s.contains("securite") || s.contains("vitesse") || s.contains("freinage") ||
        s.contains("stationnement") || s.contains("parking") || s.contains("créneau") ||
        s.contains("creneau") || s.contains("rond-point") || s.contains("rond point")) {
        return true;
    }

    return false;
}

void ChatBot::onFinished(QNetworkReply *reply)
{
    reply->deleteLater();

    if (reply->error()) {
        QString errorStr = QString("Erreur réseau: %1").arg(reply->errorString());
        qDebug() << "❌" << errorStr;
        emit errorOccured(errorStr);
        return;
    }

    QByteArray data = reply->readAll();

    if (data.isEmpty()) {
        qDebug() << "❌ Réponse API vide";
        emit errorOccured("Réponse vide de l'API");
        return;
    }

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "❌ JSON invalide:" << parseError.errorString();
        emit errorOccured("Réponse invalide de l'API");
        return;
    }

    QJsonObject root = doc.object();

    if (!root.contains("choices") || !root["choices"].isArray()) {
        qDebug() << "❌ Pas de 'choices' dans la réponse";
        emit errorOccured("Structure de réponse API invalide");
        return;
    }

    QJsonArray choices = root["choices"].toArray();
    if (choices.isEmpty()) {
        qDebug() << "❌ Tableau 'choices' vide";
        emit errorOccured("Aucun choix dans la réponse API");
        return;
    }

    QJsonObject firstChoice = choices[0].toObject();
    if (!firstChoice.contains("message") || !firstChoice["message"].isObject()) {
        qDebug() << "❌ Pas de 'message' dans le choix";
        emit errorOccured("Message manquant dans la réponse");
        return;
    }

    QJsonObject message = firstChoice["message"].toObject();
    if (!message.contains("content") || !message["content"].isString()) {
        qDebug() << "❌ Pas de 'content' dans le message";
        emit errorOccured("Contenu manquant dans la réponse");
        return;
    }

    QString text = message["content"].toString().trimmed();

    if (text.isEmpty()) {
        qDebug() << "❌ Contenu texte vide";
        emit errorOccured("Réponse vide de l'assistant");
        return;
    }

    qDebug() << "✅ Réponse:" << text;
    emit replyReady(text);
}

// -------------------------------------------------
//  DETECTION SQL - VERSION AMÉLIORÉE
// -------------------------------------------------
QString ChatBot::detectSql(const QString &q) const
{
    QString s = q.toLower().trimmed();
    qDebug() << "🤖 ChatBot analyse:" << s;

    // ✅ CANDIDATS
    bool isCandidatRequest =
        s.contains("candidat") || s.contains("condidat") ||
        s.contains("élève") || s.contains("eleve") ||
        s.contains("apprenti") || s.contains("étudiant");

    if (isCandidatRequest) {
        if (s.contains("leur nom") || s.contains("leurs nom") || s.contains("nom")) {
            return "SELECT NOM_C, PRENOM_C FROM CANDIDATS";
        }

        if (s.contains("liste") || s.contains("afficher") || s.contains("voir")) {
            return "SELECT ID_CANDIDAT, NOM_C, PRENOM_C, CIN_C, TELEPHONE_C, PROGRESSION FROM CANDIDATS";
        }

        if (s.contains("combien") || s.contains("nombre")) {
            return "SELECT COUNT(*) FROM CANDIDATS";
        }

        return "SELECT NOM_C, PRENOM_C FROM CANDIDATS";
    }

    // ✅ EMPLOYÉS
    bool isEmployeRequest =
        s.contains("employé") || s.contains("employe") || s.contains("employés") ||
        s.contains("personnel") || s.contains("staff");

    if (isEmployeRequest) {
        if (s.contains("liste") || s.contains("afficher") || s.contains("voir")) {
            return "SELECT ID_EMPLOYE, NOM_EMP, PRENOM_EMP, POSTE_EMP, SALAIRE_EMP, EMAIL_EMP FROM EMPLOYES";
        }

        if (s.contains("combien") || s.contains("nombre")) {
            return "SELECT COUNT(*) FROM EMPLOYES";
        }

        return "SELECT NOM_EMP, PRENOM_EMP, POSTE_EMP FROM EMPLOYES";
    }

    // ✅ MONITEURS
    bool isMoniteurRequest =
        s.contains("moniteur") || s.contains("instructeur") || s.contains("formateur");

    if (isMoniteurRequest) {
        if (s.contains("liste") || s.contains("afficher") || s.contains("voir")) {
            return "SELECT CIN_M, NOM_M, PRENOM_M, SPECIALITE_M, EXPERIENCE_M, DISPO_M FROM MONITEURS";
        }

        if (s.contains("combien") || s.contains("nombre")) {
            return "SELECT COUNT(*) FROM MONITEURS";
        }

        return "SELECT NOM_M, PRENOM_M, SPECIALITE_M FROM MONITEURS";
    }

    // ✅ VÉHICULES
    bool isVehiculeRequest =
        s.contains("véhicule") || s.contains("vehicule") || s.contains("voiture") ||
        s.contains("moto") || s.contains("auto");

    if (isVehiculeRequest) {
        if (s.contains("liste") || s.contains("afficher") || s.contains("voir")) {
            return "SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, ETAT_V, KILOMETRAGE_V FROM VEHICULES";
        }

        if (s.contains("combien") || s.contains("nombre")) {
            return "SELECT COUNT(*) FROM VEHICULES";
        }

        return "SELECT MATRICULE, TYPE_V, MARQUE_V FROM VEHICULES";
    }

    // ✅ SÉANCES
    bool isSeanceRequest =
        s.contains("séance") || s.contains("seance") || s.contains("cours") ||
        s.contains("leçon") || s.contains("session");

    if (isSeanceRequest) {
        if (s.contains("liste") || s.contains("afficher") || s.contains("voir")) {
            return "SELECT ID_SEANCE, TYPE_S, DATE_S, HEURE_DEBUT_S, HEURE_FIN_S FROM SEANCES";
        }

        if (s.contains("combien") || s.contains("nombre")) {
            return "SELECT COUNT(*) FROM SEANCES";
        }

        return "SELECT ID_SEANCE, TYPE_S, DATE_S FROM SEANCES";
    }

    qDebug() << "❌ Aucune requête SQL détectée pour:" << s;
    return "";
}

// -------------------------------------------------
//  EXECUTION SQL
// -------------------------------------------------
QString ChatBot::execSql(const QString &sql) const
{
    if (!m_db.isOpen()) {
        qDebug() << "❌ Base de données non connectée";
        return "Base non connectée";
    }

    QSqlQuery q(m_db);
    qDebug() << "🔍 Exécution SQL:" << sql;

    if (!q.exec(sql)) {
        QString error = "Erreur SQL: " + q.lastError().text();
        qDebug() << "❌" << error;
        return "Erreur base de données";
    }

    if (sql.contains("COUNT(")) {
        if (q.next()) {
            int count = q.value(0).toInt();
            return QString("%1").arg(count);
        }
        return "0";
    }

    QStringList results;
    int rowCount = 0;

    QSqlRecord rec = q.record();

    while (q.next()) {
        QStringList row;
        for (int i = 0; i < rec.count(); i++) {
            row << q.value(i).toString().trimmed();
        }

        if (rec.count() == 2 && (rec.fieldName(0).contains("NOM") || rec.fieldName(1).contains("PRENOM"))) {
            results << "• " + row[1] + " " + row[0];
        } else {
            results << "• " + row.join(" - ");
        }
        rowCount++;
    }

    if (results.isEmpty()) {
        return "AUCUN_RÉSULTAT";
    }

    return QString("%1 résultat(s):\n%2").arg(rowCount).arg(results.join("\n"));
}

// -------------------------------------------------
//  CREATION PROMPT - VERSION INTELLIGENTE
// -------------------------------------------------
QString ChatBot::buildPrompt(const QString &question, const QString &sqlResult, bool isGeneralQuestion) const
{
    QString prompt = "QUESTION: " + question + "\n\n";

    if (isGeneralQuestion) {
        // ✅ QUESTIONS GÉNÉRALES - réponse libre
        prompt += "Il s'agit d'une question générale sur l'auto-école Smart Drive ou sur toi-même.\n";
        prompt += "Réponds de façon naturelle et utile sans contrainte de données.\n";
        prompt += "Sois courtois et professionnel.\n";
    }
    else if (!sqlResult.isEmpty() && sqlResult != "AUCUN_RÉSULTAT" &&
             !sqlResult.contains("Erreur") && !sqlResult.contains("Base non connectée")) {
        // ✅ QUESTIONS AVEC DONNÉES - réponse stricte
        prompt += "DONNÉES DE LA BASE:\n" + sqlResult + "\n\n";
        prompt += "CONSIGNES:\n";
        prompt += "1. Utilise UNIQUEMENT les données ci-dessus\n";
        prompt += "2. Sois précis avec les chiffres et noms\n";
        prompt += "3. Réponse courte et factuelle\n";
        prompt += "4. Présente les résultats de façon claire\n";
    }
    else if (sqlResult == "AUCUN_RÉSULTAT") {
        // ✅ TABLE VIDE
        prompt += "DONNÉES: La table est VIDE - aucun enregistrement.\n\n";
        prompt += "Réponds: 'Aucun résultat trouvé dans la base de données.'";
    }
    else {
        // ✅ AUCUNE DONNÉE ou ERREUR
        prompt += "Aucune donnée spécifique trouvée pour cette question.\n\n";
        prompt += "Réponds brièvement que tu n'as pas cette information spécifique dans la base de données.";
    }

    return prompt;
}

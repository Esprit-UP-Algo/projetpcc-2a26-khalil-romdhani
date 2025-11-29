# Configuration de l'API Groq

1. Obtenez une clé API GRATUITE sur: https://console.groq.com
2. Copiez `config_template.json` vers `config.json`
3. Remplacez `YOUR_GROQ_API_KEY_HERE` par votre vraie clé Groq
4. Ne partagez jamais votre `config.json`!

## Méthodes de configuration (choisir une):

### Option 1: Variable d'environnement (Recommandée)
```bash
# Linux/Mac
export GROQ_API_KEY=votre_clé_groq_ici

# Windows (Command Prompt)
set GROQ_API_KEY=votre_clé_groq_ici

# Windows (PowerShell)
$env:GROQ_API_KEY="votre_clé_groq_ici"
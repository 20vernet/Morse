# Notice Utilisateur

## Fiche explicative pour utiliser le codeur/décodeur morse

### Utilisation du codeur :

- Lancer le programme avec *./morse*
- Répondre **1** à la question *Que voulez-vous faire ?*
- Le codeur se lance et vous demande le chemin du fichier *.txt* à coder,
- Le fichier à coder doit :
  - Etre écrit uniquement avec des **MAJUSCULES**,
  - Le texte doit être écrit sur une ligne, sans ponctuation,
- Le codeur retourne un fichier *morse.wav* avec le code morse.

Plusieurs exemples de fichiers *.txt* à coder et du fichier *.wav* qui lui est associé dans le dossier **Exemples_codage**.

### Utilisation du décodeur :
- Lancer le programme avec *./morse*
- Répondre **2** à la question *Que voulez-vous faire ?*
- Le décodeur se lance et vous demande le chemin du fichier *.txt* à décoder,
- Le fichier à décoder doit :
  - Contenir le code morse écrit avec des **.** et des **-**,
  - Chaque ensemble de lettre doit être séparé par **1** espace,
  - Deux mots doivent être séparés par **2** espaces,
  - A la fin du message, il doit y avoir les deux caractères **" /"** (espace /),
- Le décodeur retourne un fichier *decode.txt* avec le texte décodé en majuscules.
  
Plusieurs exemples de fichiers *.txt* à décoder et du fichier *.txt* qui lui est associé dans le dossier **Exemples_decodage**.



# Reste à faire :
*Gestion des espaces : pour l'instant, écrire une virgule*
- Modifier le codage pour lire un fichier .txt
- Modifier le makefile pour ne pas créer le fichier build (après un commit du tout qui fonctionne)
- Faire des exemples de codages : couple .txt/.wav ; puis de décodage .txt/.txt
- Essaier de lire un .wav en binaire pour récupérer les données à décoder du fichier audio, et les écrire en ., - et ~ dans un fichier .txt (puis lui appliquer le décodeur)

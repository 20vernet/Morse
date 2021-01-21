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

Plusieurs exemples de fichiers *.txt* à coder et du fichier *.wav* qui lui est associé sont dans le dossier **Exemples_codage**.

### Utilisation du décodeur :
- Lancer le programme avec *./morse*
- Répondre **2** à la question *Que voulez-vous faire ?*
- Le décodeur se lance et vous demande le chemin du fichier *.wav* à décoder,
- Le fichier à décoder doit :
  - Etre un fichier audio *.wav*,
  - Avoir été codé avec le codeur,
- Le décodeur retourne un fichier *decode.txt* avec le texte décodé en majuscules. Il retourne aussi un fichier *texte_morse.txt* contenant le code morse de l'audio transcrit en - et . par le programme.
  
Plusieurs exemples de fichiers *.wav* à décoder et du fichier *.txt* qui lui est associé sont dans le dossier **Exemples_decodage**.


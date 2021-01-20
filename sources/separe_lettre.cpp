#include <string>

int separe_lettre(std::string texte, std::string* separe){
    // La fonction permet aussi de récupérer le nombre de carctère du message (lettre ou espace)
    int lon = texte.length();
    int i_txt = 0;
    int i_sep = 0;
    
    while(i_txt<lon-1){
        // Pour gérer la fin et ne pas avoir de problème dans le else
            if(texte[i_txt] == ' '){
                separe[i_sep] = ' ';
                i_txt = i_txt + 1;    
            }

            else{
                std::string lettre;
                int k = 0;
                while(texte[i_txt+k] != ' '){
                    k = k+1;
                }
                lettre.append(texte, i_txt, k);
                separe[i_sep] = lettre;
                i_txt = i_txt + k + 1;
                // Prise en compte de l'espace entre deux série de caractères pour 2 lettres
            }
            i_sep = i_sep +1;

            // A la fin d'une boucle, on a ajouté un caractère au tableau de string separe
            // Soit un espace, soit une lettre
            // i_sep correspond alors au nombre de caractère présents dans separe 
    }
    
    return(i_sep);
}

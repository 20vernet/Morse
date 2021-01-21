#include <iostream>
#include <fstream>
#include "pre_decodage.h"


//on lit les données dans un fichier texte pour l'instant

void decode_morse(){
    //récupérer l'emplacement du fichier (texte) à lire
    std::string empl = lecture();
    
    // empl est l'adresse du fichier texte pour le décodeur
    // Il est générer par la fonction lecture à partir d'un fichier audio
    
    //ouverture du fichier
    std::ifstream fichier_lu (empl);

    //lecture du fichier
    std::string contenu;
    std::getline(fichier_lu, contenu);
    int lon = contenu.length();
    std::string separe[lon];

    //séparationde contenu en tableau de tring avec chaque lettre séparée
    int lon_message = separe_lettre(contenu, separe);

    // Ecriture de chaque caractère dans un fichier .txt
    ecrire_fichier(separe, lon_message);


    //fermeture du fichier
    fichier_lu.close();
}

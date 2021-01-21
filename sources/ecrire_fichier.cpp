#include <iostream>
#include <fstream>

#include <string>
#include <map>


std::map<std::string, char> morse_to_fr;

void ecrire_fichier(std::string* separe, int lon_message){
    // Ouverture fichier
    std::ofstream fichier_ecrit ("decode.txt");

    // Dictionnaire
    morse_to_fr[" "] = ' ';
    morse_to_fr[".-"] = 'A';
    morse_to_fr["-..."] = 'B';
    morse_to_fr["-.-."] = 'C';
    morse_to_fr["-.."] = 'D';
    morse_to_fr["."] = 'E';
    morse_to_fr["..-."] = 'F';
    morse_to_fr["--."] = 'G';
    morse_to_fr["...."] = 'H';
    morse_to_fr[".."] = 'I';
    morse_to_fr[".---"] = 'J';
    morse_to_fr["-.-"] = 'K';
    morse_to_fr[".-.."] = 'L';
    morse_to_fr["--"] = 'M';
    morse_to_fr["-."] = 'N';
    morse_to_fr["---"] = 'O';
    morse_to_fr[".--."] ='P' ;
    morse_to_fr["--.-"] = 'Q';
    morse_to_fr[".-."] = 'R';
    morse_to_fr["..."] = 'S';
    morse_to_fr["-"] = 'T';
    morse_to_fr["..-"] = 'U';
    morse_to_fr["...-"] = 'V';
    morse_to_fr[".--"] = 'W';
    morse_to_fr["-..-"] = 'X';
    morse_to_fr["-.--"] = 'Y';
    morse_to_fr["--.."] = 'Z';
    // Fin dictionnaire

    for(int i; i<lon_message; i+=1){
        std::string val = separe[i];
        fichier_ecrit << morse_to_fr[val];
    }


    //fermeture fichier
    fichier_ecrit.close();

}

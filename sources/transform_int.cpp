#include <iostream>
#include <map>
#include <string>

// Définition du dictionnaire
std::map<char, std::string> fr_to_morse;

// Cette fonction transforme la chaîne de caractère à coder
// En un tableau d'entiers représentant la durée du son ou du blanc
// Les morceau de son sont représentés par des entiers positifs
// Les morceaux de blanc sont représentés par des entiers négatifs

void transform_int(std::string text, int* code, int length){
    int ind_int = 0;

    // Dictionnaire
    fr_to_morse[' '] = " ";
    fr_to_morse['A'] = ".-";
    fr_to_morse['B'] = "-...";
    fr_to_morse['C'] = "-.-.";
    fr_to_morse['D'] = "-..";
    fr_to_morse['E'] = ".";
    fr_to_morse['F'] = "..-.";
    fr_to_morse['G'] = "--.";
    fr_to_morse['H'] = "....";
    fr_to_morse['I'] = "..";
    fr_to_morse['J'] = ".---";
    fr_to_morse['K'] = "-.-";
    fr_to_morse['L'] = ".-..";
    fr_to_morse['M'] = "--";
    fr_to_morse['N'] = "-.";
    fr_to_morse['O'] = "---";
    fr_to_morse['P'] = ".--.";
    fr_to_morse['Q'] = "--.-";
    fr_to_morse['R'] = ".-.";
    fr_to_morse['S'] = "...";
    fr_to_morse['T'] = "-";
    fr_to_morse['U'] = "..-";
    fr_to_morse['V'] = "...-";
    fr_to_morse['W'] = ".--";
    fr_to_morse['X'] = "-..-";
    fr_to_morse['Y'] = "-.--";
    fr_to_morse['Z'] = "--..";
    // Fin du dictionnaire
    
    // Parcours de la chaîne de caractère à coder
    for(int i = 0; i < length; i+=1){
        
        char let = text[i];
        std::string letter = fr_to_morse[let];

        int lon = letter.length();

        // Parcours de la lettre morse pour écrire les différents poids de chaque carctère
        // Dans le tableau d'entiers
        for(int k = 0; k < lon; k+=1){
        
            if(letter[k] == ' '){
                code[ind_int + k] = -4; // Normalment -7, mais on mais -3 après chaque lettre
            }
            else if(letter[k] == '.'){
                code[ind_int + k] = 1;
            }
            else if(letter[k] == '-'){
                code[ind_int + k] = 3;
            }
        

        }
        // On a mis une lettre, on ajoute l'espace de -2 pour signifier la fin de la lettre 
        // (car on ajoute -1 à chaque symbole mis en audio)
        code[ind_int + lon] = -2;

        // On passe à la lettre suivante pour le tableau d'entiers
        ind_int = ind_int + lon + 1;
    }
}

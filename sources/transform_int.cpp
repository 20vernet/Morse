#include <iostream>
#include <map>
#include <string>

std::map<char, std::string> fr_to_morse;


void transform_int(std::string text, int* code, int length){
    int ind_int = 0;

     //dico
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
    //fin dico
    
     
    for(int i = 0; i < length; i+=1){
        
        char let = text[i];
        std::string letter = fr_to_morse[let];

        int lon = letter.length();

      
        for(int k = 0; k < lon; k+=1){
        
            if(letter[k] == ' '){
                code[ind_int + k] = -4; //normalment -7, mais on mais -3 après chaque lettre
            }
            else if(letter[k] == '.'){
                code[ind_int + k] = 1;
            }
            else if(letter[k] == '-'){
                code[ind_int + k] = 3;
            }
        

        }
        //on a mis une lettre, on ajoute l'espace de -1-2 pour signifier la fin de la lettre (car on ajoute -1
        //à chaque symbole mis en audio)
        code[ind_int + lon] = -2;

        //on passe à la lettre suivante
        ind_int = ind_int + lon + 1;
    }
}

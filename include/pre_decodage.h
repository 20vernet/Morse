#include <string>

// Fonctions nécessaires pour decode_morse.cpp

int separe_lettre(std::string texte, std::string* separe);
void ecrire_fichier(std::string* separe, int lon_message);
std::string lecture();
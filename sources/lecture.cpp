#include <iostream>
#include <fstream>
#include <string>




std::string lecture(){
    std::ifstream myfile;
    std::string chemin;
    std::cout<<"Chemin de l'audio :"<<std::endl;
    std::cin>>chemin;
    myfile.open(chemin, std::ios::binary|std::ios::ate);

    unsigned long int size = myfile.tellg();
    char header[44];
    int t;
    int pas = 8850; // Nombre d'échantillons pour dt = 0.2
    

    myfile.seekg(0, std::ios::beg);
    myfile.read(header, 44);
    unsigned long int longueur = (size-44)/2 -100; //Pour être sur de ne pas avoir de problèmes....
    int* suite;

    suite = (int*) calloc(longueur + 2*pas, sizeof(int)) ;

    // Récupération des données

    for(unsigned long int i = 0; i<longueur; i+=1){
        myfile.read((char*) &t, 2);
        suite[i] = t;
    }
    
    myfile.close();
    
    // Fin récupération des données


    // Calcul des longueurs des blancs et des sons
    int blanc[longueur/10 +1];
    int count = 0;

    for(unsigned long int i = 0; i<longueur; i+=10){
        if(suite[i]==suite[i+5]){
            blanc[count] = -1;
        }
        else{
            blanc[count] = 1;
        }
        count +=1;
    }


    // Parcour des données pour connaître ce qui est codé


    std::ofstream fichier_ecrit ("texte_morse.txt");

    unsigned long int i = 0;
    while(i<longueur/10 +1){
    //for(int k = 0; k<10; k+=1){
        if(blanc[i] == 1){
            // On est dans un son
            int temps = 0; 

            while(blanc[i] == 1){
                // On compte le nombre de dizaine d'échantillpon de son
                temps += 1;
                i = i+1;
            }

            // Le nombre d'échantillon de son paut être 1 pas ou 3 pas
            if(temps == 882){
                // On a un point
                fichier_ecrit << ".";
            }

            else if(temps == 2646){
                // On a un trait
                fichier_ecrit << "-";
            }

            
        }

        else{
            // On est dans un blanc
            int temps = 0; 

            while(blanc[i] == -1){
                // On compte le nombre de dizaine d'échantillpon de blanc
                temps += 1;
                i = i+1;
            }


            // Le nombre d'échantillon de blanc paut être 1 pas, 3 pas ou 7 pas
            if(temps == 7938){
                // On a un blanc d'espace entre mots
                fichier_ecrit << "  ";
            }

            else if(temps == 2646){
                // On a un blanc entre lettre
                fichier_ecrit << " ";
            }

            // Si on ne vérifie aucune de ces deux conditions, c'est un blanc inter caractère
            // on ne fait rien

            
        }
    }
    
  

    // A la fin de la boucle, on ajoute " /" pour le décodeur
    fichier_ecrit<<" /";
    fichier_ecrit<<'\n';
    

    fichier_ecrit.close();

    return "texte_morse.txt";
}


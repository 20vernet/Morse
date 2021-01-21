double calcul_duree(int*code, int length, double dt){
    
    // Calcule de la durée du signal
    double dure = 0;
    

    for(int i = 0; i < length; i+=1){
        
        if(code[i]>0){
            int val = code[i];

            // On ajoute le blanc après chaque point ou trait d'un même caractère
            dure = dure + (val+1)*dt; 
        }

        if(code[i]<0){
            dure = dure - code[i]*dt;
        }
       
    }
    return(dure);
}

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "GenerationCode.h"



int main()
{
    erase_fichier();
    int choix = afficher_menu();
     //efface les donn�es pr�existence sur le fichier param.h
    demander_localisation(); // va d�finir ou sera stocker le fichier param.h
    ecrire_choix(choix); // va g�nerer le fichier param.h

}





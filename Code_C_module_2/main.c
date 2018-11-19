#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "GenerationCode.h"



int main()
{
    erase_fichier();
    int choix = afficher_menu();
     //efface les données préexistence sur le fichier param.h
    demander_localisation(); // va définir ou sera stocker le fichier param.h
    ecrire_choix(choix); // va génerer le fichier param.h

}





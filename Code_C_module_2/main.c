#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "GenerationCode.h"



int main()
{
    erase_fichier();              /*efface les données préexistence sur le fichier param.h */
    int choix = afficher_menu();    /* affiche le menu et récupère la saisie de l'utilisateur dans la variable choix */     /* va définir ou sera stocker le fichier param.h */
    ecrire_choix(choix);            /* va génerer le fichier param.h */

}





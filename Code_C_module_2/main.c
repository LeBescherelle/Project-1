#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "GenerationCode.h"



int main()
{
    erase_fichier();              /*efface les donn�es pr�existence sur le fichier param.h */
    int choix = afficher_menu();    /* affiche le menu et r�cup�re la saisie de l'utilisateur dans la variable choix */     /* va d�finir ou sera stocker le fichier param.h */
    ecrire_choix(choix);            /* va g�nerer le fichier param.h */

}





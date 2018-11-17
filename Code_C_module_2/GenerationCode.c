#include <stdio.h>
#include <stdlib.h>
#include "GenerationCode.h"

void erase_fichier()
{
    FILE *pointeur;  /* on déclare un pointeur de type FILE (qui va permettre d'aller chercher l'emplacement mémoire du fichier à crée/modifier */
    pointeur = fopen("param.h","w+");/* on ouvre le fichier en mode w+ et on écrie rien dedans ce qui permet de l'éffacer ou de le crée si il n'est pas crée */
    fclose(pointeur); /* fonction pour libérer la mémoire alloué au pointeur de type FILE (en d'autre terme on fermer le fichier) */
}

void ecrire_choix(int param)
{


    FILE *pointeur;/* on déclare le pointeur de type FILE */
    pointeur = fopen("param.h", "a+"); /* on ouvre le fichier en mode "a+" ce qui permet d'écrire de positionner le pointeur à la fin du fichier */
    if (pointeur == NULL) /* précaution au cas ou le pointeur n'a pas réussi à être initialiser*/
    {
        printf("erreur \n");
        exit(-1); /* permet une sortie (un arrêt) de l'exécution du programme */
    }
    fprintf(pointeur, "%s %d", "#define param", param); /* on écris notre "choix" dans le fichier param.h, on écris donc #define param "valeur_du_choix" */
    if (param == 2)
    {
        int a;
        printf("une LED sur combien doit etre allume (ne doit pas exceder 10 et ne pas etre egale a 0) ?\n");
        scanf("%d", &a); /* on récupère la valeur */
        if ((a > 10)) || (a==0) /* sers à écrire une condition d'échappement */
        {
            exit(-1);
        }
        if ((a==0)) /* on empêche les valeurs impossible (donc inexploitable par la suite) */
        {
            printf("0 impossible, la valeur sera defini par defaut sur 1\n");
            a=1;
        }
        if (pointeur == NULL)
        {
            printf("erreur \n");
            exit(-1);
        }


        fprintf(pointeur, "%s %d\n", "#define param2", a);

    }
    if (param == 4)
    {
        int a;
        printf("Entrer la valeur de la LED a faire clignoter) ?\n");
        scanf("%d", &a);
        if ((a > 10))
        {
            exit(-1);
        }
        if ((a==0))
        {
            printf("0 impossible, la valeur sera defini par defaut sur 1\n");
            a=1;
        }
        else
        {
            fprintf(pointeur, "\n%s %d", "#define param2", a);



        }
    }
    else
    {
        fprintf(pointeur, "\n%s 0", "#define param2");

    }




    fclose(pointeur);
}







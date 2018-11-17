#include <stdio.h>
#include <stdlib.h>
#include "GenerationCode.h"

void erase_fichier()
{
    FILE *pointeur;  /* on d�clare un pointeur de type FILE (qui va permettre d'aller chercher l'emplacement m�moire du fichier � cr�e/modifier */
    pointeur = fopen("param.h","w+");/* on ouvre le fichier en mode w+ et on �crie rien dedans ce qui permet de l'�ffacer ou de le cr�e si il n'est pas cr�e */
    fclose(pointeur); /* fonction pour lib�rer la m�moire allou� au pointeur de type FILE (en d'autre terme on fermer le fichier) */
}

void ecrire_choix(int param)
{


    FILE *pointeur;/* on d�clare le pointeur de type FILE */
    pointeur = fopen("param.h", "a+"); /* on ouvre le fichier en mode "a+" ce qui permet d'�crire de positionner le pointeur � la fin du fichier */
    if (pointeur == NULL) /* pr�caution au cas ou le pointeur n'a pas r�ussi � �tre initialiser*/
    {
        printf("erreur \n");
        exit(-1); /* permet une sortie (un arr�t) de l'ex�cution du programme */
    }
    fprintf(pointeur, "%s %d", "#define param", param); /* on �cris notre "choix" dans le fichier param.h, on �cris donc #define param "valeur_du_choix" */
    if (param == 2)
    {
        int a;
        printf("une LED sur combien doit etre allume (ne doit pas exceder 10 et ne pas etre egale a 0) ?\n");
        scanf("%d", &a); /* on r�cup�re la valeur */
        if ((a > 10)) || (a==0) /* sers � �crire une condition d'�chappement */
        {
            exit(-1);
        }
        if ((a==0)) /* on emp�che les valeurs impossible (donc inexploitable par la suite) */
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







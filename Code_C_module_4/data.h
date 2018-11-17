/**
	*@file data.h
	*@brief Header du fichier de gestion des données.
	*@author Antonin
	*@version 1.0
	*@date 12 novembre 2018
	*
	*Extrait les données du fichier csv et contrôle la structure de données.
*/

#ifndef DEF_DATA
#define DEF_DATA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable : 4996) //Désactive des erreurs liées à Visual Studio.

/**
	*@struct Data_Line	
	*@brief Structure contenant les informations d'une ligne de données extraite du fichier.
*/
typedef struct
{
	int time;
	int heartRate;
}Data_Line;


/**
	*@fn static FILE* open_file(char* path, char* openingMode)
	*@brief Ouverture d'un fichier.
	*
	*@param path Chemin du fichier à ouvrir.
	*@param openingMode Mode d'ouverture du fichier.
	*@return FILE* - Fichier ouvert.
*/
FILE* open_file(char* path, char* openingMode);


/**
	*@fn Data_Line* tab_fill_data()
	*@brief Lecture du fichier de données et insertion
	*des données dans le tableau de données.
	*
	*@return Data_Line* - Tableau de Data_Line rempli.
*/
Data_Line* tab_fill_data();


/**
	*@fn int get_tab_size(Data_Line *tab)
	*@brief Calcule la taille du tableau de données.
	*
	*@param tab Tableau de Data_Line à calculer.
	*@return int - Nombre de structures dans le tableau.
*/
int get_tab_size(Data_Line *tab);


/**
	*@fn static void split_save_line(char *toSplit, int *first, int *second)
	*@brief Extrait les deux variables (int, int) de la chaîne
	*et les sauvegardes dans deux variables.
	*
	*@param toSplit Chaîne à découper et sauvegarder.
	*@param first Variable int où enregistrer la première valeur.
	*@param second Variable int où enregistrer la deuxième valeur.

*/
void split_save_line(char *toSplit, int *first, int *second);


/**
	*@fn static void uptade_tab_memory(void** tab, size_t size)
	*@brief Modifie l'espace mémoire alloué pour un tableau.
	*
	*@param tab Pointeur sur le tableau duquel modifier l'espace mémoire.
	*@param size Taille en octets de l'espace mémoire à allouer.
*/
static void uptade_tab_memory(void** tab, size_t size);

#endif
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
#pragma warning(disable : 4996)

/**
	*@struct Data_Line	
	*@brief Structure contenant les informations d'une ligne de données extraite du fichier.
*/
typedef struct
{
	int time;
	float heartRate;
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
	*@return Data_Line* - Tableau de Data_Line remplit.
*/
Data_Line* tab_fill_data();


/**
	*@fn int get_tab_size(Data_Line *tab)
	*@brief Calcule la taille du tableau de données.
	*
	*@param tab Tableau de Data_Line à calculer.
	*@return int - Nombre de structure dans le tableau.
*/
int get_tab_size(Data_Line *tab);


/**
	*@fn static void replace_char(char *toChange, char toFind, char toReplace)
	*@brief remplace un type de caractère par un autre dans toute une chaine.
	*
	*@param toChange Chaine à modifier.
	*@param toFind Valeur à remplacer.
	*@param toReplace Valeur de remplacement.

*/
void replace_char(char *toChange, char toFind, char toReplace);


/**
	*@fn static void split_save_line(char *toSplit, float *first, int *second)
	*@brief Extrait les deux variables (float, int) de la chaine.
	*
	*@param toSplit Chaine à découper et sauvegarder.
	*@param first Variable int ou enregistrer la première donnée.
	*@param second Variable float ou enregistrer la deuxième valeur.

*/
void split_save_line(char *toSplit, int *first, float *second);


/**
	*@fn static void delete_specials_characters(char *toChange)
	*@brief Supprime les caractères spéciaux au début d'une chaine.
	*
	*@param toChange Chaine à modifier.
*/
static void delete_specials_characters(char *toChange);


/**
	*@fn static void tab_write(Data_Line* tab, char* toWrite, int* pos)
	*@brief Traite la chaine de caractère extraite du fichier et remplit
	*une structure du tableau de données.
	*
	*@param tab Tableau de données ou sont les structures.
	*@param toWrite chaine à découper et sauvegarder.
	*@param pos Pointeur sur l'index ou écrire dans le tableau.
*/
static void tab_write(Data_Line* tab, char* toWrite, int pos);


/**
	*@fn static void uptade_tab_memory(void** tab, size_t size)
	*@brief Modifie l'espace mémoire alloué pour un tableau.
	*
	*@param tab Pointeur sur le tableau auquel modifier l'espace mémoire.
	*@param size Taille en octet de l'espace mémoire à allouer.
*/
static void uptade_tab_memory(void** tab, size_t size);

#endif
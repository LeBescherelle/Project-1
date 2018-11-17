/**
	*@file treatment.h
	*@brief Header du fichier de traitement des données.
	*@author Antonin
	*@version 1.0
	*@date 15 novembre 2018
	*
	*Effectue des traitements sur les données.
*/

#ifndef DEF_TREATMENT
#define DEF_TREATMENT

#include "data.h"
#include <stdlib.h>

/**
	*@fn void display_all_data(Data_Line* data, size_t size)
	*@brief Affiche toutes les données enregistrées dans la
	*structure de données.
	*
	*@param data Tableau de données à afficher.
	*@param size Taille du tableau.
*/
void display_all_data(Data_Line* data, size_t size);


/**
	*@fn void display_all_file()
	*@brief Affiche toutes les lignes du fichier csv.
*/
void display_all_file();


/**
	*@fn int compare_time(Data_Line first, Data_Line second)
	*@brief Fonction de comparaison du temps entre
	*deux lignes de données.
	*
	*@param first Première ligne à comparer.
	*@param second Deuxième ligne à comparer.
	*@return int - si return > 0 alors first > second.
*/
int compare_time(Data_Line first, Data_Line second);


/**
	*@fn int compare_bpm(Data_Line first, Data_Line second)
	*@brief Fonction de comparaison des bpm entre
	*deux lignes de données.
	*
	*@param first Première ligne à comparer.
	*@param second Deuxième ligne à comparer.
	*@return int - si return > 0 alors first > second.
*/
int compare_bpm(Data_Line first, Data_Line second);


/**
	*@fn void tab_sort(Data_Line* tab, size_t size, int(*compareFunction)(Data_Line, Data_Line), int ascending)
	*@brief Trie le tableau de données soit par ordre croissant
	*soit par ordre décroissant.
	*Prend une fonction de comparaison en paramètre.
	*Utilise un tri par sélection O(n²).
	*
	*@param tab Tableau à trier.
	*@param size Taille du tableau.
	*@param compareFunction Fonction de comparaison.
	*@param ascending Si 1 alors tri par ordre croissant, 0 pour ordre décroissant.
*/
void tab_sort(Data_Line* tab, size_t size, int(*compareFunction)(Data_Line, Data_Line), int ascending);


/**
	*@fn Data_Line search_bpm(Data_Line* tab, size_t size, int time)
	*@brief Recherche une valeur de bpm en fonction d'un temps.
	*Utilise un algorithme de recherche séquentielle O(n).
	*
	*@param tab Tableau où effectuer la recherche.
	*@param size Taille du tableau.
	*@param time Critère de temps où effectuer la recherche.
	*@return Data_Line - Structure de la ligne trouvée.
*/
Data_Line search_bpm(Data_Line* tab, size_t size, int time);


/**
	*@fn double get_average_pulse(Data_Line* tab, size_t size, int firstTime, int secondTime)
	*@brief Calcule la moyenne de pouls dans un intervalle de temps.
	*Utilise un algorithme de recherche séquentielle O(n).
	*
	*@param tab Tableau de données.
	*@param size Taille du tableau de données.
	*@param firstTime Première borne de l'intervalle (temps).
	*@param secondTime Seconde borne de l'intervalle (temps).
	*@return double - Moyenne de pouls dans l'intervalle.
*/
double get_average_pulse(Data_Line* tab, size_t size, int firstTime, int secondTime);


/**
	*@fn void display_max_min_pulse(Data_Line* tab, size_t size)
	*@brief Affiche le maximum et minimum du pouls enregistré.
	*Utilise un algorithme de recherche séquentielle O(n).
	*
	*@param tab Tableau de données.
	*@param size Taille du tableau de données.
*/
void display_max_min_pulse(Data_Line* tab, size_t size);

#endif
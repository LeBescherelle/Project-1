/**
	*@file menu.h
	*@brief Header du fichier de gestion des menus.
	*@author Antonin
	*@version 1.0
	*@date 15 novembre 2018
	*
	*Contrôle l'affichage du menu et l'éxecution des choix.
*/

#ifndef DEF_MENU
#define DEF_MENU

#include <stdlib.h>
#include "data.h"

#define SCREEN_CLEAR() system("cls");
#define LINE_BREAK() printf("\n\n");
#define PAUSE() system("pause");


/**
	*@fn void display_menu(Data_Line* tab, size_t size)
	*@brief Affiche le menu principal.
	*
	*@param tab Tableau de données.
	*@param size Taille du tableau de données.
*/
void display_menu(Data_Line* tab, size_t size);


/**
	*@fn static int get_menu_choice()
	*@brief Récupère le choix de l'utilisateur.
	*
	*@return int - Choix de l'utilisateur.
*/
static int get_menu_choice();


/**
	*@fn static int check_input_int()
	*@brief Récupère la valeur que l'utilisateur rentre,
	*et vérifie que c'est bien un entier.
	*Ferme le programme si la valeur n'est pas un entier.
	*
	*@return int - Entier rentré par l'utilisateur.
*/
static int check_input_int();


/**
	*@fn static void display_sort_menu()
	*@brief Affiche les menus de tri.
*/
static void display_sort_menu();


/**
	*@fn static void choice_execution(Data_Line* tab, size_t size, int subIndex)
	*@brief Execute	le choix de l'utilisateur.
	*
	*@param tab Tableau de données.
	*@param size Taille du tableau de données.
	*@param choice Choix de l'utilisateur.
*/
static void choice_execution(Data_Line* tab, size_t size, int choice);


/**
	*@fn static void sort_exec(Data_Line* tab, size_t size, int subIndex, int ascending)
	*@brief Execute le tri choisi par l'utilisateur.
	*
	*@param tab Tableau des données.
	*@param size Taille du tableau de données.
	*@param choice Choix utilisateur entre tri par temps ou par bpm.
	*@param ascending Boolean pour tri par ordre croissant ou décroissant.
*/
static void sort_exec(Data_Line* tab, size_t size, int choice, int ascending);


/**
	*@fn static void sub_menu_research(Data_Line* tab, size_t size);
	*@brief Sous-menu pour effectuer une recherche de donnée.
	*
	*@param tab Tableau des données.
	*@param size Taille du tableau de données.
*/
static void sub_menu_research(Data_Line* tab, size_t size);


/**
	*@fn static void sub_menu_average(Data_Line* tab, size_t size)
	*@brief Sous-menu pour calculer la moyenne
	*dans une intervalle de temps donnée.
	*
	*@param tab Tableau des données.
	*@param size Taille du tableau de données.
*/
static void sub_menu_average(Data_Line* tab, size_t size);

#endif
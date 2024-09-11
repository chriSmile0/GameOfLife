#ifndef __JEU_H
#define __JEU_H

#include "grille.h"
/**\file jeu.h
 * \brief jeu.h contient les prototypes des fonctions et certaines fonctions qui vont etre implémentées ici qui seront utilisés dans jeu.c
 * \author Spitz chrsitopher
 *
 * Commentaire longs du fichier pouvant\n
 * s'étendre sur plusieurs lignes\n
 * à la suite.\n
 */



 /**
 * \brief Effectue le modulo entre 2 nombres
 * \param [in] i le nombre 1
 * \param [in] m le nombre 2
 * \return return i modulo m
 */

// modulo modifié pour traiter correctement les bords i=0 et j=0
// dans le calcul des voisins avec bords cycliques
static inline int modulo(int i, int m) {return (i+m)%m;}


/**
 * \brief Un pointeur de fonction qui va pointer vers compte_voisins_vivants_nc ou compte_voisins_vivants_c
 * \param [in] i ligne de la cellule autour de laquelle il faut compter si le voisinage est vivant ou non
 * \param [in] j colonne de la cellule autour de laquelle il faut compter si le voisinage est vivant ou non
 * \param [in] g une grille allouer de 2 dimensions
 * \return retourne un entier qui est le nombre de voisins vivants de la cellule i j
 */
 // compte le nombre de voisins vivants de la cellule (i,j)
// les bords sont cycliques.
// On s'en sert maintenant comme d'un pointeur de fonction pour choisir entre non cyclique et cyclique
int (* compte_voisins_vivants)(int i, int j, grille g);
/**
 * \brief Fonction qui va compter les voisins vivants de manière non cyclique
 * \param [in] i ligne de la cellule autour de laquelle il faut compter si le voisinage est vivant ou non
 * \param [in] j colonne de la cellule autour de laquelle il faut compter si le voisinage est vivant ou non
 * \param [in] g une grille allouer de 2 dimensions
 * \return retourne un entier qui est le nombre de voisins vivants de la cellule i j
 */
//fonction qui lorsqu'elle elle est activée va  effectuée le comptage des voisins de façon non cyclique
int  compte_voisins_vivants_nc(int i,int j , grille g);
/**
 * \brief Fonction qui va compter les voisins vivants de manière cyclique
 * \param [in] i ligne de la cellule autour de laquelle il faut compter si le voisinage est vivant ou non
 * \param [in] j colonne de la cellule autour de laquelle il faut compter si le voisinage est vivant ou non
 * \param [in] g une grille allouer de 2 dimensions
 * \return retourne un entier qui est le nombre de voisins vivants de la cellule i j
 */
//fonction qui lorsqu'elle est activée va effecguée le compte des voisins de façon cyclique
int  compte_voisins_vivants_c(int i, int j, grille g);

//int config_suivante(grille *g,grille *g_oscille);
/**
 * \brief Fonction qui va faire evoluer les cellules et avec la fonction veillissement qui va augmenter leurs valeurs
 * \brief jusqu'à la valeur de 8 pour ensuite les faires mourir si les cellules vivantes l'ont étaient consecutivement 8 fois
 * \param [in] gc une grille allouer de 2 dimensions
 * \param [in] g une grille allouer de 2 dimensions
 * \param [in] vieillissement  entier qui sert de booleen
 * \return ne retourne rien , elle fait juste varier les cellules et utilise les 2 fonctions implementer plus haut dans jeu.c
 */
void evolue (grille *g, grille *gc,int vieillissement);

#endif

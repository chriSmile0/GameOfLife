#ifndef __IO_H
#define __IO_H

#include <stdio.h>
#include "grille.h"
#include "jeu.h"
#include <cairo/cairo.h>
#include <cairo/cairo-xlib.h>
#include <X11/Xlib.h>
#include <math.h>
/**\file io.h
 * \brief io.h contient les prototypes des fonctions qui faire en sorte que l'on puisse jouer et donc affiche et effacer la grille
 * \author Spitz chrsitopher
 *
 * Commentaire longs du fichier pouvant\n
 * s'étendre sur plusieurs lignes\n
 * à la suite.\n
 */

 /**
 * \brief Affichage d'une grille a 2 dimensions
 * \param [in] *g une grille sous forme d'adresse
 * \return Affiche la grille en sortie (dans le terminal)
 */

// affichage d'une grille
void affiche_grille (const grille *g);


/**
 * \brief Affichage d'une grille a 2 dimensions
 * \param [in] *g une grille sous forme d'adresse
 * \param [in] *surface element qui a pour but d'initialiser une fenetre graphique
 * \return Affiche la grille en sortie dans une fenetre graphique
 */
//affichage d'une grille en mode graphique
 void affiche_grille_cairo(cairo_surface_t *surface, const grille *g, int vieillissement);

/**
 * \brief Efface une grille a 2 dimensions
 * \param [in] *g une grille sous forme d'adresse
 * \return Efface la grille qui se trouve en sortie
 */

void efface_grille (const grille *g);
/**
 * \brief Cette fonction contient les caractères que l'on peut entrer pour jouer et toutes les fonctions pour jouer
 * \param [in] *g une grille sous forme d'adresse
 * \param [in] *gc une grille sous forme d'adresse
 * \return Pas de retour mais cela effectue les fonctions lorsque l'on entre certains caractères dans la sortie standard
 */
 //debute le jeu en cairo

void debut_jeu(grille *g, grille *gc,grille *g_oscille);

#endif

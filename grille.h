#ifndef __GRILLE_H
#define __GRILLE_H

#include <stdbool.h>
/**\file grille.h
 * \brief grille.h contient les prototypes des fonctions qui vont etre implementer dans grille.c
 * \author Spitz chrsitopher
 *
 * Commentaire longs du fichier pouvant\n
 * s'étendre sur plusieurs lignes\n
 * à la suite.\n
 */


 /**
 * \brief Structure d'une grille qui contient un nombre de ligne, un nombre de colonne et un tableau a 2 dimensions
 *
 * Commentaire long\n
 * sur plusieurs lignes si\n
 * besoin.\n
 */

// structure grille : nombre de lignes, nombre de colonnes, tableau de tableau de cellules
typedef struct {
  int nbl;
  int nbc;
  int **cellules;
} grille;
/**
 * \brief Allocation d'une  grille a 2 dimensions
 * \param [in] l le nombre de ligne de la grille
 * \param [in] c le nombre de colonne de la grille
 * \param [in] *g une grille sous forme d'adresse
 * \return retourne une grille allouer de taille l par c
 */

// alloue une grille de taille l*c, et initialise toutes les cellules à mortes
void alloue_grille(int l, int c, grille* g);
/**
 * \brief Liberation d'une grille a 2 dimensions
 * \param [in] *g une grille sous forme d'adresse
 * \return ne retourne rien mais a liberer toute la mémoire que la grille occupée
 */
// libère une grille
void libere_grille(grille* g);
/**
 * \brief initialisation de la grille
 * \param [in] *g une grille sous forme d'adresse
 * \param [in] *filename un tableau de caractères qui contient un fichier qui va etre lu
 * \return retourne une grille en fonction du fichier entrer en paramètre
 */
// alloue et initalise la grille g à partir d'un fichier
void init_grille_from_file(char const*const filename, grille* g);
/**
 * \brief Fait la copie d'une grille gs vers une grille gd
 * \pre la precondition est dans le programme mais il faut s'assurer que les grilles
 * \pre est la même taille
 * \param [in] *gs il s'agis de la grille a copier
 * \param [in] *gd il s'agis de la grille qui va recevoir l'autre grille
 * \return retourne une grille
 */

 /**
 * \brief initialise une cellule en cellule vivante
 * \brief comme il s'agis avec une petite partie de code a implementer on peut le faire ici
 * \param [in] *g la grille que l'on utilise
 * \param [in] i ligne de la cellule dans la grille
 * \param [in] j colonne de la cellule dans la grille
 * \return retourne une cellule initialiser a 1
*/

inline void set_vivante(int i, int j, grille g) {
  g.cellules[i][j] = 1;
}
/**
 * \brief initialise une cellule en cellule morte
 * \brief comme il s'agis avec une petite partie de code a implementer on peut le faire ici
 * \param [in] *g la grille que l'on utilise
 * \param [in] i ligne de la cellule dans la grille
 * \param [in] j colonne de la cellule dans la grille
 * \return retourne une cellule initialiser a 0
*/
// rend morte la cellule (i,j) de la grille g
inline void set_morte(int i, int j, grille g) {
  g.cellules[i][j] = 0;
}
/**
 * \brief initialise une cellule en cellule non viable
 * \brief comme il s'agis avec une petite partie de code a implementer on peut le faire ici
 * \param [in] g la grille que l'on utilise
 * \param [in] i ligne de la cellule dans la grille
 * \param [in] j colonne de la cellule dans la grille
 * \return retourne une cellule initialiser a -1
*/
inline void set_nonViable(int i, int j, grille g){
	g.cellules[i][j] = -1;
}

/**
 * \brief test si la cellule est vivante
 * \brief comme il s'agis avec une petite partie de code a implementer on peut le faire ici
 * \param [in] g la grille que l'on utilise
 * \param [in] i ligne de la cellule dans la grille
 * \param [in] j colonne de la cellule dans la grille
 * \return retourne un booleen qui dit vrai si elle est bien vivante
*/
// teste si la cellule (i,j) de la grille g est vivante
inline bool est_vivante(int i, int j, grille g) {
  return ((g.cellules[i][j] > 0)&&(g.cellules[i][j] <=8));
}

/**
* \brief test si une cellule est non viable
* \brief comme il s'agis d'une petite partie du code a implementer alors on peut le faire ici
* \param [in] g la grille que l'on utilise
* \param [in] i ligne de la cellule de la grille
* \param [in] j colonne de la cellule de la grille
* \return retourne un boolen qui dit vrai si la cellule est bien non viable
*/
inline bool est_nonViable(int i, int j , grille g){
	return g.cellules[i][j] == -1;
}

/**
 * \brief Fait la copie d'une grille gs vers une grille gd
 * \pre la precondition est dans le programme mais il faut s'assurer que les grilles
 * \pre est la même taille
 * \param [in] *gs il s'agis de la grille a copier
 * \param [in] *gd il s'agis de la grille qui va recevoir l'autre grille
 * \return retourne une grille
 */
// recopie gs dans gd (sans allocation)
void copie_grille(const grille *gs, grille *gd);

#endif // __GRILLE_H

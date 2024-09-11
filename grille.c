//
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grille.h"
 /**\file grille.c
 * \brief grille.c contient les fonctions qui vont allouer et initialiser la grille leurs prototypes se trouvent dans grille.h
 * \author Spitz chrsitopher
 *
 * Commentaire longs du fichier pouvant\n
 * s'étendre sur plusieurs lignes\n
 * à la suite.\n
 */





void alloue_grille(int l, int c, grille *g) {
	g->nbl=l;
	g->nbc=c;
	int i;
	 g->cellules = malloc(sizeof(int *)*l);
	if(g->cellules==NULL){
		printf("Pas assez de memoire \n");
		exit(1);
	}
	for(i=0;i<l;i++){
		g->cellules[i] = calloc(sizeof(int),c);
		if(g->cellules[i]==NULL){
			printf("pas assez de memoire\n");
			exit(1);
		}
	}
}

void libere_grille(grille *g) {
	int i;
	for(i=0;i<g->nbl;i++){
		free(g->cellules[i]);
	}
	free(g->cellules);

}


void init_grille_from_file(char const *const filename, grille *const g) {
  FILE *pfile = fopen(filename, "r");
  if (pfile == NULL) {
    fprintf(stderr,
            "Erreur (%s:%d): Lecture du fichier \"%s\" impossible (%s)\n",
            __FILE__, __LINE__ - 4, filename, strerror(errno));
    exit(EXIT_FAILURE);
  }

  int l, c;
  fscanf(pfile, "%d", &l);
  fscanf(pfile, "%d", &c);

  alloue_grille(l, c, g);

  int vivantes = 0;
  fscanf(pfile, "%d", &vivantes);
  for (int n = 0; n < vivantes; ++n) {
    fscanf(pfile, "%d", &l);
    fscanf(pfile, "%d", &c);
    set_vivante(l, c, *g);
  }
  int non_vivantes = 0;
  fscanf(pfile, "%d", &non_vivantes);
  for (int n = 0; n < non_vivantes; ++n) {
    fscanf(pfile, "%d", &l);
    fscanf(pfile, "%d", &c);
    set_nonViable(l, c, *g);
  }

  fclose(pfile);
  return;
}

void copie_grille(const grille *const gs, grille *const gd) {
  assert(gs->nbl == gd->nbl && gs->nbc == gd->nbc);
  for (int i = 0; i < gs->nbl; ++i)
    for (int j = 0; j < gs->nbc; ++j)
      gd->cellules[i][j] = gs->cellules[i][j];
}


extern inline bool est_vivante(int i, int j, grille g);
extern inline void set_vivante(int i, int j, grille g);
extern inline void set_morte(int i, int j, grille g);
extern inline bool est_nonViable(int i, int j, grille g);
extern inline void set_nonViable(int i, int j , grille g);




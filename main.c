// Chemin : /cygdrive/c/Users/CrSpi/OneDrive/Bureau/FAC_MI_L2/FAC_MI_L2_S3P/TechDev

#include <stdio.h>
#include <stdlib.h>

#include "grille.h"
#include "io.h"
#include "jeu.h"


int main (int argc, char **argv){
  if (argc != 2) {
    printf("Usage : %s <fichier grille>\n", argv[0]);
    return 1;
  }
  grille g, gc,g_oscille;
  init_grille_from_file(argv[1], &g);
  alloue_grille(g.nbl, g.nbc, &gc);
  affiche_grille(&g);
  debut_jeu(&g, &gc,&g_oscille);

  libere_grille(&g);
  libere_grille(&gc);


  return EXIT_SUCCESS;
}

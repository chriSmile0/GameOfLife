#include "io.h"
#include <stdio.h>

/**\file io.c
 * \brief io.c contient les fonctions implementés et 2 fonctions supplémentaires que sont affiche_trait et affiche_ligne et
 * \brief  les fonctions dont le prototype est dans io.h que l'on va implémentées ici
 * \author Spitz chrsitopher
 *
 * Commentaire longs du fichier pouvant\n
 * s'étendre sur plusieurs lignes\n
 * à la suite.\n
 */





static void affiche_trait(int c) {
  int i;
  for (i = 0; i < c; ++i)
    printf("|---");
  printf("|\n");
  return;
}







 void affiche_ligne(int c, int *ligne){
    for(int i=0;i<c;++i)
        if(ligne[i]==0) printf("|   ");
			else if(ligne[i]==-1) printf("|  X");

        else printf("| %d ",ligne[i]);


    printf("|\n");
}




 void affiche_grille_cairo(cairo_surface_t *surface, const grille *g, int vieillissement){
	 int i=0;
	 int j=0;
	 int px=0;
	 int py=0;
	 cairo_t *cr;
	 cr = cairo_create(surface);
	 for(i=0;i<g->nbl;i++){
		 py+=50;
		 for(j=0;j<g->nbc;j++){
		px+= 50;
		cairo_rectangle(cr,px,py,50,50);
		cairo_set_source_rgb (cr, 0.0, 1.0, 0.0);
		cairo_fill(cr);
		cairo_rectangle(cr,px,py,50,50);
		cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
		cairo_stroke(cr);
		if(g->cellules[i][j]==-1){
                    cairo_set_source_rgb(cr,1.0,0.0,0.0);
                    cairo_move_to(cr,px+5,py+5);
                    cairo_line_to(cr,px+45,py+45);
                    cairo_move_to(cr,px+45,py+5);
                    cairo_line_to(cr,px+5,py+45);
                    cairo_set_line_width(cr,2);
                    cairo_stroke(cr);
            }
           else if((g->cellules[i][j]==1)||(vieillissement && (g->cellules[i][j]>0)&&(g->cellules[i][j]<8))){
                    cairo_set_source_rgb (cr, 0.0,0.0,1.0);
                    cairo_arc(cr,px+25,py+25,10.,0.,2 * M_PI);
                    cairo_fill(cr);
                    
            }
		}
		px=0;
	 }

 }
void affiche_grille(const grille *g) {
  printf("\n");
  int l=g->nbl;
  int c=g->nbc;
  affiche_trait(c);
  for (int i = 0; i < l; ++i) {
    affiche_ligne(c, g->cellules[i]);
    affiche_trait(g->nbc);
  }
  printf("\n");
  return;
}



void efface_grille(const grille *g) { printf("\n\e[%dA", g->nbl * 2 + 5); }





void debut_jeu(grille *g, grille *gc,*_g_oscille){
  int evolution_max=200; // on défini une évolution maximum de notre grille a 200//
  int oscille =0;//booleen pour l'oscillation//
  int c = getchar();
  char  string[100];
  int i=0;//compteur pour l'evolution//
  int t=0;//temps de périodicité//
  int l=0; //variable pour les lignes d'une grille//
  int d=0;//variable  pour les colonnes d'une grille//
  int p=0;// la periode d'une grille//
  compte_voisins_vivants = compte_voisins_vivants_c;//le pointeur compte_voisins vivants vers la fonction cyclique ou la non cyclique//
    int vieillissement=0;//booleen pour le vieillissement//
  while (c != 'q') { // touche 'q' pour quitter
    switch (c) {

    case '\n': { // touche "entree" pour évoluer
	  printf("Le temps d'évolution est : %d ",++i);
      evolue(g, gc,vieillissement);
      efface_grille(g);
      affiche_grille(g);
      break;
    }

   case 'n' : { //touche n pour demander une nouvelle grille //
	   //getchar();
	   printf("\e[2J\n");
	   libere_grille(g);
	   libere_grille(gc);
	   i=0;
	   printf("Entrer une nouvelle grille \n");
	   scanf("%s",string);
	   init_grille_from_file(string,g);
	   init_grille_from_file(string,gc);
	   printf("Le temps d'évolution est : %d ",++i);
	   affiche_grille(g);
    break;
   }
   case 'c' : {  //touche c pour activer/desactiver le compte voisins cyclique//

	   if(compte_voisins_vivants==compte_voisins_vivants_c){
		   compte_voisins_vivants = compte_voisins_vivants_nc;
		}
		else {
			compte_voisins_vivants = compte_voisins_vivants_c;
		}
		break;
	}

	case 'v' : {// touche v pour activer/desactiver le veillissement//
		if(vieillissement==1){
                vieillissement=0;
		}
		else {
		    vieillissement=1;
		}
		break;
	}
	/*case 'o' : {//touche pour activer le test d'oscillation//
	    if(oscille==0){oscille =1;}
        if((oscille==1)&&(vieillissement==0)){
            if(test_oscille==0){
                alloue_grille(g->nbl,g->nbc,g_oscille);
                copie_grille(g,g_oscille);
                test_oscille=1;
            }
            else {
                if((test_oscille==1) && (evolution_max<200){
                    for(l=0;l<g->nbl;l++){
                        for(d=0;d<g->bnc;c++){
                            if(g->cellules[l][d] !=g_oscille->cellules[l][d]){t++};
                        }
                    }
                if(t==0){//la grille
                    test_oscille=2;
                }
                p++;
                }
            }
        }
        else if((oscille==1)&&(vieillissement==1){
                if(test_oscille==0){
                    alloue_grille(g->nbl,g->nbc,g_oscille);
                    copie_grille(g,g_oscille);
                    test_oscille=1;
                }
                else {
                    if((test_oscille==1)&& (evolution_max<200))
                }
        }

	    break;
	}*/

    default: { // touche non traitée
      printf("\n\e[1A");
      break;
    }
    }
    c = getchar();
  }
  return;
}

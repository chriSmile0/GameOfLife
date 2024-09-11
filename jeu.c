#include "jeu.h"
#include <stdio.h>

/**\file jeu.c
 * \brief jeu.c contient les fonctions implementées qui comportent leurs prototypes dans jeu.h
 * \author Spitz chrsitopher
 *
 * Commentaire longs du fichier pouvant\n
 * s'étendre sur plusieurs lignes\n
 * à la suite.\n
 */



int compte_voisins_vivants_c(int i, int j, grille g){//cyclique
	int v = 0, l=g.nbl, c = g.nbc;
	v+= est_vivante(modulo(i-1,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i-1,l),modulo(j,c),g);
	v+= est_vivante(modulo(i-1,l),modulo(j+1,c),g);
	v+= est_vivante(modulo(i,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i,l),modulo(j+1,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j+1,c),g);

	return v;
}


int compte_voisins_vivants_nc(int i, int j, grille g){
	int v = 0, l=g.nbl, c = g.nbc;
	if(i==0 && j==0)
	{
		v+= est_vivante(i+1,j,g);
		v+= est_vivante(i,j+1,g);
		v+= est_vivante(i+1,j+1,g);
	}
	else if(i==l-1 && j==0)
	{
		v+= est_vivante(i-1,j,g);
		v+= est_vivante(i-1,j+1,g);
		v+= est_vivante(i,j+1,g);
	}
	else if(i==l-1 && j==c-1)
	{
		v+= est_vivante(i-1,j,g);
		v+= est_vivante(i-1,j-1,g);
		v+= est_vivante(i,j-1,g);
	}
	else if(i==0 && j==c-1)
	{
		v+= est_vivante(i,j-1,g);
		v+= est_vivante(i+1,j-1,g);
		v+= est_vivante(i+1,j,g);
	}
	else if(j==0 && i>0 && i<l-1)
	{
		v+= est_vivante(i-1,j,g);
		v+= est_vivante(i-1,j+1,g);
		v+= est_vivante(i,j+1,g);
		v+= est_vivante(i+1,j+1,g);
		v+= est_vivante(i+1,j,g);
	}
	else if(j==c-1 && i>0 && i<l-1)
	{
		v+= est_vivante(i-1,j,g);
		v+= est_vivante(i-1,j-1,g);
		v+= est_vivante(i,j-1,g);
		v+= est_vivante(i+1,j-1,g);
		v+= est_vivante(i+1,j,g);
	}
	else if(i==0 && j>0 && j<c-1)
	{
		v+= est_vivante(i,j-1,g);
		v+= est_vivante(i+1,j-1,g);
		v+= est_vivante(i+1,j,g);
		v+= est_vivante(i+1,j+1,g);
		v+= est_vivante(i,j+1,g);
	}
	else if(i==l-1 && j>0 && j<c-1)
	{
		v+= est_vivante(i,j-1,g);
		v+= est_vivante(i-1,j-1,g);
		v+= est_vivante(i-1,j,g);
		v+= est_vivante(i-1,j+1,g);
		v+= est_vivante(i,j+1,g);
	}
	else
	{
		v+= est_vivante(i-1,j-1,g);
		v+= est_vivante(i-1,j,g);
		v+= est_vivante(i-1,j+1,g);
		v+= est_vivante(i,j-1,g);
		v+= est_vivante(i,j+1,g);
		v+= est_vivante(i+1,j-1,g);
		v+= est_vivante(i+1,j,g);
		v+= est_vivante(i+1,j+1,g);
	}
	return v;
}






/*int config_suivante(grille *g,grille *aussi){
    int b=0; //booleen pour savoir si elle oscille//
    int i,j,p;
    int temps=0;//entier pour savoir au bout de combien de temps elle revient sur elle meme//
	int vieillissement=0;
	alloue_grille(g->nbl,g->nbc,aussi);
	copie_grille(g,aussi);
    evolue(g,aussi,vieillissement);
	for(i=0;i<g->nbl;i++){
        for(j=0;j<g->nbc;j++){

            if(g->cellules[i][j] != aussi->cellules[i][j]){
                temps++;
            }
        }
	}



return temps;
}*/





void evolue (grille *g, grille *gc, int vieillissement){
	copie_grille (g,gc); // copie temporaire de la grille
	int i,j,l=g->nbl, c = g->nbc,v;
	for (i=0; i<l; i++)
	{
		for (j=0; j<c; ++j)
		{
			v = (*compte_voisins_vivants)(i, j, *gc);
			if (est_vivante(i,j,*g))
			{ // evolution d'une cellule vivante
			    if (( v!=2 && v!= 3 )|| (g->cellules[i][j]==8 && vieillissement)) set_morte(i,j,*g);//devient morte sinon on ne touche pas et elle reste a 0 sur la grille donc t = t+1
				else if(((v==3) || (v==2)) && vieillissement && (g->cellules[i][j]<8)&&(g->cellules[i][j]!=-1)) g->cellules[i][j]++;
				//else if(((v==3) || (v==2)) && (!vieillissement)) set_vivante(i,j,*g);
				}

			else if(!est_nonViable(i,j,*g))

			{ // evolution d'une cellule morte
				if ( v==3 ) set_vivante(i,j,*g);
			}
		}
	}
	return;
}

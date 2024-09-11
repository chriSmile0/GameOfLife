#include <stdio.h>
#include <stdlib.h>

#include "grille.h"
#include "io.h"
#include "jeu.h"

#include <cairo/cairo.h>
#include <cairo/cairo-xlib.h>
#include <X11/Xlib.h>

#define SIZEX 1200
#define SIZEY 1200

int main (int argc, char *argv[]){
	int vieillissement = 0;
	int i=0;
	char string[100];
	compte_voisins_vivants = compte_voisins_vivants_c;
	// X11 display
	Display *dpy;
	Window rootwin;
	Window win;
	XEvent e;
	int scr;

	// init the display
	if(!(dpy=XOpenDisplay(NULL))) {
		fprintf(stderr, "ERROR: Could not open display\n");
		exit(1);
	}

	scr=DefaultScreen(dpy);
	rootwin=RootWindow(dpy, scr);

	win=XCreateSimpleWindow(dpy, rootwin, 1, 1, SIZEX, SIZEY, 0,
			BlackPixel(dpy, scr), BlackPixel(dpy, scr));

	XStoreName(dpy, win, "jeu de la vie");
	XSelectInput(dpy, win, ExposureMask|ButtonPressMask|KeyPressMask);
	XMapWindow(dpy, win);

	// create cairo surface
	cairo_surface_t *cs;
	cs=cairo_xlib_surface_create(dpy, win, DefaultVisual(dpy, 0), SIZEX, SIZEY);

	// run the event loop
	grille g, gc;
	init_grille_from_file(argv[1],&g);
	alloue_grille(g.nbl, g.nbc, &gc);
	while(1) {
		XNextEvent(dpy, &e);
		
			if(e.type==Expose && e.xexpose.count<1) {
					affiche_grille_cairo(cs,&g,vieillissement);
				}
			if(e.type==ButtonPress && e.xbutton.button == Button1){
				evolue(&g,&gc,vieillissement);
				affiche_grille_cairo(cs,&g,vieillissement);
			}
			if(e.type==ButtonPress && e.xbutton.button==Button3) break;
			
			 if(e.type==KeyPress){
				if(e.xkey.keycode == XKeysymToKeycode(dpy,'n')){
					printf("Entrer une nouvelle grille : ");
					scanf("%s",string);
					i=0;
					libere_grille(&g);
					libere_grille(&gc);
					init_grille_from_file(string,&g);
					//init_grille_from_file(string,&gc);
					printf("Le temps d'évolution est %d",++i);
					affiche_grille_cairo(cs,&g,vieillissement);
				}
				 if(e.xkey.keycode == XKeysymToKeycode(dpy,'c')){
					 if(compte_voisins_vivants==compte_voisins_vivants_c){
						compte_voisins_vivants = compte_voisins_vivants_nc;
						}
					else {
					compte_voisins_vivants = compte_voisins_vivants_c;
					}
				}
				else if(e.xkey.keycode == XKeysymToKeycode(dpy,'v')){
					if(vieillissement==1){
						vieillissement=0;
					}
					else {
						vieillissement=1;
					}
				}
			}
			
		

	
			
		  if(e.type==ButtonPress && e.xbutton.button==Button3) break;
	  }
	

	cairo_surface_destroy(cs); // destroy cairo surface
	XCloseDisplay(dpy); // close the display
return 0;
}



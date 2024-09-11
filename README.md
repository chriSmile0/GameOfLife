Pour le versionnage j'ai fait l'étiquette 1.0 pour le niveau 1 et 2,
la 2.0 pour le niveau 3
la 3.0 pour le niveau 4
et le 4.0 pour le rendu final



La touche n permet d'entrer une nouvelle grlle
la touche c activer/desactiver le fait de faire le comptage cyclique ou non des voisins
la touche \n faire évoluer la grille
la touche v va activer ou désactiver le vieillissement des cellules


Le Makefile a était modifié pour pouvoir switcher entre l'affichage de la grille en mode graphique ou en mode texte

La fonction affiche_grille_cairo permet d'afficher la grille avec tout les cas (vieillissement et cyclique ).
Les cercles remplis de noirs sont les cases qui sont vivantes, la croix rouge représente une cellule non viable
J'avait aussi l'idée de changer la couleur du blanc vers le noir au fur et à mesure que la cellule vieilli si le mode vieillissement est activé

Finalement je le niveau 4 est bien terminé et fonctionne très bien.

Pour ce qui est du Niveau 5 j'ai implementer en commentaire des esquisses de ce que je pouvait faire pour ce niveau , mais je n'est pas ce qui 
faut pour implementer cairo hors de la fac donc pour ne pas chambouler le code du niveau 4 et pour eviter de faire buguer le programme a la compilation 
je préfère finir sur quelque chose qui compile et qui fonctionne très bien.


Si je peut donner un avis sur la bibliothèque cairo et la Xlib je dirait que celà est très interessant et utilise un peu près les memes commandes 
que lorsque nous faisons de la programmation web donc celà m'a aider pour l'utiliser. Le soucis serait qui faut bien chercher sur les autres systèmes 
d'exploitation que les système Unix pour pouvoir utiliser cairo et Xlib ce qui est un peu dommage quand on utilise pas Linux.

Si je devais faire une conclusion sur ce projet je dirais que cela était instructif de voir tout ce qu'on peut faire avec le langage C mais 
qu'il faut aussi beaucoup de fonctions pour implementer un jeu comme ça. Meme si la version que nous avons implementer est assez petite et basique 
par rapport a tout ce qu'on peut faire avec le jeu de la vie , quand on voit tout les dessins possibles et tout les algorithmes possible de ce jeu ,
on peut dire que celà mériterait de faire un jeu de la vie plus complexe dans un semestre plus avancé car le jeu de la vie est composé d'algorithmes
très interessant quand on y regarde de plus pret.

Ma conclusion sur mes difficultés serait de dire que le C n'est pas vraiment mon langage préféré et que l'utilisation des pointeurs n'est pas mon fort
mais je m'en suis plutot bien sortit même si au final je ne peut pas finir le projet , je suis quand même content d'etre arrivé au niveau 4 et de l'avoir 
terminé car ce n'était pas vraiment gagner. J'ai eu du mal a commencer , et aussi du mal avec mon git , c'est même pour celà que mon 1er rendu 
n'est peut etre pas très coherent avec mon depot git. Ce projet n'a pas était de tout repos pour moi car j'ai preferer me concentrer sur les rendus 
d'une autre matière , on va dire que le temps m'a un peu manqué sur ce projet et que je n'est pas fait le necessaire pour pouvoir faire le 
projet chez moi jusqu'au bout. C'est dommage j'aurait preferer le finir et viser une note maximale mais pas grave je vais redoubler d'effort sur le reste.
#ifndef INTERFACE_H
#define INTERFACE_H

#include "../obj/carte.h"
#include "../obj/plateau.h"
#include "../obj/structures.h"


/*
Requires : Un plateau bien défini
Assigns : /
Ensures : Renvoie un tableau dans lequel on retrouve quelles cartes il veut garder ou non et affiche le mulligan
 */
void print_mulligan(Plateau p, int tab[3]);

/*
Requires : Un plateau bien défini
Assigns : Un tableau de 3 int.
Ensures : Affiche la fin du mulligan
 */

void print_fin_mulligan(Plateau);

/*
Requires : Deux plateaux bien définis, pour récupérer l'entier tour.
Assigns : /
Ensures : Affiche un message qui signal qu'un nouveau tour commence, avec toutes les informations utiles.
 */

void nouveau_tour(Plateau,Plateau);

/*
Requires : Un entier si cet entier est pair on sait que c'est l'ENSIIE A qui doit faire sa phase, sinon c'est l'ENSIIE B.
Assigns : /
Ensures : Affiche un message signifiant qu'une nouvelle phase commence à l'ENSIIE associée.
*/

void nouvelle_phase(int);


/*
Requires : Un plateau bien défini, pour récupérer toutes les informations utiles.
Assigns : /
Ensures : Affiche le plateau et plus particulièrement : les DD, les PE, le deck, la main, la défausse.
 */

void affichage_plateau(Plateau);

/*
Requires : /
Assigns : /
Ensures : Demande à un joueur qui reçoit une carte Elève s'il souhaite ajouter une carte FISE ou FISA et renvoie l'entier associé à FISE ou FISA.
*/

int fise_fisa();

/*
Requires : Un plateau correctement défini pour avoir accès à la main.
Assigns : /
Ensures : Demande au joueur de choisir une carte de sa main et renvoie l'entier associé à la bonne carte.
 */

int choix_carte(Plateau);

/*
Requires : Deux plateaux correctement définis, les deux plateaux indiquant les DD respectifs des deux ENSIIE.
Assigns : /
Ensures : Affiche le gagnant ou l'égalité (égalité si les deux ENSIIE dépassent les 20 DD au même moment et ont le même nombre de DD, ou si après 30 tours il n'y a pas de gagnant).
 */
 void victoire_egalite(Plateau, Plateau);

 #endif

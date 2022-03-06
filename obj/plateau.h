#ifndef PLATEAU_H
#define PLATEAU_H

#include "carte.h"
#include "structures.h"

struct Plateau{
    stack deck;
    stack pile_fise;
    stack pile_fisa;
    stack defausse;
    queue main;
    queue file_personnel;
    int tour;
    int energie;
    int pt_dvpt_durable;
    int times_played_repas_vegetarien;
    int times_played_zeros_papier;
};

typedef struct Plateau Plateau;

/* 
Requires : nothing
Assigns : nothing
Ensures : Retourne un nouveau plateau, le décalage sert pour mélanger le deck, en prenant deux décalages différent, on aura ainsi deux mélanges différents
*/
Plateau new_plateau(int decalage);

/* 
Requires : nothing
Assigns : Le plateau
Ensures : Libère l'espace mémoire dédié au plateau
*/
void free_plateau(Plateau* p);

/* 
Requires : nothing
Assigns : le plateau, et plus précisément, son compteur de tour, les espaces disponibles pour les cartes personnel, et les cartes fisa
Ensures : La fonction signifie au plateau qu'un nouveau tour commence, elle, incrémente donc son nombre de tour, et si celui ci est impair,
alors il activera les cartes fisa, sinon il les désactivera, de plus si le tour est le n° 6 ou 11, alors le plateau gagnera un espace supplémentaire de carte personnel.
Cette fonction initialise les points d'énergie du plateau en fonction du nombre de cartes fises et fisas.*/
void new_tour(Plateau* p);

/* 
Requires : nothing
Assigns : nohting
Ensures : Retourne le nombre de cartes que l'ensiie doit piocher au début de sa phase, en fonction des cartes présentes sur le plateau.
*/
int nbr_cards_drawn(Plateau p);

/* 
Requires : nothing
Assigns : la main et le deck du plateau
Ensures : Retire une carte du deck et la place dans la main.
*/
void draw(Plateau* p);

/**
* \brief Calculer combien de cartes \b Elèves une ENSIIE recevra au début de sa phase
* \param p Un plateau
* \return Le nombre de cartes \b Elèves une ENSIIE recevra au début de sa phase
*/
int nbr_carte_eleve(Plateau p);

/**
* \brief Ajouter une carte \b Elèves de type \b FISE au plateau de jeu d'une ENSIIE
* \param p Un plateau*
* \return Rien
*/
void ajoute_carte_FISE(Plateau* p);

/**
* \brief Ajouter une carte \b Elèves de type \b FISA au plateau de jeu d'une ENSIIE
* \param p Un plateau*
* \return Rien
*/
void ajoute_carte_FISA(Plateau* p);

/**
* \brief Calculer le nombre de PE(Points d'énergie) disponible par une ENSIIE
* après avoir posé sa ou ses nouvelles cartes \b Elèves
* \param p Un plateau, et c Une carte
* \return le nombre de PE disponible par une ENSIIE
*/
int nb_PE(Plateau p, Carte c);

/**
* \brief Permetre à une ENSIIE de jouer une carte de sa main
* \param p Un plateau*
* \return Rien
*/
void jouer_cart_main(Plateau* p1, Plateau* p2, int num_carte, int quelle_ensiie);

/**
* \brief Signifier au plateau que le tour est terminé
* \attention Elle permettra de faire le calcul des DD gagnés par chaque ENSIIE 
* à la fin du tour
* \param p1, p2 Deux plateaux
* \return Rien
*/
void tour_terminer(Plateau* p1, Plateau* p2);

/**
* \brief Déterminer si la partie est finie, et si oui si un jouer a gagné ou s'il y a égalité
* \param p1, p2 Deux plateaux
* \return Rien
*/
int est_partie_finie(Plateau p1, Plateau p2);


/* 
Requires : nothing
Assigns : nohting
Ensures : retourne le deck du plateau fournit en argument.
*/
stack get_deck(Plateau p);

/* 
Requires : nothing
Assigns : nohting
Ensures : retourne la main du plateau fournit en argument.
*/
queue get_main(Plateau p);

/* 
Requires : nothing
Assigns : nohting
Ensures : retourne le nombre de places pour les cartes personnel sur le plateau passé en argument, soit 1, 2 ou 3. 
Attention : il ne retourne pas le nombre de places restantes !
*/
int get_places_personnel(Plateau p);

/* 
Requires : nothing
Assigns : nohting
Ensures : retourne le nombre de places restantes pour le personnel sur le plateau passé en argument.
*/
int get_places_personnel_restantes(Plateau p);

/* 
Requires : nothing
Assigns : nohting
Ensures : retourne 1 si c'est un tour impair et 0 sinon.
*/
int is_tour_impair(Plateau p);

/* 
Requires : nothing
Assigns : nohting
Ensures : retourne la défausse du plateau fournit en argument.
*/
stack get_defausse(Plateau p);

/* 
Requires : nothing
Assigns : nohting
Ensures : retourne la pile des cartes fise du plateau fournit en argument.
*/
stack get_pile_fise(Plateau p);

/* 
Requires : nothing
Assigns : nohting
Ensures : retourne la pile des cartes fisa du plateau fournit en argument.
*/
stack get_pile_fisa(Plateau p);

/* 
Requires : nothing
Assigns : nothing
Ensures : retourne l'énergie restante sur le plateau fournit en argument.
*/
int get_energie(Plateau p);

void setEnergie(Plateau* p);
int valeur_developpement_fise_p1(Plateau p1, Plateau p2);
int valeur_durabilite_fise_p1(Plateau p1, Plateau p2);
int valeur_developpement_fise_p2(Plateau p1, Plateau p2);
int valeur_durabilite_fise_p2(Plateau p1, Plateau p2);
int valeur_developpement_fisa_p1(Plateau p1, Plateau p2);
int valeur_durabilite_fisa_p1(Plateau p1, Plateau p2);
int valeur_developpement_fisa_p2(Plateau p1, Plateau p2);
int valeur_durabilite_fisa_p2(Plateau p1, Plateau p2);

#endif
/*
Requires : le tableau de taille 3 contient à la case i un 0 si l'utilisateur veut garder la ième carte de sa main et un 1 s'il veut renvoyer cette carte dans son deck.
Assigns : Le plateau du joueur, et plus précisément sa main ainsi que son deck
Ensures : Renvoie dans le deck toutes les cartes que l'utilisateur ne voulait pas garder, puis mélange le deck, puis pioche autant de cartes qu'il en a renvoyé.
*/
void mulligan(int tab[3], Plateau* p);
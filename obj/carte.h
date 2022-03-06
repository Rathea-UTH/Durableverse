#ifndef CARTE_H
#define CARTE_H
typedef struct Carte Carte;

/* 
Requires : nothing
Assigns : nothing
Ensures : retourne le cout de la carte
*/
int get_cout_carte(Carte c);

/* 
Requires : nothing
Assigns : nothing
Ensures : retourne le type de la carte
*/
char get_type_carte(Carte c);

/* 
Requires : nothing
Assigns : nothing
Ensures : retourne le nombre d'exemplaire de la carte passée en argument présentes dans le deck au départ
*/
int get_nb_debut(Carte c);

struct Carte {
    char* nom;
    char type; // a = action, e = élève et p = personnel
    int pt_dvp;
    int pt_dur;
    int cout; //Il vaudra 0 pour les cartes élèves qui n'ont pas de cout.
    int effets[12];
    int is_fise; //Il vaudra 1 pour les cartes élèves fises, et 0 pour les cartes élèves fisa et les autres cartes.
    int nb_depart; //Il vaudra 0 pour les cartes élèves, 1 pour les cartes personnel et vaudra 1, 2, 3 ou 4 pour les cartes actions.
    int numero;
};

Carte Thomas_Lim;
Carte Marie_Szafranski;
Carte Alain_Faye;
Carte Christophe_Mouilleron;
Carte Stefania_Dumbrava;
Carte Julien_Forest;
Carte Nicolas_Brunel;
Carte Laurence_Bourard;
Carte Dimitri_Watel;
Carte Vitera_Y;
Carte Kevin_Goilard;
Carte Vincent_Jeannas;
Carte Massinissa_Merabet;
Carte Anne_Laure_Ligozat;
Carte Catherine_Dubois;
Carte Eric_Lejeune;
Carte Christine_Mathias;
Carte Katrin_Salhab;
Carte Abass_Sagna;
Carte Laurent_Prevel;

Carte Cours_Developpement_Durable;
Carte Recrutement;
Carte Rentree_Fise;
Carte Rentree_Fisa;
Carte Energie_Verte;
Carte Diplomation;
Carte Decharge;
Carte Recyclage;
Carte Zero_papier;
Carte Repas_vegetarien;
Carte Fermeture_annuelle;


Carte Fisa;
Carte Fise;
#endif
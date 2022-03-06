#include "carte.h"

/*struct Carte {
    char* nom;
    char type; //le type vaut 'a' si c'est une action, 'e' si c'est un élève, et 'p' si c'est un personnel
    void* attributs_speciaux; //attributs_speciaux sera les attributs d'un eleve d'un personnel ou d'une action 
};

struct AttributsEleve {
    int is_fise; //vaut 1 si c'est un fise et 0 si c'est un fisa.
    int pt_dvp;
    int pt_dur;
};

struct AttributsAction {
    int cout;
    int nb_depart;
};

struct AttributsPersonnel {
    int cout;
    int effets[12];
}; 
*/

/* 
Le tableau effets contient les valeurs pour chaque effet possible(il y en a 12 différents). Si une carte ne possède pas l'effet AE1 par exemple, alors effets[0] sera égal à 0.
Les effets sont classés dans l'ordre suivant : 
0 - AE1         6 - RA1
1 - AE2         7 - RA2
2 - AA1         8 - ADD
3 - AA2         9 - RDD
4 - RE1         10 - DR
5 - RE2         11 - E
*/

/*typedef struct AttributsPersonnel AttributsPersonnel;
typedef struct AttributsEleve AttributsEleve;
typedef struct AttributsAction AttributsAction;
*/
int get_cout_carte(Carte c){
    if (c.type == 'e')
        return 0; //les cartes élèves n'ont pas de coût
    return c.cout;
}

char get_type_carte(Carte c){
    return c.type;
}

int get_nb_debut(Carte c){
    return c.nb_depart;
}

Carte Thomas_Lim = { "Thomas Lim", 'p', 0, 0, 3, {1,0,0,0,0,0,0,0,0,0,0,0}, 0, 1,1};
Carte Marie_Szafranski = {"Marie Szafranski", 'p', 0, 0, 3, {0,1,0,0,0,0,0,0,0,0,0,0}, 0, 1,2};
Carte Alain_Faye = {"Alain Faye", 'p', 0, 0, 3, {0,0,1,0,0,0,0,0,0,0,0,0}, 0, 1,3};
Carte Christophe_Mouilleron = {"ChristopheMouilleron", 'p', 0, 0, 3, {0,0,0,1,0,0,0,0,0,0,0,0}, 0, 1,4};
Carte Stefania_Dumbrava = {"Stefania Dumbrava", 'p', 0, 0, 3, {0,0,0,0,1,0,0,0,0,0,0,0}, 0, 1,5};
Carte Julien_Forest = {"Julien Forest", 'p', 0, 0, 3, {0,0,0,0,0,1,0,0,0,0,0,0}, 0, 1,6};
Carte Nicolas_Brunel = {"Nicolas Brunel", 'p', 0, 0, 3, {0,0,0,0,0,0,1,0,0,0,0,0}, 0, 1,7};
Carte Laurence_Bourard = {"Laurence Bourard", 'p', 0, 0, 3, {0,0,0,0,0,0,0,1,0,0,0,0}, 0, 1,8};
Carte Dimitri_Watel = {"Dimitri Watel", 'p', 0, 0, 5, {1,0,1,0,0,0,0,0,0,0,0,0}, 0, 1,9};
Carte Vitera_Y = {"Vitera Y", 'p', 0, 0, 5, {0,1,0,1,0,0,0,0,0,0,0,0}, 0, 1,10};
Carte Kevin_Goilard = {"Kevin Goilard", 'p', 0, 0, 5, {0,0,0,0,1,0,1,0,0,0,0,0}, 0, 1,11};
Carte Vincent_Jeannas = {"Vincent Jeannas", 'p', 0, 0, 5, {0,0,0,0,0,1,0,1,0,0,0,0}, 0, 1,12};
Carte Massinissa_Merabet = {"Massinissa Merabet", 'p', 0, 0, 7, {0,0,0,0,0,0,0,0,0,0,2,0}, 0, 1,13};
Carte Anne_Laure_Ligozat = {"Anne-Laure Ligozat", 'p', 0, 0, 8, {0,0,0,0,0,0,0,0,2,0,1,1}, 0, 1,14};
Carte Catherine_Dubois = {"Catherine Dubois", 'p', 0, 0, 8, {0,0,0,0,0,0,0,0,0,2,1,1}, 0, 1,15};
Carte Eric_Lejeune = {"Eric Lejeune", 'p', 0, 0, 10, {1,1,0,0,0,1,0,0,0,1,0,0}, 0, 1,16};
Carte Christine_Mathias = {"Christine Mathias", 'p', 0, 0, 10, {0,0,1,1,0,0,0,1,0,1,0,0}, 0, 1,17};
Carte Katrin_Salhab = {"Katrin Salhab", 'p', 0, 0, 15, {2,2,0,0,0,0,0,0,0,0,0,1}, 0, 1,18};
Carte Abass_Sagna = {"Abass Sagna", 'p', 0, 0, 15, {0,0,2,2,0,0,0,0,0,0,0,1}, 0, 1,19};
Carte Laurent_Prevel = {"Laurent Prével", 'p', 0, 0, 20, {2,2,2,2,0,0,0,0,1,1,1,2}, 0, 1,20};

Carte Cours_Developpement_Durable = {"Cours Développement Durable", 'a', 0, 0, 2, {0,0,0,0,0,0,0,0,0,0,0,0}, 0, 3,21};
Carte Recrutement = {"Recrutement", 'a', 0, 0, 2, {0,0,0,0,0,0,0,0,0,0,0,0}, 0, 3,22};
Carte Rentree_Fise = {"Rentree Fise", 'a', 0, 0, 3, {0,0,0,0,0,0,0,0,0,0,0,0}, 0, 2,23};
Carte Rentree_Fisa = {"Rentree Fisa", 'a', 0, 0, 3, {0,0,0,0,0,0,0,0,0,0,0,0}, 0, 2,24};
Carte Energie_Verte = {"Energie Verte", 'a', 0, 0, 4, {0,0,0,0,0,0,0,0,0,0,0,0}, 0, 2,25};
Carte Diplomation = {"Diplomation", 'a', 0, 0, 5, {0,0,0,0,0,0,0,0,0,0,0,0}, 0, 2,26};
Carte Decharge = {"Decharge", 'a', 0, 0, 5, {0,0,0,0,0,0,0,0,0,0,0,0}, 0, 4,27};
Carte Recyclage = {"Recyclage", 'a', 0, 0, 10, {0,0,0,0,0,0,0,0,0,0,0,0}, 0, 1,28};
Carte Zero_papier = {"Zero papier", 'a', 0, 0, 10, {0,0,0,0,0,0,0,0,0,0,0,0}, 0, 1,29};
Carte Repas_vegetarien = {"Repas vegetarien", 'a', 0, 0, 10, {0,0,0,0,0,0,0,0,0,0,0,0}, 0, 1,30};
Carte Fermeture_annuelle = {"Fermeture annuelle", 'a', 0, 0, 10, {0,0,0,0,0,0,0,0,0,0,0,0}, 0, 1,31};


Carte Fisa = {"Fisa", 'e', 1, 1, 0, {0,0,0,0,0,0,0,0,0,0,0,0}, 0, 0,32};
Carte Fise = {"Fise", 'e', 1, 1, 0, {0,0,0,0,0,0,0,0,0,0,0,0}, 1, 0,33};

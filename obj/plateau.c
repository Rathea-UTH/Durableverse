#include "structures.h"
#include "carte.h"
#include "plateau.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

typedef Carte elem;

stack get_deck(Plateau p){
    return p.deck;
}

queue get_main(Plateau p){
    return p.main;
}

int get_places_personnel(Plateau p){
    if (p.tour < 6)
        return 1;
    if (p.tour < 11)
        return 2;
    return 3;
}

int get_places_personnel_restantes(Plateau p){
    return (get_places_personnel(p) - queue_length(p.file_personnel));
}

int is_tour_impair(Plateau p){
    return (p.tour%2);
}

stack get_defausse(Plateau p){
    return(p.defausse);
}

stack get_pile_fise(Plateau p){
    return p.pile_fise;
}

stack get_pile_fisa(Plateau p){
    return p.pile_fisa;
}

int get_energie(Plateau p){
    return p.energie;
}

//fonction qui renvoie un entier aléatoire
int random_(int decalage){
    srand(time(NULL)+decalage);
    return(rand());
}

//Fonction qui mélange le deck du plateau p
void shuffle_deck(Plateau* p, int decalage)
{
    int n = stack_length(p->deck);
    Carte* tab = malloc(n*sizeof(Carte));
    for (int i = 0; i < n; i += 1)
    {
        tab[i] = stack_pop(&(p->deck));
    }
    int a;
    elem tmp;
    for (int i = 0; i < n ; i+= 1)
    {
        a = random_(decalage)%(i+1);
        tmp = tab[a];
        tab[a] = tab[i];
        tab[i] = tmp;
    }
    for (int i = 0; i < n ; i+= 1)
    {
        stack_push(tab[i], &(p->deck));
    }
    free(tab);
}

Plateau new_plateau(int decalage)//Le décalage sert à ce que les mélanges des deux decks ne soient pas les mêmes.
{
    Plateau plateau;
    plateau.deck = create_stack();
    stack_push(Thomas_Lim, &(plateau.deck));
    stack_push(Marie_Szafranski, &(plateau.deck));
    stack_push(Alain_Faye, &(plateau.deck));
    stack_push(Christophe_Mouilleron, &(plateau.deck));
    stack_push(Stefania_Dumbrava, &(plateau.deck));
    stack_push(Julien_Forest, &(plateau.deck));
    stack_push(Nicolas_Brunel, &(plateau.deck));
    stack_push(Laurence_Bourard, &(plateau.deck));
    stack_push(Dimitri_Watel, &(plateau.deck));
    stack_push(Vitera_Y, &(plateau.deck));
    stack_push(Kevin_Goilard, &(plateau.deck));
    stack_push(Vincent_Jeannas, &(plateau.deck));
    stack_push(Massinissa_Merabet, &(plateau.deck));
    stack_push(Anne_Laure_Ligozat, &(plateau.deck));
    stack_push(Catherine_Dubois, &(plateau.deck));
    stack_push(Eric_Lejeune, &(plateau.deck));
    stack_push(Christine_Mathias, &(plateau.deck));
    stack_push(Katrin_Salhab, &(plateau.deck));
    stack_push(Abass_Sagna, &(plateau.deck));
    stack_push(Laurent_Prevel, &(plateau.deck));
    for (int i = 0; i < get_nb_debut(Cours_Developpement_Durable) ; i = i + 1)
    {
        stack_push(Cours_Developpement_Durable, &(plateau.deck));
    }
    for (int i = 0; i < get_nb_debut(Recrutement); i = i + 1)
    {
        stack_push(Recrutement, &(plateau.deck));
    }
    for (int i = 0; i < get_nb_debut(Rentree_Fise); i = i + 1)
    {
        stack_push(Rentree_Fise, &(plateau.deck));
    }
    for (int i = 0; i < get_nb_debut(Rentree_Fisa); i = i + 1)
    {
        stack_push(Rentree_Fisa, &(plateau.deck));
    }
    for (int i = 0; i < get_nb_debut(Energie_Verte); i = i + 1)
    {
        stack_push(Energie_Verte, &(plateau.deck));
    }
    for (int i = 0; i < get_nb_debut(Diplomation); i = i + 1)
    {
        stack_push(Diplomation, &(plateau.deck));
    }
    for (int i = 0; i < get_nb_debut(Decharge); i = i + 1)
    {
        stack_push(Decharge, &(plateau.deck));
    }
    for (int i = 0; i < get_nb_debut(Recyclage); i = i + 1)
    {
        stack_push(Recyclage, &(plateau.deck));
    }
    for (int i = 0; i < get_nb_debut(Zero_papier); i = i + 1)
    {
        stack_push(Zero_papier, &(plateau.deck));
    }
    for (int i = 0; i < get_nb_debut(Repas_vegetarien); i = i + 1)
    {
        stack_push(Repas_vegetarien, &(plateau.deck));
    }
    for (int i = 0; i < get_nb_debut(Fermeture_annuelle); i = i + 1)
    {
        stack_push(Fermeture_annuelle, &(plateau.deck));
    }
    plateau.main = empty_queue();
    plateau.file_personnel = empty_queue();
    plateau.pile_fise = create_stack();
    plateau.pile_fisa = create_stack();
    plateau.defausse = create_stack();
    plateau.tour = 0;
    plateau.energie = 0;
    plateau.pt_dvpt_durable = 0;
    plateau.times_played_repas_vegetarien = 0;
    plateau.times_played_zeros_papier = 0;
    shuffle_deck(&plateau, decalage);
    return plateau;
}

void free_plateau(Plateau* p)
{
    free_queue(&(p->file_personnel));
    free_queue(&(p->main));
    free_stack(&(p->deck));
    free_stack(&(p->defausse));
    free_stack(&(p->pile_fisa));
    free_stack(&(p->pile_fise));
}

void new_tour(Plateau* p)
{
    p->tour += 1;
}
void setEnergie(Plateau* p)
{
    p->energie = 0;
    p->energie += stack_length(p->pile_fise);
    if (is_tour_impair(*p))
    {
        p->energie += 2*stack_length(p->pile_fisa);
    }
}
int nbr_cards_drawn(Plateau p)
{
    Carte c;
    int result = 1;
    while(! is_empty_queue(p.file_personnel))
    {
        c = dequeue(&(p.file_personnel));
        result += c.effets[10];
    }
    return result;
}

int nbr_carte_eleve(Plateau p)
{
    Carte c;
    int result = 1;
    while(! is_empty_queue(p.file_personnel))
    {
        c = dequeue(&(p.file_personnel));
        result += c.effets[11];
    }
    return result;
}

void ajoute_carte_FISE(Plateau* p)
{
    stack_push(Fise,&(p->pile_fise));
}

void ajoute_carte_FISA(Plateau* p)
{
    stack_push(Fisa,&(p->pile_fisa));
}


void draw(Plateau* p){
    elem pioche = stack_pop(&(p->deck));
    enqueue(&(p->main),pioche);
}

int nb_PE(Plateau p, Carte c ){
    int energie = get_energie(p);
    int cout_carte = c.cout;
    return (energie-cout_carte);
}

int est_partie_finie(Plateau p1, Plateau p2){
    return ((p1.pt_dvpt_durable>20) || (p2.pt_dvpt_durable>20) || ((p1.tour>30) &&(p2.tour>30)));
}

int valeur_developpement_fise_p1(Plateau p1, Plateau p2){
    int result = 1;
    Carte c;
    while(! is_empty_queue(p1.file_personnel))
    {
        c = dequeue(&(p1.file_personnel));
        result += c.effets[0];
    }
    result += p1.times_played_zeros_papier;
    while(! is_empty_queue(p2.file_personnel))
    {
        c = dequeue(&(p2.file_personnel));
        result = result - c.effets[4];
    }
    if (result < 0)
    {
        return 0;
    }
    else
    {
        return result;
    }
}

int valeur_durabilite_fise_p1(Plateau p1, Plateau p2){
    int result = 1;
    Carte c;
    while(! is_empty_queue(p1.file_personnel))
    {
        c = dequeue(&(p1.file_personnel));
        result += c.effets[1];
    }
    result += p1.times_played_repas_vegetarien;
    while(! is_empty_queue(p2.file_personnel))
    {
        c = dequeue(&(p2.file_personnel));
        result = result - c.effets[5];
    }
    if (result < 0)
    {
        return 0;
    }
    else
    {
        return result;
    }
}

int valeur_developpement_fise_p2(Plateau p1, Plateau p2){
    int result = 1;
    Carte c;
    while(! is_empty_queue(p2.file_personnel))
    {
        c = dequeue(&(p2.file_personnel));
        result += c.effets[0];
    }
    result += p2.times_played_zeros_papier;
    while(! is_empty_queue(p1.file_personnel))
    {
        c = dequeue(&(p1.file_personnel));
        result = result - c.effets[4];
    }
    if (result < 0)
    {
        return 0;
    }
    else
    {
        return result;
    }
}

int valeur_durabilite_fise_p2(Plateau p1, Plateau p2){
    int result = 1;
    Carte c;
    while(! is_empty_queue(p2.file_personnel))
    {
        c = dequeue(&(p2.file_personnel));
        result += c.effets[1];
    }
    result += p2.times_played_repas_vegetarien;
    while(! is_empty_queue(p1.file_personnel))
    {
        c = dequeue(&(p1.file_personnel));
        result = result - c.effets[5];
    }
    if (result < 0)
    {
        return 0;
    }
    else
    {
        return result;
    }
}

int valeur_developpement_fisa_p1(Plateau p1, Plateau p2){
    int result = 1;
    Carte c;
    while(! is_empty_queue(p1.file_personnel))
    {
        c = dequeue(&(p1.file_personnel));
        result += c.effets[2];
    }
    result += p1.times_played_zeros_papier;
    while(! is_empty_queue(p2.file_personnel))
    {
        c = dequeue(&(p2.file_personnel));
        result = result - c.effets[6];
    }
    if (result < 0)
    {
        return 0;
    }
    else
    {
        return result;
    }
}

int valeur_durabilite_fisa_p1(Plateau p1, Plateau p2){
    int result = 1;
    Carte c;
    while(! is_empty_queue(p1.file_personnel))
    {
        c = dequeue(&(p1.file_personnel));
        result += c.effets[3];
    }
    result += p1.times_played_repas_vegetarien;
    while(! is_empty_queue(p2.file_personnel))
    {
        c = dequeue(&(p2.file_personnel));
        result = result - c.effets[7];
    }
    if (result < 0)
    {
        return 0;
    }
    else
    {
        return result;
    }
}

int valeur_developpement_fisa_p2(Plateau p1, Plateau p2){
    int result = 1;
    Carte c;
    while(! is_empty_queue(p2.file_personnel))
    {
        c = dequeue(&(p2.file_personnel));
        result += c.effets[2];
    }
    result += p2.times_played_zeros_papier;
    while(! is_empty_queue(p1.file_personnel))
    {
        c = dequeue(&(p1.file_personnel));
        result = result - c.effets[6];
    }
    if (result < 0)
    {
        return 0;
    }
    else
    {
        return result;
    }
}

int valeur_durabilite_fisa_p2(Plateau p1, Plateau p2){
    int result = 1;
    Carte c;
    while(! is_empty_queue(p2.file_personnel))
    {
        c = dequeue(&(p2.file_personnel));
        result += c.effets[3];
    }
    result += p2.times_played_repas_vegetarien;
    while(! is_empty_queue(p1.file_personnel))
    {
        c = dequeue(&(p1.file_personnel));
        result = result - c.effets[7];
    }
    if (result < 0)
    {
        return 0;
    }
    else
    {
        return result;
    }
}

int dd_supplementaire_gagne(Plateau p)
{
    int result = 0;
    Carte c;
    while(! is_empty_queue(p.file_personnel))
    {
        c = dequeue(&(p.file_personnel));
        result += c.effets[8];
    }
    return result;
}

int dd_retranche(Plateau p)
{
    int result = 0;
    Carte c;
     while(! is_empty_queue(p.file_personnel))
    {
        c = dequeue(&(p.file_personnel));
        result += c.effets[9];
    }
    return result;
}
void tour_terminer(Plateau* p1, Plateau* p2){
    int DD_retire_par_p1 = dd_retranche(*p1);
    int DD_retire_par_p2 = dd_retranche(*p2);
    int DD_gagne_par_p1=dd_supplementaire_gagne(*p1);
    int DD_gagne_par_p2=dd_supplementaire_gagne(*p2);
    int dvpt_all_fise_p1 = stack_length(p1->pile_fise) * valeur_developpement_fise_p1(*p1, *p2);
    int durabilite_all_fise_p1 = stack_length(p1->pile_fise) * valeur_durabilite_fise_p1(*p1, *p2);
    int dvpt_all_fise_p2 = stack_length(p2->pile_fise) * valeur_developpement_fise_p2(*p1, *p2);
    int durabilite_all_fise_p2 = stack_length(p2->pile_fise) * valeur_durabilite_fise_p2(*p1, *p2);
    int dvpt_all_p1 = dvpt_all_fise_p1;
    int durabilite_all_p1 = durabilite_all_fise_p1;
    int dvpt_all_p2 = dvpt_all_fise_p2;
    int durabilite_all_p2 = durabilite_all_fise_p2;
    if(is_tour_impair(*p1))
    {
        dvpt_all_p1 += stack_length(p1->pile_fisa) * valeur_developpement_fisa_p1(*p1, *p2);
        durabilite_all_p1 += stack_length(p1->pile_fisa) * valeur_durabilite_fisa_p1(*p1, *p2);
        dvpt_all_p2 += stack_length(p2->pile_fisa) * valeur_developpement_fisa_p2(*p1, *p2);
        durabilite_all_p2 += stack_length(p2->pile_fisa) * valeur_durabilite_fisa_p2(*p1, *p2);
    }
    if (dvpt_all_p1 - durabilite_all_p2 > 0)
    {
        DD_gagne_par_p1 += dvpt_all_p1 - durabilite_all_p2;
    }
    if (dvpt_all_p2 - durabilite_all_p1 > 0)
    {
        DD_gagne_par_p2 += dvpt_all_p2 - durabilite_all_p1;
    }
    if (DD_gagne_par_p1 - DD_retire_par_p2> 0)
    {
        DD_gagne_par_p1 = DD_gagne_par_p1 - DD_retire_par_p2;
    }
    else
    {
        DD_gagne_par_p1 = 0;
    }
    if (DD_gagne_par_p2 - DD_retire_par_p1> 0)
    {
        DD_gagne_par_p2 = DD_gagne_par_p2 - DD_retire_par_p1;
    }
    else
    {
        DD_gagne_par_p2 = 0;
    }
    p1->pt_dvpt_durable = p1->pt_dvpt_durable + DD_gagne_par_p1;
    p2->pt_dvpt_durable = p2->pt_dvpt_durable + DD_gagne_par_p2;
}

//Fonction qui va faire l'effet Cours de Developpement Durable (gagner 1 DD)
void play_Cours_Developpement_Durable(Plateau* p){
    p->pt_dvpt_durable += 1;
}
//Fonction qui va faire l'effet Recrutement (piocher une carte)
void play_Recrutement(Plateau* p){
    draw(p);
}
//Fonction qui va faire l'effet Rentree_FISE (mettre en jeu un élève FISE)
void play_Rentree_Fise(Plateau* p){
    ajoute_carte_FISE(p);
}
//Fonction qui va faire l'effet Rentree_FISA (mettre en jeu un élève FISA)
void play_Rentree_Fisa(Plateau* p){
    ajoute_carte_FISA(p);
}
//Fonction qui va faire l'effet Energie_Verte (gagner 6 PE)
void play_Energie_Verte(Plateau* p){
    p->energie = p->energie + 6;
}
//Fonction qui va faire l'effet Diplomation (retirer 1 FISE et 1 FISA à l'adversaire)
void play_Diplomation(Plateau* adversaire){
    if(!(is_stack_empty(adversaire->pile_fise))){
        stack_pop(&(adversaire->pile_fise));
    }
    if(!(is_stack_empty(adversaire->pile_fisa))){
        stack_pop(&(adversaire->pile_fisa));
    }
}
//Fonction qui va faire l'effet Decharge (mettre la première carte Personnel de l'adversaire dans la défausse)
void play_Decharge(Plateau* adversaire){
    if(!is_empty_queue(adversaire->file_personnel)){
    queue file_personnel =  adversaire->file_personnel;
    elem ajout_defausse = dequeue(&(file_personnel));
    stack_push(ajout_defausse,&(adversaire->defausse));
    }
}

//Fonction qui va faire l'effet Recyclage
void play_Recyclage(Plateau* p){
    while(!is_stack_empty(p->defausse)){
        elem defausse = stack_pop(&(p->defausse));
        stack_push(defausse,&(p->deck));
    }
    shuffle_deck(p,0);
}
//Fonction qui va faire l'effet Zeros Papier
void play_zeros_papier(Plateau* p){
    p->times_played_zeros_papier +=1;
}

//Fonction qui va faire l'effet Repas Vegetarien
void play_Repas_vegetarien(Plateau* p){
    p->times_played_repas_vegetarien +=1;
}

//Fonction qui va faire l'effet Fermeture Annuelle
void play_Fermeture_annuelle(Plateau* p1, Plateau* p2){
    while(!is_stack_empty(p1->pile_fise))
    {
        stack_pop(&(p1->pile_fise));
    }
    while(! is_stack_empty(p2->pile_fise))
    {
        stack_pop(&(p2->pile_fise));
    }
    while(! is_stack_empty(p1->pile_fisa))
    {
        stack_pop(&(p1->pile_fisa));
    }
    while(! is_stack_empty(p2->pile_fisa))
    {
        stack_pop(&(p2->pile_fisa));
    }
}

void jouer_cart_main(Plateau* p1, Plateau* p2, int num_carte, int quelle_ensiie)
{
    if(quelle_ensiie == 1)
    {
        if (num_carte < 0 || num_carte > queue_length(p1->main))
        {
            printf("► Vous venez de rentrer un numéro invalide. ◄\n");
            return;
        }
        Carte c = queue_enlever_i(num_carte, &(p1->main));
        if (get_cout_carte(c) <= get_energie(*p1))
        {
            if (get_type_carte(c) == 'p')
            {
                if(get_places_personnel_restantes(*p1) <= 0)
                {
                    //Alors la file de personnel est pleine
                    stack_push(dequeue(&(p1->file_personnel)), &(p1->defausse));
                }
                enqueue(&(p1->file_personnel), c);
            }
            else if (get_type_carte(c) == 'a')
            {
                switch (c.numero)
                {
                case 21:
                    play_Cours_Developpement_Durable(p1);
                    break;
                case 22:
                    play_Recrutement(p1);
                    break;
                case 23:
                    play_Rentree_Fise(p1);
                    break;
                case 24:
                    play_Rentree_Fisa(p1);
                    break;
                case 25:
                    play_Energie_Verte(p1);
                    break;
                case 26:
                    play_Diplomation(p2);
                    break;
                case 27:
                    play_Decharge(p2);
                    break;
                case 28:
                    play_Recyclage(p1);
                    break;
                case 29:
                    play_zeros_papier(p1);
                    break;
                case 30:
                    play_Repas_vegetarien(p1);
                    break;
                case 31:
                    play_Fermeture_annuelle(p1,p2);
                    break;
                default:
                    break;
                }
            }
        p1->energie -= get_cout_carte(c);
        }
        else
        {
             printf("► Vous tentez de jouer une carte qui coûte trop cher, veuillez saisir un autre numéro. ◄\n");
             enqueue(&(p1->main), c);
        }
    }
    else
    {
         if (num_carte < 0 || num_carte > queue_length(p2->main))
        {
            printf("► Vous venez de rentrer un numéro invalide. ◄\n");
            return;
        }
        Carte c = queue_enlever_i(num_carte, &(p2->main));
        if (get_cout_carte(c) <= get_energie(*p2))
        {
        if (get_type_carte(c) == 'p')
        {
            if( get_places_personnel_restantes(*p2) <= 0)
            {
                //Alors la file de personnel est pleine
                stack_push(dequeue(&(p2->file_personnel)), &(p2->defausse));
            }
            enqueue(&(p2->file_personnel), c);
        }
        else if (get_type_carte(c) == 'a')
        {
            switch (c.numero)
            {
            case 21:
                play_Cours_Developpement_Durable(p2);
                break;
            case 22:
                play_Recrutement(p2);
                break;
            case 23:
                play_Rentree_Fise(p2);
                break;
            case 24:
                play_Rentree_Fisa(p2);
                break;
            case 25:
                play_Energie_Verte(p2);
                break;
            case 26:
                play_Diplomation(p1);
                break;
            case 27:
                play_Decharge(p1);
                break;
            case 28:
                play_Recyclage(p2);
                break;
            case 29:
                play_zeros_papier(p2);
                break;
            case 30:
                play_Repas_vegetarien(p2);
                break;
            case 31:
                play_Fermeture_annuelle(p1,p2);
                break;
            default:
                break;
            }
        }
        p2->energie -= get_cout_carte(c);
        }
        else
        {
             printf("► Vous tentez de jouer une carte qui coûte trop cher, veuillez saisir un autre numéro. ◄\n");
             enqueue(&(p2->main), c);
        }
    }
}


void mulligan(int tab[3], Plateau* p)
{
    for (int i = 0; i < 3; i++)
    {
        if (tab[i])
        {
            draw(p);
        }
    }
    shuffle_deck(p, 15);
    for (int i = 0; i < 3; i++)
    {
        if (tab[i])
        {
            stack_push(queue_enlever_i(i,&(p->main)),&(p->deck));
        }
    }
}
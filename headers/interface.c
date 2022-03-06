#include <stdlib.h>
#include <stdio.h>
#include "interface.h"
#include "../obj/plateau.h"
#include "../obj/carte.h"


void print_mulligan(Plateau p, int renvoie[3]){
  int carteARenvoyer = -1;
  printf("╔════════════════════╗\n");
  printf("║ Début du Mulligan: ║\n");
  printf("╚════════════════════╝\n");
  printf("► Tapez '0' si vous voulez garder votre main ◄\n");
  printf("\n");
  printf("Voici votre main avec les numéros associés aux cartes:\n");
  printf("──────────────────────────────────────────────────────\n");
  printf("\n");
  printf("┌─────────────────────────────────────────────────────┐\n");
  printf("\n");
  queue hand = get_main(p);
  int taille_main = queue_length(hand);
    for(int i=1;i<=taille_main;i++){
      printf("  Tapez '%i' si vous ne voulez pas garder cette carte :\n", i );
      printf("  %s : ", lecture_queue(i,hand).nom);
      printf("  Type : %c ; ", get_type_carte(lecture_queue(i,hand)));
      printf("  Coût : %i ; ", get_cout_carte(lecture_queue(i,hand)));
      printf("\n");
      printf("\n");
    }
    printf("└─────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("\n");
  while(carteARenvoyer!=0){
    scanf("%d", &carteARenvoyer);
    if(carteARenvoyer==1 && renvoie[0]!=1){
      printf("┌──────────────────────────────────────────────────────────────┐\n");
      printf("Vous avez décidé de relancer la carte 1 !\n");
      printf("► Tapez '0' si vous voulez garder votre main ◄\n");
      printf("► Vous pouvez cependant choisir de retirer d'autres cartes ! ◄\n");
      printf("└──────────────────────────────────────────────────────────────┘\n");
      printf("\n");
      renvoie[0]=1;
    }
    else if(carteARenvoyer==2 && renvoie[1]!=1){
      printf("┌──────────────────────────────────────────────────────────────┐\n");
      printf("Vous avez décidé de relancer la carte 2 !\n");
      printf("► Tapez '0' si vous voulez garder votre main ◄\n");
      printf("► Vous pouvez cependant choisir de retirer d'autres cartes ! ◄\n");
      printf("└──────────────────────────────────────────────────────────────┘\n");
      printf("\n");
      renvoie[1]=1;
    }
    else if(carteARenvoyer==3 && renvoie[1]!=1){
      printf("┌──────────────────────────────────────────────────────────────┐\n");
      printf("Vous avez décidé de relancer la carte 3 !\n");
      printf("► Tapez '0' si vous voulez garder votre main ◄\n");
      printf("► Vous pouvez cependant choisir de retirer d'autres cartes ! ◄\n");
      printf("└──────────────────────────────────────────────────────────────┘\n");
      printf("\n");
      renvoie[2]=1;
    }
    else if( (carteARenvoyer==1 && renvoie[0]==1) || (carteARenvoyer==2 && renvoie[1]==1) || (carteARenvoyer==3 && renvoie[2]==1) ){
      printf("┌─────────────────────────────────────────────────────────────────────────┐\n");
      printf("Vous avez déjà choisi de retirer cette carte de votre main de départ.\n");
      printf("► Tapez '0' si vous voulez garder votre main ◄\n");
      printf("► Vous pouvez cependant choisir de retirer d'autres cartes ! ◄\n");
      printf("└─────────────────────────────────────────────────────────────────────────┘\n");
      printf("\n");
    }
  }
}

void print_fin_mulligan(Plateau p){
  printf("Votre main de départ est :\n");
  printf("──────────────────────────────────────────────────────\n");
  printf("\n");
  printf("┌─────────────────────────────────────────────────────┐\n");
  printf("\n");
  queue hand = get_main(p);
  int taille_main = queue_length(hand);
    for(int i=1;i<=taille_main;i++){
      printf("  %s : ", lecture_queue(i,hand).nom);
      printf("  Type : %c ; ", get_type_carte(lecture_queue(i,hand)));
      printf("  Coût : %i ; ", get_cout_carte(lecture_queue(i,hand)));
      printf("\n");
      printf("\n");
    }
  printf("└─────────────────────────────────────────────────────┘\n");
  printf("\n");
  printf("╔════════════════════╗\n");
  printf("║  Fin du Mulligan   ║\n");
  printf("╚════════════════════╝\n");
  printf("\n");
  printf("\n");
  printf("\n");
}

int fise_fisa(){
    int fiseOuFisa=0;
    printf("╔═══════════════════╗\n");
    printf("║ Choix de l'élève: ║\n");
    printf("╚═══════════════════╝\n");
    printf("\n");
    printf("Ajouter une carte FISE ou FISA ?\n");
    printf("────────────────────────────────\n");
    printf("Tapez '1' pour une carte FISE.\n");
    printf("Tapez '2' pour une carte FISA.\n");
    scanf("%d",&fiseOuFisa);
    printf("\n");
    if(fiseOuFisa == 1){
        printf("► Une carte FISE a été ajouté. ◄\n");
    }
    else if(fiseOuFisa == 2){
        printf("► Une carte FISA a été ajouté ◄\n");
    }
    else {
        printf("► Vous venez d'entrer un mauvais numéro ◄\n");
    }
    printf("\n");
    return fiseOuFisa;
}

int choix_carte(Plateau p){
  int carteAJouer = -1;
  printf("╔═══════════════════╗\n");
  printf("║ Choix de la carte ║\n");
  printf("╚═══════════════════╝\n");
  if(is_empty_queue(p.main)){
    carteAJouer = 0;
    printf("► Tu n'as pas de carte dans ta main ◄\n");
    printf("► Fin du tour ◄\n");
  }
  else {
    int energie = get_energie(p);
    queue hand = get_main(p);
    int taille_main = queue_length(hand);
    printf("Vous avez %i d'énergie\n", energie);
    printf("► Tapez '0' si vous voulez passer votre tour. ◄\n");
    printf("\n");
    printf("Voici votre main avec les numéros associés aux cartes:\n");
    printf("──────────────────────────────────────────────────────\n");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────┐\n");
    printf("\n");
    for(int i=1;i<=taille_main;i++){
      printf("  Tapez '%i' si vous voulez jouer cette carte :\n", i );
      printf("  %s : ", lecture_queue(i,hand).nom);
      printf("  Type : %c ; ", get_type_carte(lecture_queue(i,hand)));
      printf("  Coût : %i ; ", get_cout_carte(lecture_queue(i,hand)));
      printf("\n");
      printf("\n");
    }
    printf("└─────────────────────────────────────────────────────┘\n");
    printf("\n");
    int ok = 0;  
    scanf("%d", &carteAJouer);
    if(carteAJouer == 0){
      printf("► Vous venez de passer votre tour. ◄\n");
      printf("► Tapez 0 pour continuer. ◄\n");
      scanf("%d", &ok);
      printf("\n");
    }
    printf("\n");
  }
  return carteAJouer;
}

void affichage_plateau(Plateau p){
  printf("\n");
  printf("Votre main :\n");
  printf("────────────");
  printf("\n");
  printf("\n");
  queue hand = get_main(p);
  int taille_main = queue_length(hand);
  int i;
  printf("┌─────────────────────────────────────────────────┐\n");
  for(i=1;i<=taille_main;i++){
        printf("  %s : ", lecture_queue(i,hand).nom);
        printf("Type : %c ; ", get_type_carte(lecture_queue(i,hand)));
        printf("Coût : %i ", get_cout_carte(lecture_queue(i,hand)));
        printf("\n");
    }
  printf("└─────────────────────────────────────────────────┘\n");
  printf("\n");
  printf("Vos piles d'élèves :\n");
  printf("────────────────────\n");
  printf("\n");
  printf("Vous avez %i carte(s) dans la pile FISE\n", stack_length(p.pile_fise));
  printf("Vous avez %i carte(s) dans la pile FISA\n", stack_length(p.pile_fisa));
  printf("\n");
  printf("Pile du personnel :\n");
  printf("───────────────────\n");
  printf("\n");
  printf("Il vous reste %i place de personnel de libre sur le plateau.\n", get_places_personnel_restantes(p));
  printf("\n");
  Carte c;
  while(!(is_empty_queue(p.file_personnel))){
    c=dequeue(&(p.file_personnel));
    printf("--------------------%s : -------------------\n", c.nom);
  }
  printf("\n");
}

void nouveau_tour(Plateau p1, Plateau p2){
  printf("\n");
  printf("                                        ┌─────────────────┐\n");
  printf("                                        │ Début du tour %2i│\n", p1.tour);
  printf("                                        └─────────────────┘\n");
  printf("\n");
  printf("\n");
  if(p1.tour%2==0){
    printf("/!\\ Les cartes FISA sont désactivées.\n");
    printf("\n");
    printf("\n");
  }
  else{
    printf("/!\\  Les cartes FISA sont activées.\n");
    printf("\n");
    printf("\n");
  }
  int valeurDeveloppementFisap1 = valeur_developpement_fisa_p1(p1,p2);
  int valeurDurabiliteFisap1 = valeur_durabilite_fisa_p1(p1,p2);
  int valeurDeveloppementFisap2 = valeur_developpement_fisa_p2(p1,p2);
  int valeurDurabiliteFisap2 = valeur_durabilite_fisa_p2(p1,p2);
  int valeurDeveloppementFisep1 = valeur_developpement_fise_p1(p1,p2);
  int valeurDurabiliteFisep1 = valeur_durabilite_fise_p1(p1,p2);
  int valeurDeveloppementFisep2 = valeur_developpement_fise_p2(p1,p2);
  int valeurDurabiliteFisep2 = valeur_durabilite_fise_p2(p1,p2);

  char * case1A ="Carte Personnel n°1 ";
  char * case2A ="Carte Personnel n°2 ";
  char * case3A="Carte Personnel n°3 ";
  if(!(is_empty_queue(p1.file_personnel))){
    case1A = dequeue(&(p1.file_personnel)).nom;
    if(!(is_empty_queue(p1.file_personnel))){
      case2A = dequeue(&(p1.file_personnel)).nom;
      if(!(is_empty_queue(p1.file_personnel))){
        case3A = dequeue(&(p1.file_personnel)).nom;
      }
    }
  }

  char * case1B =" Carte Personnel n°1";
  char * case2B =" Carte Personnel n°2";
  char * case3B=" Carte Personnel n°3";
  if(!(is_empty_queue(p2.file_personnel))){
    case1B = dequeue(&(p2.file_personnel)).nom;
    if(!(is_empty_queue(p2.file_personnel))){
      case2B = dequeue(&(p2.file_personnel)).nom;
      if(!(is_empty_queue(p2.file_personnel))){
        case3B = dequeue(&(p2.file_personnel)).nom;
      }
    }
  }
  // Début affichage du plateau
  // Le développement des cartes est à gauche du / et la durabilité à droite.
  printf("   ╔═══════════════════════════════════════════╦══════════════════════════════════════════╗   \n");
  printf("E  ║%2i/%2i FISA :  %2i                           ║                          %2i  : FISA %2i/%2i║  E\n",valeurDeveloppementFisap1,valeurDurabiliteFisap1,stack_length(p1.pile_fisa),stack_length(p2.pile_fisa),valeurDeveloppementFisap2,valeurDurabiliteFisap2 );
  printf("N  ╟────┐                                      ║            [%20s]   ┌────╢  N\n",case3B);
  printf("S  ║ DD │    [%20s]            ║                                     │ DD ║  S\n",case1A);
  printf("I  ║    │                                      ║            [%20s]   │    ║  I\n",case2B);
  printf("I  ║ %2i │    [%20s]            ║                                     │%2i  ║  I\n", p1.pt_dvpt_durable,case2A, p2.pt_dvpt_durable);
  printf("E  ║    │                                      ║            [%20s]   │    ║  E\n", case1B);
  printf("   ╟────┘    [%20s]            ║                                     └────╢   \n",case3A);
  printf("A  ║%2i/%2i FISE :  %2i                           ║                          %2i  : FISE %2i/%2i║  B\n",valeurDeveloppementFisep1,valeurDurabiliteFisep1,stack_length(p1.pile_fise),stack_length(p2.pile_fise),valeurDeveloppementFisep2,valeurDurabiliteFisep2);
  printf("   ╚═══════════════════════════════════════════╩══════════════════════════════════════════╝   \n");

  // Début affichage du plateau
  printf("┌───────────────────────────────────────────────────────────────┐\n");
  printf("│   L'ENSIIE A et B possèdent %i place(s) pour le personnel.     │\n", get_places_personnel(p1));
  printf("└───────────────────────────────────────────────────────────────┘\n");
  printf("\n");
}

void nouvelle_phase(int i){
  if(i%2==0){
    printf("             C'est le début de la phase de l'ENSIIE A\n");
    printf("             ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬");
    printf("\n");
    printf("\n");
  } 
  else {
    printf("             C'est le début de la phase de l'ENSIIE B\n");
    printf("             ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬");
    printf("\n");
    printf("\n");
  }
  printf("\n");
}
   
void victoire_egalite(Plateau p1, Plateau p2){
  if(p1.pt_dvpt_durable==p2.pt_dvpt_durable){
    printf("Egalité !\n");
  }
  if(p1.pt_dvpt_durable>=20){
    printf("ENSIIE A a gagné !\n");
  }
  if(p2.pt_dvpt_durable>=20){
    printf("ENSIIE B a gagné !\n");
  }
  printf("\n");
}
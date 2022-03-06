#include <stdio.h>
#include <stdlib.h>

#include "../obj/carte.h"
#include "../obj/plateau.h"
#include "../headers/interface.h"

//Début nouveau main
int main(){
	//Initialisation des deux plateaux
	Plateau P_1=new_plateau(0);
	Plateau P_2=new_plateau(20);
	int numero_carte;
	int fiseOuFisa=0;
	int tab_mulligan_[3] = {0,0,0};
	int tab_mulligan_b[3] = {0,0,0};
	int nb_phase = 0;
	//Début de la partie, chaque ENSIIE pioche 3 cartes
	for (int i = 0; i<3;i++){
		draw(&P_1);
		draw(&P_2);
	}
	//Le mulligan va commencer, c'est à dire que les joueurs auront le choix de garder les cartes qu'ils ont piochées dans leur main de départ, ou de les renvoyer
	//pour en piocher de nouvelles à la place
	printf("Le mulligan de l'ensiie A commence\n");
	print_mulligan(P_1,tab_mulligan_);
	mulligan(tab_mulligan_, &P_1);
	print_fin_mulligan(P_1);
	printf("Le mulligan de l'ensiie B commence\n");
	print_mulligan(P_2,tab_mulligan_b);
	mulligan(tab_mulligan_b, &P_2);
	print_fin_mulligan(P_2);
	//Tant que la partie n'est pas finie, on joue
	while(!est_partie_finie(P_1,P_2)){
		//On commence un nouveau tour pour l'ensiie 1 et 2
		new_tour(&P_1);
		new_tour(&P_2);
		nouveau_tour(P_1,P_2); //On affiche toutes les informations utiles pour le début de tour (je prends P_1 mais j'aurais pu prendre P_2, les informations sont les mêmes.)

		nouvelle_phase(nb_phase); //Affiche qui doit jouer sa phase.

		// On rappelle que si la phase est paire c'est l'ENSIIE 1 qui joue sinon 2.
		// On rappelle également qu'il faut qu'il y ait une alternance dans les phases : 1 -> 2 -> 2 -> 1

		//Dans le cas où la phase est paire :
		if((nb_phase)%2==0){

			//On pioche le bon nombre de carte au début de sa phase.
			for (int i=0;i<nbr_cards_drawn(P_1);i++)
		    {
			    draw(&P_1);
		    }
			//affichage_plateau(P_1);
			//On demande s'il veut jouer une carte FISE ou FISA.
			for(int i=0;i<nbr_carte_eleve(P_1);i++){
				fiseOuFisa=0;
            	while( !(fiseOuFisa == 1 || fiseOuFisa == 2)){
                	fiseOuFisa = fise_fisa();
					if (fiseOuFisa == 1){ ajoute_carte_FISE(&P_1);}
					else if (fiseOuFisa == 2){ ajoute_carte_FISA(&P_1);}
            	}
			}
			setEnergie(&P_1);
			while ((numero_carte = choix_carte(P_1)))// Si numero_carte = 0, alors le joueur voulait passer son tour, sinon, c'est qu'il voulait jouer une carte.
			{
				jouer_cart_main(&P_1, &P_2, numero_carte, 1);
			}
			affichage_plateau(P_1);
			affichage_plateau(P_1);
			//
			// On passe au deuxième joueur
			//
		    printf("             C'est le début de la phase de l'ENSIIE B\n");
    		printf("             ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬");
    		printf("\n");
			printf("\n");
			//On pioche le bon nombre de carte au début de sa phase.
			for (int k=0;k<nbr_cards_drawn(P_2);k++)
		    {
			    draw(&P_2);
		    }
		//	affichage_plateau(P_2);
			//On demande s'il veut jouer une carte FISE ou FISA.
			for(int i=0;i<nbr_carte_eleve(P_2);i++){
				fiseOuFisa=0;
            	while( !(fiseOuFisa == 1 || fiseOuFisa == 2)){
                	fiseOuFisa = fise_fisa();
					if (fiseOuFisa == 1){ ajoute_carte_FISE(&P_2);}
					else if (fiseOuFisa == 2){ ajoute_carte_FISA(&P_2);}
            	}
			}
			setEnergie(&P_2);
			while ((numero_carte = choix_carte(P_2)))// Si numero_carte = 0, alors le joueur voulait passer son tour, sinon, c'est qu'il voulait jouer une carte.
			{
				jouer_cart_main(&P_1, &P_2, numero_carte, 2);
			}
		//	affichage_plateau(P_2);
			tour_terminer(&P_1,&P_2);
			nb_phase += 1;
		}
		else // C'est l'autre ensiie qui doit commencer à jouer.
		{
			//On pioche le bon nombre de carte au début de sa phase.
			for (int i=0;i<nbr_cards_drawn(P_2);i++)
		    {
			    draw(&P_2);
		    }
			affichage_plateau(P_2);
			//On demande s'il veut jouer une carte FISE ou FISA.
			for(int i=0;i<nbr_carte_eleve(P_2);i++){
				fiseOuFisa=0;
            	while( !(fiseOuFisa == 1 || fiseOuFisa == 2)){
                	fiseOuFisa = fise_fisa();
					if (fiseOuFisa == 1){ ajoute_carte_FISE(&P_2);}
					else if (fiseOuFisa == 2){ ajoute_carte_FISA(&P_2);}
            	}
			}
			setEnergie(&P_2);
			while ((numero_carte = choix_carte(P_2)))// Si numero_carte = 0, alors le joueur voulait passer son tour, sinon, c'est qu'il voulait jouer une carte.
			{
				jouer_cart_main(&P_1, &P_2, numero_carte, 2);
			}
			affichage_plateau(P_2);
			//
			// On passe au deuxième joueur
			//
			printf("             C'est le début de la phase de l'ENSIIE A\n");
    		printf("             ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬");
    		printf("\n");
			printf("\n");
			//On pioche le bon nombre de carte au début de sa phase.
			for (int k=0;k<nbr_cards_drawn(P_1);k++)
		    {
			    draw(&P_1);
		    }
			affichage_plateau(P_1);
			//On demande s'il veut jouer une carte FISE ou FISA.
			for(int i=0;i<nbr_carte_eleve(P_1);i++){
				fiseOuFisa=0;
            	while( !(fiseOuFisa == 1 || fiseOuFisa == 2)){
                	fiseOuFisa = fise_fisa();
					if (fiseOuFisa == 1){ ajoute_carte_FISE(&P_1);}
					else if (fiseOuFisa == 2){ ajoute_carte_FISA(&P_1);}
            	}
			}
			setEnergie(&P_1);
			while ((numero_carte = choix_carte(P_1)))// Si numero_carte = 0, alors le joueur voulait passer son tour, sinon, c'est qu'il voulait jouer une carte.
			{
				jouer_cart_main(&P_1, &P_2, numero_carte, 2);
			}
			affichage_plateau(P_1);
			tour_terminer(&P_1,&P_2);
			nb_phase += 1;
		}
	}
	victoire_egalite(P_1,P_2);
	//free_plateau(&P_1);
	//free_plateau(&P_2);
	return 0;
}
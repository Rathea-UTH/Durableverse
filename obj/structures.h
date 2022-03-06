#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_SIZE 200
#include "carte.h"
/* type des élements contenus dans la pile */
typedef Carte elem;

typedef struct stack stack;

typedef struct queue_base queue;

struct stack{
  int top;    //position du sommet
  elem val[MAX_SIZE];   //elements de la pile
};

struct queue_base {
    int tail;
    int head;
    elem val[MAX_SIZE]; 
};

/* @requires nothing
   @assigns nothing
   @ensures retourne une pile vide */
stack create_stack();

/* @requires nothing
   @assigns nothing
   @ensures retourne 0 ssi la pile ps est vide */
int is_stack_empty(stack);

/* @requires s est une adresse valide et *s contient moins de STACK_MAX elements
   @assigns *s
   @ensures ajoute a au sommet de de la pile s */
void stack_push(elem,stack*);

/* @requires s est une adresse valide et *s est non-vide  
   @assigns nothing
   @ensures depiler le sommet de la pile s et le retourne  */
elem stack_pop(stack*);

/* @requires s est une adresse valide
   @assigns nothing
   @ensures la taille de la pile s */
int stack_length(stack);

/* @requires rien
 * @assigns une file FIFO
 * @ensures cette file FIFO est retournée prête à l'usage */
queue empty_queue();

/* @requires une file bien formée
 * @assigns rien
 * @ensures 1 est retourné si la file est vide, sinon 0*/
int is_empty_queue(queue);

/* @requires une file bien formée
 * @assigns rien
 * @ensures e est ajouté en haut de la file */
void enqueue(queue*,elem);

/* @requires une file bien formée et non-vide
 * @assigns rien
 * @ensures l'élement entré il y a la plus longtemps dans la file est retourné */
elem dequeue(queue*);

/* @requires int i, pile s est une adresse valide  
   @assigns nothing
   @ensures Lecture du i-eme élement dans la pile et le retoune */
elem lecture(int,stack);

/* @requires une file bien formée
   @assigns nothing
   @ensures la taille de la file (queue) q */
int queue_length(queue);

/* @requires int i, queue q une file bien formée et non-vide
   @assigns nothing
   @ensures Lecture du i-eme élement dans la file et le retoune */
elem lecture_queue(int,queue);

/* @requires int i, queue q une file bien formée et non-vide
   @assigns nothing
   @ensures Lecture du i-eme élement dans la file et le retoune */
void free_stack(stack*);

/* @requires int i, queue q une file bien formée et non-vide
   @assigns nothing
   @ensures Lecture du i-eme élement dans la file et le retoune */
void free_queue(queue*);

elem queue_enlever_i(int,queue*);

#endif
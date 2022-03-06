#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
stack create_stack()
{
  stack r;
  r.top = -1;
  return r;
}

int is_stack_empty(stack s) 
{
  return(s.top==-1);
}

void stack_push(elem a, stack *s) 
{
  s->top = s->top + 1;
  s->val[s->top] = a;
}

elem stack_pop(stack *s) 
{
  elem r;
  r = s->val[s->top];
  s->top = s->top - 1;
  return r;
}

int stack_length(stack s) {
  return s.top+1;
}


queue empty_queue() {
    queue q;
    q.tail=0;
    q.head=0;
    return q;
}

int is_empty_queue(queue q) {
    return(q.head==q.tail);
}

void enqueue(queue * q, elem e) {
    q->val[q->tail] = e;
    q->tail = (q->tail+1)%MAX_SIZE;
}

elem dequeue(queue * q) {
  elem f = q->val[q->head];
  q->head=(q->head+1)%MAX_SIZE;
  return f;
}

int queue_length(queue q){
  if(q.tail>q.head){
    return q.tail-q.head;
  }
  else{
    return q.head-q.tail;
  }
}

elem queue_enlever_i(int i, queue* q)
{
  if ( queue_length(*q) < i){
    printf("Il n'existe pas !!!\n");
    exit(1); 
  }
  else
  {
    queue q2 = empty_queue();
    for (int j = 0; j < i-1; j+=1)
    {
      enqueue(&q2,dequeue(q));
    }
    elem result = dequeue(q);
    while(! is_empty_queue(*q))
    {
      enqueue(&q2,dequeue(q));
    }
    while(! is_empty_queue(q2))
    {
      enqueue(q,dequeue(&q2));
    }
    return result;
  }
}

elem lecture_queue(int i, queue q){
  if ( queue_length(q) < i){
    printf("Il n'existe pas !!!\n");
    exit(1); 
  }
  else
  {
    queue q2 = empty_queue();
    for (int j = 0; j < i-1; j+=1)
    {
      enqueue(&q2,dequeue(&q));
    }
    elem result = dequeue(&q);
    return result;
  }
}

void free_stack (stack *ps)
{
  free(ps->val);
}

void free_queue (queue *q){
  free(q->val);
}

/*void print_stack(stack s){
  elem r;
  while(!(is_stack_empty(s))){
    r=stack_pop(&s);
    printf("%d",r);
  }
}

void print_queue(queue q){
    while(!is_empty_queue(q)){
        printf("%d\n",dequeue(&q));
    }
}
*/
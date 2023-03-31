#include "arraylist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// normal array
typedef struct ArrayList {
  void **data;
  int capacity;
  int size;
} ArrayList;


void expandList(ArrayList *l) {

  l->data = realloc(l->data, l->capacity * 2);

  l->capacity *= 2;
}

void empujarDer(ArrayList *l, int i) {
  for (int k = l->size - 1; k >= i; k--)
    l->data[k + 1] = l->data[k]; //
}

void empujarIzq(ArrayList *l, int i) {
  for (int k = i; k < l->size - 1; k++)
    l->data[k] = l->data[k + 1]; //

	
}

ArrayList *createList(void) {

  ArrayList *new = malloc(sizeof(ArrayList));
  new->data = (void **)malloc(sizeof(void *) * 2);
  new->capacity = 2; // porque inicializa en 2?
  new->size = 0;

  return new;
}

void append(ArrayList *l, void *data) {
  // Si esta lleno agrandar.
  if (l->size == l->capacity)
    expandList(l);

  l->data[l->size] = data;
  l->size++;
}

void push(ArrayList *l, void *data, int i) {
  if (l->size == l->capacity)
    expandList(l);
  // si es mayor no hay que hacer nada
  if (i > l->size)
    return;

  empujarDer(l, i);

  l->data[i] = data;
  l->size++;
}

void *pop(ArrayList *l, int i) {
  if (l->size==0 || i > l->size)
    return NULL;
	
  if (i<0)
  	i= l->size-i;
	
  void *stored = l->data[i];

  empujarIzq(l, i);
  l->size--;
  return stored;
}

void *get(ArrayList *l, int i) { 
	if (l->size==0 || l->size < i) return NULL;

	i=(i < 0)?(l->size+i):i;
	
	return l->data[i];
}

int get_size(ArrayList *l) { return l->size; }

// remove elements
void clean(ArrayList *l) {}

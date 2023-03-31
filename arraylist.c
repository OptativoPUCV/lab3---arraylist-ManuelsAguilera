#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;


void expandList(ArrayList *l)
{

	l->data=realloc(l->data,l->capacity*2);

	l->capacity*=2;


}

void empujarDer(ArrayList* l,int i)
{
	for(int k = l->size; k > i ;	k--)
		l->data[k+1]=l->data[k]; //
}

ArrayList *createList(void) {
							 
    ArrayList* new=malloc(sizeof(ArrayList));
	new->data = (void **) malloc(sizeof(void*)*2);
	new->capacity=2; //porque inicializa en 2?
	new->size=0;

	return new;
}

void append(ArrayList * l, void * data){
	if (l->size == l->capacity) expandList(l);
	
	l->data[l->size]= data;
	l->size++;
}

void push(ArrayList * l, void * data, int i){
	if (l->size == l->capacity) expandList(l);
	if (i> l->size) return;

	empujarDer(l,i);

	l->data[i]=data;
	l->size++;
}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *lista = (List*)malloc(sizeof(List));
  lista->head = NULL;
  lista->tail = NULL;
  lista->current = NULL;

  return lista;
}

void * firstList(List * list) {
  if (list == NULL || list->head == NULL) {
    return NULL;
  }
  return list->head->data;
}

void * nextList(List * list) {
  if (list == NULL || list->current == NULL || list->current->next == NULL) {
    
    return NULL;
  }
  list->current = list->current->next; 
  
  return list->current->data; 
}

void * lastList(List * list) {
  if (list == NULL || list->head == NULL) {
    
    return NULL;
  }

  list->current = list->tail; 
  
  return list->current->data; 
}

void * prevList(List * list) {
  if (list == NULL || list->current == NULL || list->current == list->head) {
    
    return NULL;
  }

  
  Node *prevNode = list->head;
  while (prevNode->next != list->current) {
    prevNode = prevNode->next;
  }

  
  list->current = prevNode;
  return prevNode->data; 
}

void pushFront(List * list, void * data) {
  Node * newNode = createNode(data);

  if(list->head == NULL)
  {
    list->head = newNode;
    list->tail = newNode;    
  }

  else{
    list->head->prev = newNode;
    newNode->next = list->head;
    list->head = newNode;
  }
  
}

void pushBack(List * list, void * data) {
  list->current = list->tail;
  pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {

  if (list == NULL || list->current == NULL) {
    
    return;
  }

  Node *newNode = createNode(data);
  

  if (list->current == list->tail) {
    list->tail = newNode;
  }

  if (list->current->next == NULL) {
    list->tail = newNode;
  }

  newNode->next = list->current->next;
  list->current->next = newNode;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  
  return NULL;
   
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
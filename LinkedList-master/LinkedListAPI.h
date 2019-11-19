#ifndef _LIST_API_
#define _LIST_API_

#include <stdio.h>
#include <stdlib.h>
typedef struct listNode{
    void *data;
    struct listNode *previous;
    struct listNode *next;
} Node;

typedef struct listHead{
    Node *head;
    Node *tail;
    void (*deleteNode)(void *toBeDeleted);
    int (*compare)(const void *first,const void *second);
    void (*printNode)(void *toBePrinted);
} List;

List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second));

Node *initializeNode(void *data);

void insertFront(List *list, void *toBeAdded);

void insertBack(List *list, void *toBeAdded);

void deleteList(List *list);

void insertSorted(List *list, void *toBeAdded);

int deleteNodeFromList(List *list, void *toBeDeleted);

void *getFromFront(List *list);

void *getFromBack(List *list);

void printForward(List *list);

void printBackwards(List *list);

void deleteListNode(void *toBeDeleted);

int contains(List * list, void* tobeFound);

#endif

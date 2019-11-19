
#include <stdlib.h>
#include <stdio.h>
#include "LinkedListAPI.h"

List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second))
{
	List* list = malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->printNode = printFunction;
	list->compare = compareFunction;
	list->deleteNode = deleteFunction;
	return list;
}

Node *initializeNode(void *data){
	Node* node = malloc(sizeof(Node));
	node->next = NULL;
	node->previous = NULL;
	node->data = (void*)data;
	return node;
}

void insertFront(List *list, void *toBeAdded){
	Node* newNode = NULL;
	newNode = initializeNode(toBeAdded);
	if(list->head == NULL)
	{
		list->head = newNode;
		list->tail = newNode;
	}
	else
	{
		list->head->previous = newNode ;
		newNode->next = list->head;
		list->head = newNode;
	}
}

void printForward(List *list){
	
	Node* temp = list->head;
	while( temp != NULL)
	{
		list->printNode(temp->data);
		temp = temp->next;
	}
}

void insertBack(List *list, void *toBeAdded){
	Node* newNode = NULL;
	newNode = initializeNode(toBeAdded);
	if(list->head == NULL)
	{

		list->head = newNode;
		list->tail = newNode;
	}
	else
	{

		list->tail->next = newNode;
		newNode->previous = list->tail;
		list->tail = newNode;
	}
}
void insertSorted(List *list, void *toBeAdded){
	int count = 0;
	Node* newNode = NULL;
	newNode = initializeNode(toBeAdded);

	if(list->head == NULL){
		list->head = newNode;
		list->tail = newNode;
	}
	else{
		if(list->compare(list->head->data, newNode->data) == 1){
			count++;
			insertFront(list, toBeAdded);
		}
		else if(list->compare(list->tail->data, newNode->data) <= 0){
			count++;
			insertBack(list, toBeAdded);
		}
		if(count == 0){
			Node* temp = list->head;
			while(temp->next != NULL && list->compare(temp->data, newNode->data) < 1){
				temp = temp -> next;
			}
			newNode->next = temp;
			newNode->previous = temp->previous;
			temp->previous->next = newNode;
			temp->previous = newNode;
		}
	}
}
int deleteNodeFromList(List *list, void *toBeDeleted){
	Node* temp = list -> head;
	if(list->compare(temp->data, toBeDeleted) == 0 )
	{
		if(temp->next != NULL)
		{
			list->head = temp->next;
			list->head->previous = NULL;
			temp->next = NULL;
			free(temp);
			return 1;
		}
		else
		{
			deleteList(list);
		}
	}
	else if (list->compare(list->tail->data, toBeDeleted) == 0)
	{
		temp = list->tail;
		list->tail = temp->previous;
		list->tail->next = NULL;
		temp->previous = NULL;
		free(temp);
		return 1;
	}
	else
	{
		while(temp != NULL)
		{
			if(list->compare(temp->data, toBeDeleted) == 0)
			{
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
				temp->previous = NULL;
				temp->next = NULL;
				free(temp);
				return 1;
			}
			temp = temp->next;
		}
	}
	return 0;
}
void deleteList(List *list){
	Node* temp = list -> head;
	Node* nextNode = NULL;
	while(temp != NULL){
		nextNode = temp->next;
		free(temp);
		temp = nextNode;
	}
	list->head = NULL;
	list->tail = NULL;
	temp = NULL;
	//free(list);

}

int contains(List * list, void* tobeFound)
{
	if(list->head == NULL)
	{
		return 0;
	}
	Node* temp = list -> head;
	while(temp != NULL){
		if(list->compare(temp->data, tobeFound) == 0)
		{
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

void printBackwards(List *list){
	Node* temp = list->tail;
	while( temp != NULL)
	{
		list->printNode(temp->data);
		temp = temp->previous;
	}
}


void *getFromFront(List *list){
	return (void*)(list->head->data);
}

void *getFromBack(List *list){
	return (void*)(list->tail->data);

}

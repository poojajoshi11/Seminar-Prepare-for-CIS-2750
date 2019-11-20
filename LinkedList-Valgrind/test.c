#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

	int data;
	struct Node* next;

}Node;


int main(){
	
	Node* node = malloc(sizeof(node));
	node->next->data = 12;

}
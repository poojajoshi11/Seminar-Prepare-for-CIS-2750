#include <stdio.h>
#include <stdlib.h>

typedef struct car{
	char dir;
	char dirTo;
	int arrival ;
}Car;

int compare(const void *first,const void *second);
Car* initializeCar(char di, char to, int arr);
char* printNode(void *toBePrinted);
void delete(void *toBeDeleted);

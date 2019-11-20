#include "Car.h"



Car* initializeCar(char di, char to, int arr)
{
	Car * newCar = malloc(sizeof(Car*));
	newCar->dir = di;
	newCar->dirTo = to;
	newCar->arrival = arr;
	return newCar;
}

int compare(const void *first,const void *second){
	Car * fir = (Car*)first;
	Car * sec = (Car*)second;
	if(fir->arrival == sec->arrival)
	{
		return 0;
	}
	if(fir->arrival < sec->arrival) {
    	return -1;
	}
	return 1;
}

char* printNode(void *toBePrinted){
	Car * toBe= (Car*)toBePrinted;
	printf("%c %c %d\n", toBe->dir, toBe->dirTo, toBe->arrival);
	return "";
}

void delete(void *toBeDeleted){
	Car * temp = (Car*)toBeDeleted;
	free(temp);
	temp = NULL;
}


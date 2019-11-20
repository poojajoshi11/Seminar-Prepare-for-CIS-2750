#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"
#include "Car.h"

int main()
{
	List * NorthList = initializeList(&printNode, &delete, &compare);
	List * SouthList = initializeList(&printNode, &delete, &compare);
	List * EastList = initializeList(&printNode, &delete, &compare);
	List * WestList = initializeList(&printNode, &delete, &compare);
	// Text file containing car and direction info
	FILE * fp = NULL;
	fp = fopen("textFile.txt","r");
		
	while (!feof(fp))
	{
		Car* temp = malloc(sizeof(Car*));
		fscanf(fp,"%c %c %d\n",&temp->dir, &temp->dirTo, &temp->arrival);
		if(temp->dir == 'N')
		{
			insertSorted(NorthList, temp);
		}
		if(temp->dir == 'S')
		{
			insertSorted(SouthList, temp);
		}
		if(temp->dir == 'E')
		{
			insertSorted(EastList, temp);
		}
		if(temp->dir == 'W')
		{
			insertSorted(WestList, temp);
		}
  		
	}		
	
	printf("NorthList:\n");
	printForward(NorthList);
	printf("EastList:\n");
	printForward(EastList);
	printf("SouthList:\n");
	printForward(SouthList);
	printf("WestList:\n");
	printForward(WestList);
	
	
	int timer = 1;
	int listCounter = 1;
	List * current = NULL;
	printf("\nSimulation begins");
	
	while(NorthList->head != NULL|| SouthList->head != NULL||EastList->head!= NULL||WestList->head!= NULL) {
		if(listCounter == 1) {
			current = NorthList;
			
		}
		if(listCounter == 2) {
			current = EastList;
			
		}
		if(listCounter == 3) {
			current = SouthList;
			
		}
		if(listCounter == 4){

			current = WestList;
		}
		
		int green = timer + 10;
		
		while(timer <= green){
			if(current->head != NULL){
				Car * currentCar = (Car*)(current->head->data);
				if(currentCar->arrival <= timer){
					if(currentCar->dirTo == 'L'){
						timer+= 3;
					}
					else if(currentCar->dirTo == 'F'){
						timer += 2;
					}
					else
					{
						timer ++;
					}
					printf("\nCar passing: \n");
					printNode(currentCar);
					deleteDataFromList(current, currentCar);
					printf("Timer: %d\n", timer);
					printf("Remaining cars:\n");
					if(current->head!= NULL)
					{
						
						printForward(current);
					}
					else
					{
						current->head = NULL;
						printf("Current lane is empty\n");
					}
				}
				else
				{
					timer++;
				}
				free(currentCar);
			}
			else {
				timer+= (green-timer);
				break;
			}
		}
		timer ++;
		if(listCounter == 4)	{
			listCounter = 1;
		}
		else	{
			listCounter++;
		}	
	}
	printf("End of simulation\n");
	/*
	fclose(fp);
	fp = NULL;
		
	freeList(NorthList);
	freeList(SouthList);
	freeList(WestList);
	freeList(EastList);
	*/
}



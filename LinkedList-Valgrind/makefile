program: main.o Car.o ListFunctions.o
	gcc -o program main.o ListFunctions.o Car.o
main.o: main.c 
	gcc -c main.c

LinkedList.o:  ListFunctions.c LinkedListAPI.h
	gcc -Wall -c ListFunctions.c

Car.o:  Car.c Car.h
	gcc -Wall -c Car.c

clean:
	rm *.o
	rm program

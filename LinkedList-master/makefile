program: main.o Car.o ListFunctions.o
	gcc -o program main.o ListFunctions.o Car.o
	./program

main.o: main.c 
	gcc -c main.c

LinkedList.o:  ListFunctions.c LinkedListAPI.h
	gcc -Wall -c ListFunctions.c

Car.o:  Car.c car.h
	gcc -Wall -c Car.c

run:
	./program
clean:
	rm *.o
	rm program

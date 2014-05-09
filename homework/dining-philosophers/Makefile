dining: dining-philosophers.o chopstickFunctions.o philosopherFunctions.o utility.o
	gcc -o dining *.o -lpthread

dining-philosophers.o: table.h

chopstickFunctions.o: table.h

philosopherFunctions.o: table.h

utility.o: utility.h table.h

clean:
	rm dining *.o

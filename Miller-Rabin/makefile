mrtest: rabin.o rabinFunctions.o
	gcc -Wall -pedantic -g rabin.o rabinFunctions.o -o mrtest -lm

rabin.o: rabin.c rabinFunctions.h
	gcc -Wall -pedantic -g -c rabin.c -lm

rabinFunctions.o: rabinFunctions.c rabinFunctions.h
	gcc -Wall -pedantic -g -c rabinFunctions.c -lm

clean:
	rm -f mrtest *.o

mrtest: rabin.o rabinFunctions.o
	gcc -Wall -ansi -pedantic -O3 rabin.o rabinFunctions.o -o mrtest

rabin.o: rabin.c rabinFunctions.h
	gcc -Wall -ansi -pedantic -O3 -c rabin.c

rabinFunctions.o: rabinFunctions.c rabinFunctions.h
	gcc -Wall -ansi -pedantic -O3 -c rabinFunctions.c

clean:
	rm -f mrtest *.o

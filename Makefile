all: ppm

ppm: ppm.cpp imagefunctions.o
	g++ -Wall -c ppm ppm.cpp imagefunctions.o

imagefunctions.o: imagefunctions.h imagefunctions.cpp
	g++ -c -Wall -o imagefunctions.o imagefunctions.cpp

clean:
	rm *.o

mrproper: clean
	rm test_polymorph
all: ppm

ppm: ppm.c imagefunctions.out
	gcc -o ppm ppm.c imagefunction.out

imagefunctions: imagefunctions.h imagefunctions.c
	gcc -o imagefunctions.out imagefunctions.c

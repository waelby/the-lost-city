prog:fonction.o main2.o
	gcc fonction.o main2.o -o prog -lSDL -lSDL_image -g
main2.o:main2.c
	gcc -c main2.c -lSDL -lSDL_image -g
fonction.o:fonction.c
	gcc -c fonction.c -lSDL -lSDL_image -g

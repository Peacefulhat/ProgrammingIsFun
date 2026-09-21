
CFLAG=-Wall -Wextra
LDFLAGS= -lglfw -lGL -lX11 -lpthread 
IPATH=-Iinclude
main: main.c glad.o
	$(CC) $(CFLAGS) $(IPATH) -o main main.c glad.o $(LDFLAGS)

glad.o: glad.c
	$(CC) $(CFLAGS) -c glad.c

cleanglad:
	rm -rf glad.o

cleanexe:
	rm -rf main

clean: cleanglad cleanexe

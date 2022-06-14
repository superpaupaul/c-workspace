#changer le nom des deux lignes suivantes si nécessaire
SOURCES = wordblitz_grafik.c main_wordblitz_grafik.c WT.c scrabble.c grafik.c LC.c tabh.c
OUTPUT = resultat
LIB = -lm -lSDL -lSDL_ttf
OPT = -Wall -g
OBJ = $(SOURCES:.c=.o)


SDL_CFLAGS = $(shell sdl-config --cflags)
SDL_LDFLAGS = $(shell sdl-config --libs)


all: $(OUTPUT)

clean: 
	rm $(OUTPUT) *.o ../lib/*.o

$(OUTPUT): ../lib/libgraphique.o $(OBJ)
	@gcc $^  -o $(OUTPUT)  $(SDL_CFLAGS) $(SDL_LDFLAGS) $(LIB)


../lib/libgraphique.o: ../lib/libgraphique.c
	@gcc   -c ../lib/libgraphique.c -o ../lib/libgraphique.o 

main_wordblitz_grafik.o: main_wordblitz_grafik.h

%.o: %.c
	@gcc $(OPT) -c $<  -o $@







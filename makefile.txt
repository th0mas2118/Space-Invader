CC = gcc
CFLAGS = -W -Wall -ansi -std=c99 -g
LIBS = -lSDL2_ttf -lSDL2_image -lSDL2_mixer
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_ttf
INCLUDES = -I./SDL2_ttf -I./SDL2_image -I./SDL2_mixer
EXEC = spacebattle
SRC = main.c sdl2-light.c sdl2-ttf-light.c event.c sprite.c ressources.c world.c renderer.c fonction_score.c
OBJ = $(SRC:.c=.o)
all: $(EXEC)
spacebattle: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -rf *.o *~
mrproper: clean
	rm -rf $(EXEC) 
CC=gcc

LIB_PATH=-Llib
INC_PATH=-Iinclude

BIN=test

ifeq ($(OS), Windows_NT)
	LIB_FLAGS=-lwinpdcurses -lSDL2
	RM=cmd /c del
	BIN+=.exe
else
	LIB_FLAGS=-lpdcurses -lSDL2
	RM=rm -f
endif

SRC=main.c utils.c
OBJ=$(SRC:.c=.o)

all: $(BIN)

run: all
	./$(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(LIB_PATH) $(INC_PATH) $(LIB_FLAGS)

%.o: %.c
	gcc -c $< $(INC_PATH)

clean:
	$(RM) *.o
	$(RM) $(BIN)

.PHONY: all run clean

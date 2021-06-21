CC=gcc

LIB_PATH=-Llib
INC_PATH=-Iinclude
LIB_FLAGS=-lpdcurses

SRC=main.c
OBJ=$(SRC:.c=.o)

BIN=test.exe

all: $(BIN)

test.exe: $(OBJ)
	$(CC) -o $@ $^ $(LIB_PATH) $(INC_PATH) $(LIB_FLAGS)

run: all
	./$(BIN)

%.o: %.c
	gcc -c $< $(INC_PATH)

clean:
	cmd /c del *.o
	cmd /c del $(BIN)

.PHONY: all run clean

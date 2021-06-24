CC=gcc

LIB_PATH=-Llib
INCLUDE_PATH=-Iinclude

ifeq ($(OS), Windows_NT)
	LIB_FLAGS=-lwinpdcurses -lSDL2
	RM=cmd /c del
	BIN=test.exe
	CC+=-mwindows
else
	LIB_FLAGS=-lpdcurses -lSDL2
	RM=rm -f
	BIN=test
endif

SRC=main.c utils.c
OBJ=$(SRC:.c=.o)

all: $(BIN)

run: all
	./$(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(LIB_PATH) $(INCLUDE_PATH) $(LIB_FLAGS)

%.o: %.c
	gcc -c $< $(INCLUDE_PATH)

clean:
	$(RM) *.o
	$(RM) $(BIN)

.PHONY: all run clean

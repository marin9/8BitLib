CC=gcc
CFLAGS=-Wall -Wextra
LDFLAGS=-lSDL2 -lm
TARGET=mg

SRC=$(wildcard *.c)
INC=$(wildcard *.h)
OBJ=$(SRC:.c=.o)


$(TARGET): $(OBJ)
	@echo " Compile" $@
	@$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o : %.c $(INC)
	@echo " Compile" $<
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo " Clean"
	@rm -f *.o $(TARGET)

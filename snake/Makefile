CC=gcc
CFLAGS= -Wall -Wextra -I../lib
LDFLAGS= -lSDL2 -lm
TARGET=snake

SRC=$(wildcard *.c) $(wildcard ../lib/*.c)
INC=$(wildcard *.h) $(wildcard ../lib/*.h)
OBJ=$(SRC:.c=.o)


$(TARGET): $(OBJ)
	@echo " Compile" $@
	@$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o : %.c $(INC)
	@echo " Compile" $<
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo " Clean"
	@rm -f $(TARGET) *.o ../lib/*.o


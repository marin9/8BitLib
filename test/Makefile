CC=gcc
CFLAGS= -Wall -Wextra -I../lib
LDFLAGS= -L../lib -l8bit -lSDL2 -lm
TARGET=a.out

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


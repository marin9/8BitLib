CC=gcc
CFLAGS=-Wall -Wextra
LDFLAGS=-lSDL2 -lm
TARGET=lib8bit.a

SRC=$(wildcard *.c)
INC=$(wildcard *.h)
OBJ=$(SRC:.c=.o)


$(TARGET): $(OBJ)
	@echo " Compile" $@
	@ar rcs $@ $(OBJ)

%.o : %.c $(INC)
	@echo " Compile" $<
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo " Clean"
	@rm -f *.o $(TARGET)

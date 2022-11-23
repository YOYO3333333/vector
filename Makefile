CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g
LDFLAGS = -fsanitize=address

SRC = vector.c
OBJS = $(SRC:.c=.o)
LIB = libvector.a

all: library

library: $(LIB)
$(LIB): $(OBJS)
	ar crs $@ $^

clean:
	$(RM) *.o *.a

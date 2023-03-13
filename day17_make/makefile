CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm
INCLUDE_DIR = -I./header -I./dir_lev1 -I./dir_lev1/dir_lev2

SRCS = main.c ./dir_lev1/add.c ./dir_lev1/dir_lev2/sub.c
OBJS = $(SRCS:.c=.o)
MAIN = main

all: $(MAIN)
	@echo Simple compiler named mycc has been compiled

$(MAIN): $(OBJS) 
	echo $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@
	
.PHONY: clean

clean: 
	rm -rf $(OBJ) $(MAIN)
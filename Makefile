CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src/ipc_framework.c src/pipe_handler.c src/security_manager.c src/message_encoder.c src/logger.c
OBJ = $(SRC:.c=.o)

all: libipc.a anon_demo

libipc.a: $(OBJ)
	ar rcs libipc.a $(OBJ)

anon_demo: libipc.a examples/anon_pipe_demo.c
	$(CC) $(CFLAGS) -o anon_demo examples/anon_pipe_demo.c libipc.a

clean:
	rm -f $(OBJ) libipc.a anon_demo

#VARIABLE

CC=gcc
CFLAGS=-lpthread -W -Wall 

SERVER_BIN=server_exe
CLIENT_BIN=client_exe
LIB=$(wildcard lib/*.o)

#PHONY

.PHONY: clean all server client

#ALIAS

all:server client reset

reset:clean server client
server:bin/$(SERVER_BIN)
client:bin/$(CLIENT_BIN)

#INSTRUCTION


bin/$(SERVER_BIN): src/Server.c include/struct.h
	$(CC) src/Server.c $(LIB) -o bin/$(SERVER_BIN) $(CFLAGS)


bin/$(CLIENT_BIN): src/Client.c include/struct.h
	$(CC) src/Client.c -o bin/$(CLIENT_BIN) $(CFLAGS)


clean:
	rm -rf bin/*
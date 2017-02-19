CC=gcc
CFLAGS=-I.
client: tcp_client.c
	$(CC) -o tcp_client tcp_client.c $(CFLAGS)

server: tcp_server.c
	$(CC) -o tcp_server tcp_server.c $(CFLAGS)

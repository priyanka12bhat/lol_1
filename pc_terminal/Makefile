
CC=gcc
CFLAGS = -g -Wall -lm 
EXEC = ./pc-terminal

all:
	$(CC) $(CFLAGS) pc_terminal.c ../protocol/packet.c ../protocol/receivepacket.c ../protocol/crc16.c -o $(EXEC)

run: all
	 $(EXEC)
	 #valgrind --tool=memcheck $(EXEC)

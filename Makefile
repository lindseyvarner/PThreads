all: minions

minions: minions.c Makefile
	gcc -Wall -Wextra -g minions.c -o minions -pthread
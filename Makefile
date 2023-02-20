.RECIPEPREFIX = |

CC = gcc
CFLAGS = -Wall -g

default: all

all: clean main

main: main.c
| $(CC) $(CFLAGS) -o main main.c node.c list.c

clean veryclean:
|  rm -f main a.out

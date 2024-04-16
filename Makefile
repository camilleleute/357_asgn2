all: hist

hist: hist.o HistHelp.o
	gcc -o hist hist.o HistHelp.o

hist.o: hist.c
	gcc -Wall -Wextra -Werror -ansi -pedantic -c hist.c

HistHelp.o: HistHelp.c HistHelp.h
	gcc -Wall -Wextra -Werror -ansi -pedantic -c HistHelp.c


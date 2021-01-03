all:
	gcc -Wall --pedantic src/*.c -lm -o bin/gauss

test: all
	bin/gauss dane/A dane/b

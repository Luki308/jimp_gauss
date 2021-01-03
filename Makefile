all:
	gcc -g -Wall --pedantic src/*.c -lm -o bin/gauss

test: all
	bin/gauss dane/A dane/b

test_zero: all
	bin/gauss dane/A_z dane/b

test_osb: all
	bin/gauss dane/A_o dane/b
	
test_c: all
	bin/gauss dane/A_c dane/b
	
test_r: all
	bin/gauss dane/A_r dane/b
	
test_b: all
	bin/gauss dane/A dane/b_wrong
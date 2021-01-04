all:
	@mkdir -p bin
	gcc -g -Wall --pedantic src/*.c -lm -o bin/gauss

test: all
	bin/gauss dane/A dane/b
	@bin/gauss dane/A dane/b | tail -5 > tmp
	@if [ "$$(diff tmp dane/wzor_test | wc -l)" = "0" ]; then echo "Wyniki sa prawidlowe!"; else echo "Ktorys z wynikow jest bledny!"; fi
	@rm tmp

test_zero: all
	bin/gauss dane/A_z dane/b
	@bin/gauss dane/A_z dane/b | tail -5 > tmp
	@if [ "$$(diff tmp dane/wzor_test_zero | wc -l)" = "0" ]; then echo "Wyniki sa prawidlowe!"; else echo "Ktorys z wynikow jest bledny!"; fi
	@rm tmp

test_zero2: all
	bin/gauss dane/A_z2 dane/b

test_osb: all
	bin/gauss dane/A_o dane/b
	
test_c: all
	bin/gauss dane/A_c dane/b
	
test_r: all
	bin/gauss dane/A_r dane/b
	
test_b: all
	bin/gauss dane/A dane/b_wrong

test_format1: all
	bin/gauss dane/A_wrong_format1 dane/b
	
test_format2: all
	bin/gauss dane/A_wrong_format2 dane/b

test_empty: all
	bin/gauss dane/empty dane/b
	
test_letters: all
	bin/gauss dane/A_letters dane/b

#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL)
    {
		fprintf(stderr, "Nie wczytano macierzy A!\n");
	    freeMatrix(b);
        return -1;
    }
	if (b == NULL) 
    {
		fprintf(stderr, "Nie wczytano macierzy b!\n");
	    freeMatrix(A);
        return -2;
    }
    printf("Macierz A:\n");
 	printToScreen(A);
    printf("\nMacierz b:\n");
    printToScreen(b);

	res = eliminate(A,b);

	if (res == 1)
	{
		fprintf(stderr, "Błąd! Macierz osobliwa.\n");
	    freeMatrix(A);
	    freeMatrix(b);
	    return res;
	}

	x = createMatrix(b->r, 1);

	if (x != NULL)
    {
		res = backsubst(x,A,b);
		
        if (res == 1)
		{
			fprintf(stderr, "Błąd! Zachodzi dzielenie przez 0! (0 występuje na diagonali)\n");
	        freeMatrix(A);
	        freeMatrix(b);
	        freeMatrix(x);
		    return res;
		}
		else if (res == 2)
		{
			fprintf(stderr, "Błąd! Macierz nieprawidłowych rozmiarów. Macierz A musi być kwadratowa, zaś ilość wierszy macierzy b musi odpowiadać ilości kolum macierzy A!\n");
    	    freeMatrix(A);
	        freeMatrix(b);
	        freeMatrix(x);
		    return res;
		}
	
        printf("\nWynik:\n");
    	printToScreen(x);
	    freeMatrix(x);
	} 
    else 
    {
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	    freeMatrix(A);
	    freeMatrix(b);
    }

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}

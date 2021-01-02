#include "gauss.h"
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int w,k;
	for (k = 0;k < mat->c;k++)
	{
		for (int w = k + 1;w < mat->r;w++)
		{
			double skalar = mat->data[k][k]/mat->data[w][k];
				printf("wsp:%f, ", skalar);
		}
		printf("\n");
	}

		return 0;
}


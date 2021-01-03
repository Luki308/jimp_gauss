#include "gauss.h"
#include "mat_io.h"
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

void swap(double *a, double *b)
{
    double *tmp = a;
    a = b;
    b = tmp;
}


int eliminate(Matrix *mat, Matrix *b){
	for (int k = 0;k < mat->c;k++)
	{
        int kmax = 0;
        swap(mat->data[k], mat->data[kmax]);
        swap(b->data[k], b->data[kmax]);

		if (mat->data[k][k] == 0)
		{
			return 1;
		}
		else {
			for (int w = k + 1;w < mat->r;w++)
			{
				double skalar = mat->data[w][k] / mat->data[k][k];
				for (int i = k;i < mat->c;i++)
				{
					mat->data[w][i] = mat->data[w][i] - skalar * mat->data[k][i];
				}
				b->data[w][0] = b->data[w][0] - skalar * b->data[k][0];
			}
		}
	}
		return 0;
}


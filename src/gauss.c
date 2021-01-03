#include "gauss.h"
#include "mat_io.h"
#include <stdio.h>
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int k, w;
	for (k = 0;k < mat->c;k++)
	{
		double max;
		int wmax;
		wmax = k;
		max = fabs(mat->data[k][k]);

		for (w = k + 1;w < mat->r;w++)
		{
			if (max < fabs(mat->data[w][k]))
			{
				max = fabs(mat->data[w][k]);
				wmax = w;
			}
			printf("max: %f", max);
		}

		if (mat->data[k][k] == 0)
		{
			return 1;
		}
		else {
			for (w = k + 1;w < mat->r;w++)
			{
				double skalar = mat->data[w][k] / mat->data[k][k];
				int i;
				for (i = k;i < mat->c;i++)
				{
					mat->data[w][i] = mat->data[w][i] - skalar * mat->data[k][i];
				}
				b->data[w][0] = b->data[w][0] - skalar * b->data[k][0];
				printToScreen(mat);
			}
		}
	}
		return 0;
}


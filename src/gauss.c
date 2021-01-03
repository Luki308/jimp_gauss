#include "gauss.h"
#include "mat_io.h"
#include <stdio.h>
#include <math.h>

/*
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b)
{
	for (int k = 0;k < mat->c;k++)
	{
		double max = fabs(mat->data[k][k]);
		int wmax = k;
		for (int w = k + 1;w < mat->c;w++)
		{
			if (max < fabs(mat->data[w][k]))
			{
				max = fabs(mat->data[w][k]);
				wmax = w;
			}
		}
        row_swap(mat, k, wmax);
        row_swap(b, k, wmax);

		if (mat->data[k][k] == 0)
		{
			return 1;
		}
		else {
			for (int w = k + 1;w < mat->c;w++)
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

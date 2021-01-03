#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) 
{
        // TO DO: sprawdzanie rozmiarów macierzy
	for (int i = x->r - 1; i >= 0; i--) 
    {
        double sum = 0;
        for (int j = mat->c - 1; j > i; j--)
            sum += mat->data[i][j] * x->data[j][0];

        if (mat->data[i][i] == 0)
            // TO DO: komunikat?
            return -1;
        else
            x->data[i][0] = (b->data[i][0] - sum) / mat->data[i][i];
    }
	return 0;
}

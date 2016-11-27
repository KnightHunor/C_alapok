/* Laszlo Hunor
 * lzam0169
 * 611
 *
 * hozzunk etre egy n*n-et matrixot, es a transzponaltjat
 */

#include <stdio.h>
#include <stdlib.h>

void print_2Darr(int **arr, int n)
{
    int i, j;
    FILE *f = fopen("output_Gy4_2.txt", "w");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fprintf(f, "%d ", *(*(arr + i) + j));
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void free2D(int **arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {   
        free(*(arr + i));
    }
    free(arr);
}

int main()
{

    FILE *f = fopen("input_Gy4_2.txt", "r");

    int n, **a, **at;

    fscanf(f, "%d", &n);

    int i, j; /* iterators */

    /* allocate matrix and read elements */
    a = (int**)malloc(sizeof(int*) * n);

    for (i = 0; i < n; i++)
    {
        *(a + i) = (int*)malloc(sizeof(int) * n);
        for (j = 0; j < n; j++)
            fscanf(f, "%d", *(a + i) + j);
    }

    /* allocate transponate matrix and assign elements */
    at = (int**)malloc(sizeof(int*) * n);

    for (i = 0; i < n; i++)
    {
        *(at + i) = (int*)malloc(sizeof(int) * n);
        for (j = 0; j < n; j++)
            *(*(at + i) + j) = *(*(a + j) + i);
    }
    print_2Darr(at, n);

    /* cleanup */
    fclose(f);

    free2D(a, n);
    free2D(at, n);

    return 0;
}

/* Nev: Laszlo Hunor
 * Csoport: 611
 * Azonosito: lzam0169
 */

/* Matrixok szorzasa */

#include <stdio.h>

int read_matrix(int t[10][10], int *m, int *n, FILE *f)
{
    fscanf(f, "%d", m);
    fscanf(f, "%d", n);

    int i, j;

    for (i = 0; i < *m; i++)
        for (j = 0; j < *n; j++)
            fscanf(f, "%d", &t[i][j]);
}

int main()
{
    FILE *f = fopen("input_Gy3_3.txt", "r");

    int a1[10][10], m, n, a2[10][10], o, p;

    read_matrix(a1, &m, &n, f);
    read_matrix(a2, &o, &p, f);

    fclose(f); f = fopen("output_Gy3_3.txt", "w");

    int i, j, k;
    int sum;

    if (n != o)
        fprintf(f, "NEM SZOROZHATO");
    else
    {
        for (i = 0; i < m; i++)
        {
            for (k = 0; k < p; k++)
            {
                sum = 0;
                for (j = 0; j < n; j++)
                    sum += a1[i][j] * a2[j][k];
                fprintf(f, "%d ", sum);
            }
            fprintf(f, "\n");
        }
    }

    fclose(f);

    return 0;
}

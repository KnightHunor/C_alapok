/* Nev: Laszlo Hunor
 * Csoport: 611
 * Azonosito: lzam0169
 */

/* Adott egy n elemu (int) tomb, masoldjuk at egy masik tombbe azokat a 15 es 25 kozootti elemeket */

#include <stdio.h>

void read_arr(int *a, int *n)
{
    FILE *f = fopen("input_L3_1_f.txt", "r");

    fscanf(f, "%d", n);

    int i;
    for (i = 0; i < *n; i++)
        fscanf(f, "%d", a + i);
}

void new_arr(int *a, int *new_array, int n, int *new_n)
{
    *new_n = 0;

    int i;
    for (i = 0; i < n; i++)
        if (a[i] >= 15 && a[i] <= 25)
            new_array[(*new_n)++] = a[i];
}

void print_arr(int *a, int n)
{
    FILE *f = fopen("output_L3_1_f.txt", "w");

    for (int i = 0; i < n; i++)
        fprintf(f, "%d ", a[i]);
    fclose(f);
}

int main()
{
    int t[100], n;
    int a[100], m;
    
    read_arr(t, &n);
    new_arr(t, a, n, &m);
    print_arr(a, m);

    return 0;
}

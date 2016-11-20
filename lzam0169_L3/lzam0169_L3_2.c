/* Nev: lzam0169
 * Csoport: 611
 * Azonosito: lzam0169
 */

/* Olvassunk be egy n elemű egész számokból álló tömböt és egy opciót, amelyek a következők egyike:
 *    1 - Kiírás
 *    2 - i. elem modositasa (ez esetben a bemeneti állományban adjuk meg az i. elemet, illetve annak új értékét)
 *    3 - Átlag
 *    4 - Összeg
 *    5 - Kilépés
 *    
 * Olvassuk be az egész számokat, majd végezzük el a számokhoz tartozó műveletet. Hibás opció esetén írjunk ki hibaüzenetet.
 */

#include <stdio.h>

void read_arr(int *t, int *n, FILE *f)
{
    fscanf(f, "%d", n);

    int i;
    for (i = 0; i< *n; i++)
        fscanf(f, "%d", t + i);
}

int sum(int *a, int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

float avg(int *a, int n)
{   
    return ((float)(sum(a, n))/n);
}

void change_value(int *t, int i, int value)
{
    t[i - 1] = value;
}

void print_array(int *t, int n, FILE *f)
{
    int i;
    for (i = 0; i < n; i++)
        fprintf(f, "%d ", t[i]);
}

void menu(int *a, int n, FILE *f) /* f: input file */
{
    FILE *g = fopen("output_L3_2.txt", "w");

    int point, i, value;

    fscanf(f, "%d", &point);
    
    switch (point)
    {
    case 1:
        print_array(a, n, g);
        break;
    case 2:
        fscanf(f, "%d%d", &i, &value);
        change_value(a, i, value);
        print_array(a, n, g);
        break;
    case 3:
        fprintf(g, "%f", avg(a, n));
        break;
    case 4:
        fprintf(g, "%d", sum(a, n));
        break;
    case 5:
        break;
    default:
        fprintf(g, "ERROR: WRONG INPUT");
        break;
    }
    fclose(g);
}

int main()
{
    FILE *f = fopen("input_L3_2.txt", "r");
    int t[100], n;
    read_arr(t, &n, f);
    
    menu(t, n, f);

    fclose(f);
    return (0);
}

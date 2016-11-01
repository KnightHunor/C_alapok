/* Nev: Laszlo Hunor
 * Csoport: 611
 * Azonosito: lzam0169
 */

/* beolvasunk n szamot, irjuk ki a paros szamok szorzatat */

#include <stdio.h>

int ossz()
{
    int n, i, a, ossz = 1; /* osszeggel jeleolom a szorzatot */

    FILE *f = fopen("input_L2_1_a.txt", "r");

    fscanf(f, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &a);

        if (!(a%2))
            ossz *= a;
    }
    fclose (f);

    return (ossz);
}

void kiir(int a)
{
    FILE *f = fopen("output_L2_1.a.txt", "w");

    fprintf(f, "%d", a);

    fclose(f);
}

int main()
{
    kiir(ossz());

    return (0);
}

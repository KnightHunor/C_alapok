/* Nev: Laszlo Hunor
 * Csoport: 611
 * Azonosito: lzam0169
 */

/* beolvasunk n szamot, irjuk ki a paros szamok szorzatat */

#include <stdio.h>

int ossz()
{
    int n, i, a, ossz = 1, van = 0; /* osszeggel jeleolom a szorzatot */

    FILE *f = fopen("input_L2_1_a.txt", "r");

    fscanf(f, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &a);

        if (!(a%2))
        {
            van = 1;
            ossz *= a;
        }
    }
    fclose (f);

    if (!van)
        return 0;
    return (ossz);
}

void kiir(int a)
{
    FILE *f = fopen("output_L2_1_a.txt", "w");

    if (a != 0)
        fprintf(f, "%d", a);
    else
        fprintf(f, "Nincs paros szam");

    fclose(f);
}

int main()
{
    kiir(ossz());

    return (0);
}

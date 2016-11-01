/*  Nev: Laszlo Hunor
 *  Csoport: 611
 *  Azonosito: lzam0169
 */

/* Irjuk ki a kovetkezo haromszoget: */

#include <stdio.h>

int kiir()
{
    FILE *g = fopen("output_L2_3_a.txt", "w");
    char c;
    int i;

    for (i = 0; i <= 'h' - 'a' + 1; i++)
    {
        for (c = 'a'; c <='h' - i; c++)
        {
            fprintf(g, "%c", c);
        }
        fprintf(g, "\n");
    }
    fclose(g);
}

int main()
{
    kiir();

    return (0);
}

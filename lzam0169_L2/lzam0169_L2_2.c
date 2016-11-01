/* Nev: Laszlo Hunor
 * Csoport: 611
 * Azonosito: lzam0169
 */

/* Olvassunk be szamokat 0-ig. Oldjuk meg a feladatot while, do{}while es for-al is */

#include <stdio.h>

void do_while(FILE *g)
{
    FILE *f = fopen("input_L2_2.txt", "r");
    fprintf(g, "while: ");
    int a;
    fscanf(f, "%d", &a);
    while(a != 0)
    {
        fprintf(g, "%d ", a);
        fscanf(f, "%d", &a);
    }
    fprintf(g, "\n");
    fclose(f);
}

void do_do_while(FILE *g)
{
    FILE *f = fopen("input_L2_2.txt", "r");
    fprintf(g, "do while: ");
    int a;
    fscanf(f, "%d", &a);
    if (a != 0)
    {
        do
        {
            fprintf(g, "%d ", a);
            fscanf(f, "%d", &a);
        }while (a != 0);
    }
    fprintf(g, "\n");
    fclose(f);
}

void do_for(FILE *g)
{
    FILE *f = fopen("input_L2_2.txt", "r");
    fprintf(g, "for: ");
    int a;
    fscanf(f, "%d", &a);
    for (;a != 0;)
    {
        fprintf(g, "%d ", a);
        fscanf(f, "%d", &a);
    }
    fclose(f);
}


int main()
{
    FILE *g = fopen("output_L2_2.txt", "w");

    do_while(g);
    do_do_while(g);
    do_for(g);

    fclose(g);
    return (0);
}

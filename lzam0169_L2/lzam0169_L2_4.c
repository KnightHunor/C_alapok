/*  Nev: Laszlo Hunor
 *  Csoport: 611
 *  Azonosito: lzam0169
 */

/*  Dobokockas jatek */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dob(int *a, int *b)
{   
    *a = (rand() % 6) + 1;
    *b = (rand() % 6) + 1;
}

void jatek()
{
    FILE *g = fopen("output_L2_4.txt", "w");

    int jatekos = 1, kor  = 1;
    int a = 0, b = 0; /* a dobokocka szamai */

    int over = 0; /* bool */

    fprintf(g, "\t1.\t2.\t3.\t4.\t5.\n");
    for (kor = 1; kor <= 5; kor++)
    {
        fprintf(g, "%d. kor\t", kor);
        for (jatekos = 1; jatekos <= 5; jatekos++)
        {
            if (jatekos == kor)
            {
                fprintf(g, "-\t");
                continue;
            }
            else
            {
                dob(&a, &b);
                fprintf(g, "(%d, %d)\t", a, b);
                if (a == 6 && a == b)
                {
                    fprintf(g, "\nA nyertes a %d. jatekos.\n", jatekos);
                    fprintf(g, "A jatek a %d. korben ert veget.\n", kor);
                    over = 1; /* true */
                    break;
                }
            }
            if (over)
                break;
        }
        fprintf(g, "\n");
    }
    fprintf(g, "\nAz osszes jatekos nyert\n");
    fclose(g);
}

int main()
{
    srand(time(NULL)); /* to be more random */
    jatek();

    return (0);
}

/* Nev: Laszlo Hunor
 * Csoport: 611
 * Azonosito: lzam0169
 */

/* Allitsunk elo egy 150 elemu tombot veletlen egesz szamokbol -999-tol +999-ig
 * Rendezzuk ezt a tombot novekvo sorrendbe. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randnum()
{
    int sign = (rand() % 2 ? (-1) : 1);

    return (sign * rand() % 1000);

}

void generate_arr(int t[])
{
    int i;

    for (int i = 0; i < 150; i++)
        t[i] = randnum();
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int t[])
{
    int sorted;
    int k = 150;
    int i;

    do {
        sorted = 1;
        for (i = 0; i < k - 1; i++)
            if (t[i] > t[i + 1])
            {
                swap(&t[i], &t[i + 1]);
                sorted = 0;
            }
    }while (!sorted);
}

void print_arr(int t[])
{
    FILE *f = fopen("output_Gy3_1.txt", "w");
    int i;

    for (i = 0; i < 150; i++)
        fprintf(f, "%d ", t[i]);
}


int main()
{
    srand(time(NULL));

    int t[150];

    generate_arr(t);
    sort(t);
    print_arr(t);

    return 0;
}

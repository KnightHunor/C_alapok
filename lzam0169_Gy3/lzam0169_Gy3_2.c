/* Nev: Laszlo Hunor
 * Csoport: 611
 * Azonosito: lzam0169
 */

/* Adott egy string, keszitsunk rola ststisztikat */

#include <stdio.h>

void read_stat (int t[], int *count, int *spacecount)
{
    FILE *f = fopen("input_Gy3_2.txt", "r");

    char c;
    while (fscanf(f, "%c", &c) != EOF)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            (*count)++;
            t[c - 'A']++;
        }
        else if (c == ' ')
        {
            (*count)++;
            (*spacecount)++;
        }
        else
            (*count)++;
    }
}

void print_stats(int t[], int count, int spacecount)
{
    FILE *f = fopen("output_Gy3_2.txt", "w");
    
    fprintf(f, "Hossz: %d\n", count);
    fprintf(f, "Hossz (szokozok nelkul): %d\n", count - spacecount);

    int i;
    for (i = 0; i < 'z' - 'A' + 1; i++)
    {
        if (t[i] != 0)
        {
            fprintf(f, "%c - %d\n", (char)(i + 'A'), t[i]);
        }
    }
    fclose(f);
}

int main()
{
    int t['z' - 'A' + 1] = { 0 };
    int count = 0, spacecount = 0;
    
    read_stat (t, &count, &spacecount);
    print_stats (t, count, spacecount);

    return 0;
}

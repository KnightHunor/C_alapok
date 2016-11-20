/* Nev: Laszlo Hunor
 * Csoport: 611
 * Azonosito: lzam0169
 */

/* Olvassunk be egy 5x5-os matrixot, irjuk ki csigabolnaba
 * a jobb felso sarokbol lefele indulva */

#define SIZE 5

#include <stdio.h>

void read_matrix(int t[SIZE][SIZE])
{
    FILE *f = fopen("input_L3_3_f.txt", "r");
    int i, j;

    for (i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            fscanf(f, "%d", &t[i][j]);
    fclose(f);
}

int changeDir(int currDir)
{
    return (currDir + 1) % 4;
}

void solve(int t[SIZE][SIZE])
{
    FILE *f = fopen("output_L3_3_f.txt", "w");
    int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; /* down, left, up, right */
    int currDir = 0; /* 0 - Down, 1 - Left, 2 - Up, 3 - Right */

    int i = 0, j = 4; /* starting position */
    int colHeigth = 4, rowWidth = 4;
    int k;

    for (k = 0; k < 25; k++)
    {
        fprintf(f, "%d ", t[i][j]);

        i += dir[currDir][0];
        j += dir[currDir][1];

        if (i == j && j == rowWidth) /* changes direction at (4,4) and (3, 3) */
            currDir = changeDir(currDir);
        if (j == 4 - rowWidth && i == colHeigth)
        {
            colHeigth--;
            rowWidth--;
            currDir = changeDir(currDir);
        }
        if (i == 4 - (colHeigth + 1) && i == j)
        {
            currDir = changeDir(currDir);
        }
        if (j == rowWidth && i == 4 - (colHeigth + 1))
        {
            currDir = changeDir(currDir);
        }
    }
    
    fclose(f);
}

int main()
{
    int t[SIZE][SIZE];

    read_matrix(t);
    solve(t);

    return 0;
}

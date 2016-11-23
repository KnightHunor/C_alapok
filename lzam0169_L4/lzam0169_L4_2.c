/* Laszlo Hunor
 * lzam0169
 * 611
 */

/* Rendezzuk egy karakterlancokbol allo tombot abc sorrendbe */

#include <stdio.h>
#include <string.h>

void swap(char s1[], char s2[])
{
    char aux[100];
    strcpy(aux, s1);
    strcpy(s1, s2);
    strcpy(s2, aux);
}

void bubbleSort(char x[][100], int n)
{
    int sorted;
    int i;

    do{
        sorted = 1;

        for(i = 0; i < n - 1; i++)
        {
            if(strcmp(x[i], x[i + 1]) > 0)
            {
                swap(x[i], x[i + 1]);
                sorted = 0;
            }
        }
        n--;

    }while(!sorted);
}

int main()
{
    char a[100][100];
    FILE *f = fopen("input_L4_2.txt", "r");
    int i, n = 0;

    while (fscanf(f, "%s", a[n])!=EOF)
        n++;
    
    bubbleSort(a, n);
    
    fclose(f); f = fopen("output_L4_2.txt", "w");
    for (i = 0; i < n; i++)
        fprintf(f, "%s\n", a[i]);
    
    return 0;
}

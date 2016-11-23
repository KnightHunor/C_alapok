/* Laszlo Hunor
 * lzam0169
 * 611
 */

/* Olvassunk be egy karaktersort, irjuk ki i es j kozotti karaktereket */

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f = fopen("input_L4_1.txt", "r");
    
    char str[200];
    int i, j;
    fgets(str, 200, f);
    fscanf(f, "%d%d", &i, &j);
        
    fclose(f);
    f = fopen("output_L4_1.txt", "w");
    if (i > j || i > strlen(str) || j > strlen(str))
        fprintf(f, "HIBAS BEMENET");
    else
        for (int k = i - 1; k < j; k++)
            fprintf(f, "%c", str[k]);
    
    fclose(f);
    return 0;
}

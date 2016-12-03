/* Laszlo Hunor
 * lzam0169
 * 611
 *
 * hozzunk etre ket n elemu tombot, es egy harmadikat,
 * amely az elozo ketto osszeget tartalmazza 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *f = fopen("input_Gy4_1.txt", "r");

    int n, *a1, *a2, *a3;

    fscanf(f, "%d", &n);

    a1 = (int*)malloc(sizeof(int) * n);
    a2 = (int*)malloc(sizeof(int) * n);
    a3 = (int*)malloc(sizeof(int) * n);

    int i;

    for (i = 0; i < n; i++)
        fscanf(f, "%d", a1 + i);
    for (i = 0; i < n; i++)
        fscanf(f, "%d", a2 + i);
    fclose(f);
    
    for (i = 0; i < n; i++)
        *(a3 + i) = *(a1 + i) + *(a2 + i);
    
    f = fopen("output_Gy4_1.txt", "w");
    for (i = 0; i < n; i++)
        fprintf(f, "%d ", *(a3 + i));
    
    /* cleanup */
    fclose(f);

    free(a1);
    free(a2);
    free(a3);

    return 0;
}

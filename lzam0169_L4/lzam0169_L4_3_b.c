/* Laszlo Hunor
 * lzam0169
 * 611
 */

/* te->en | hogy->mu */

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f = fopen("input_L4_3_b.txt", "r");
    char s[200];
    fgets(s, 200, f);
    char *aux;
    while ((aux = strstr(s, "te")) != NULL)
    {
        strncpy(aux, "en", 2);
    }
    while((aux = strstr(s, "hogy")) != NULL)
    {
        strncpy(aux, "mu", 2);
        strcpy(aux+2, aux+4);
    }

    fclose(f);
    f = fopen("output_L4_3_b.txt", "w");
    fprintf(f, "%s", s);

    return 0;
}

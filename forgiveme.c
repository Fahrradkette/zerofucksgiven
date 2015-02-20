/*
Forgives you all the fucks you uttered.
Also empties /tmp/accumulatedfucks.
*/
#include <stdio.h>
#include <stdlib.h>

#define STOREDFUCKS "/tmp/accumulatedfucks"

void get_fucks(FILE *fp, unsigned long *fucks)
{
    rewind(fp);
    if (fread(fucks, sizeof(*fucks), 1, fp) == 1)
    {
        return;
    }
    *fucks = 0;
}

void store_fucks(FILE *fp, unsigned long *fucks)
{
    rewind(fp);
    if (fwrite(fucks, sizeof(*fucks), 1, fp) != 1)
    {
        printf("writing error\n");
        return;
    }
}

int main(void)
{
    unsigned long fucks;
    FILE *fp;
    fp = fopen(STOREDFUCKS, "r+b");
    if (fp == NULL)
    {
        fp = fopen(STOREDFUCKS, "w+b");
    }
    get_fucks(fp, &fucks);
    switch (fucks)
    {
        case 0 : printf("You shall be forgiven!\n"); break;
        case 1 : printf("Forgiving you for one lonely fuck.\n"); break;
        default : printf("All the %d f-words are forgiven.\n", fucks);
    }
    fucks = 0;
    store_fucks(fp, &fucks);
    fclose(fp);
    return EXIT_SUCCESS;
}

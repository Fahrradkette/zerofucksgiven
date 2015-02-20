/*
Tells you how much you care.
Also prints out the number of stored fucks in /tmp/accumulatedfucks
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

int main(void)
{
    unsigned long fucks;
    FILE *fp;
    fp = fopen(STOREDFUCKS, "r+b");
    if (fp == NULL)
    {
        printf("Zero fucks given!\n");
        return EXIT_SUCCESS;
    }
    get_fucks(fp, &fucks);
    switch (fucks)
    {
        case 0: printf("Not even a single one!\n"); break;
        case 1: printf("One little fuck given!\n"); break;
        default : printf("%d fucks given!\n", fucks);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

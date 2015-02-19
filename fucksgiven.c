/* TODO
check for "/tmp/accumulatedfucks" existence and readabilty
read number
print containing number
else print 0

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
        printf("Zero fucks given!");
        return EXIT_SUCCESS;
    }
    get_fucks(fp, &fucks);
    switch (fucks)
    {
        case 0: printf("Zero fucks given!\n"); break;
        case 1: printf("One single fuck given!\n"); break;
        default : printf("%d fucks given!\n", fucks);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

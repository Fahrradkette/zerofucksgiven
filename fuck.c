/* TODO
step0:
read number
add one

step1:
read argv and count containing fucks
add those

*/
#include <stdio.h>
#include <stdlib.h>

#define STOREDFUCKS "/tmp/accumulatedfucks"

void get_fucks(FILE *fp, unsigned long *fucks)
{
    rewind(fp);
    if (fread(fucks, sizeof(*fucks), 1, fp) == 1)
    {
        //printf("read returns %d\n", *fucks);
        return;
    }
    {
        *fucks = 0;
    }
}

void store_fucks(FILE *fp, unsigned long *fucks)
{
    rewind(fp);
    if (fwrite(fucks, sizeof(*fucks), 1, fp) != 1)
    {
        printf("writing error on \"%s\" \n", STOREDFUCKS);
        return;
    }
    //printf("writing %d to file\n", *fucks);
}

int main(int argc, char **argv)
{
    unsigned long fucks;
    FILE *fp;
    fp = fopen(STOREDFUCKS, "r+b");
    if (fp == NULL)
    {
        //printf("File \"%s\" doesn't exist, creating it.\n", STOREDFUCKS);
        fp = fopen(STOREDFUCKS, "w+b");
    }
    get_fucks(fp, &fucks);
    fucks += 1;
    store_fucks(fp, &fucks);
    fclose(fp);
    return EXIT_SUCCESS;
}

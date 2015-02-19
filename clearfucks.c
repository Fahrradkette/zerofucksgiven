/* TODO
step0:
check for "/tmp/accumulatedfucks" existence and writeability
write 0

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
        printf("writing error\n");
        return;
    }
    //printf("writing %d to file\n", *fucks);
}

int main(void)
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
    if (fucks == 0)
    {
        printf("0 fucks given so far!\n");
        fclose(fp);
        return EXIT_SUCCESS;
    }
    printf("Clearing %d fucks.\n", fucks);
    fucks = 0;
    store_fucks(fp, &fucks);
    fclose(fp);
    return EXIT_SUCCESS;
}

/*
Adds up all the fucks you utter and stores them in /tmp/accumulatedfucks
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("writing error on \"%s\" \n", STOREDFUCKS);
        return;
    }
}

int count_fucks(int argc, char **argv)
{
    int i;
    int count = 1;
    for (i=1; i<argc; i++)
    {
        char *slice = argv[i];
        while (slice = strstr(slice, "fuck\0"))
        {
            slice += 5;
            count += 1;
        }
    }
    return count;
}

int main(int argc, char **argv)
{
    unsigned long fucks;
    FILE *fp;
    if ((fp = fopen(STOREDFUCKS, "r+b")) == NULL)
    {
        // file didn't exist
        fp = fopen(STOREDFUCKS, "w+b");
    }
    get_fucks(fp, &fucks);
    fucks += count_fucks(argc, argv);
    store_fucks(fp, &fucks);
    fclose(fp);
    return EXIT_SUCCESS;
}

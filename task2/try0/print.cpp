#include <stdio.h>
#include "data.h"

void data::print(FILE * fp)
{
    fprintf(fp, "m = %d ", m);
    for(int i = 0; i < get_p(); i++)
    {
        if(i == M) break;
        fprintf(fp, "a[%d] = %lf ", i, a[i]);
    }
    fprintf(fp, "\n ");
}
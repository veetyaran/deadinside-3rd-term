#include <stdio.h>
#include "data.h"

void data::init(int s)
{
    m = s;
}
int data::read(FILE* fp)
{
    if(fscanf(fp, "%d", &m) != 1)
    { return -1;}
    int real_m = m;
    double trash;
    if(m > M)
    { m = M;}
    for(int i = 0; i < m; i++)
    {
        if(fscanf(fp, "%lf", a + i) != 1)
        { return -1;}
    }
    for(int i = 0; i < real_m - m; i++)
    {
        if(fscanf(fp, "%lf", &trash) != 1)
        { return -1;} 
    }
    m = real_m;
    return 0;
}
int data::p = 0;
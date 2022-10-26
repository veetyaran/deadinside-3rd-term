#include "student.h"

int createValue(int n, int s, int i)
{
    switch(s)
    {
        case 1: return i;
        case 2: return n - i;
        case 3: return i/2;
        case 4: return n - i/2;
    }
    return -1;
}


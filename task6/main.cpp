#include "list.h"

int main(int argc, char** argv)
{
    FILE* fp = fopen("test.txt", "r");
    int max = 10;
    list l;
    l.read(fp, max);
    return 0;
}
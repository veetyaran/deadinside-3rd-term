#include "list.h"

int main(int argc, char** argv)
{
    FILE* fp = fopen("test.txt", "r");
    int max = 10;
    student x;
    x.init("name", 69);
    list l;
    l.read(fp, max);
    l.popfront();
    l.print();
    l.pushfront((student&&)x);
    printf("length = %d\n", l.get_length());
    l.print();
    fclose(fp);
    return 0;
}
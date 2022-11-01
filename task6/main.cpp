#include "list.h"
#include <forward_list>

int main(int argc, char** argv)
{
    FILE* fp = fopen("test.txt", "r");
    FILE* fp1 = fopen("test1.txt", "w");
    int max = 10;
    list l;
    l.read(fp);
    l.bubbleSort();
    fprintf(fp1, "New List\n");
    l.print(100000000, fp1);
    fclose(fp);
    fclose(fp1);
    
    return 0;
}
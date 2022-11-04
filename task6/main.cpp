#include "list.h"
#include <time.h>

int main(int argc, char** argv)
{
    FILE* fp = fopen("pyramid.txt", "r");
    FILE* fp1 = fopen("result.txt", "w");
    double time;
    list l;
    l.read(fp);
    time = clock();
    //l.bubbleSort();
    //l.selectionSort();
    l.insertionSort();
    time = (clock() - time) / CLOCKS_PER_SEC;
    fprintf(fp1, "New List\n");
    l.print(100000000, fp1);
    printf("Elapsed = %.2f\n", time);
    fclose(fp);
    fclose(fp1);
    return 0;
}
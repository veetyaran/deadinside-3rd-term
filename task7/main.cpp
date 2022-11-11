
#include "2tree.h"
#include "stdio.h"
#include <time.h>

int main(int argc, char** argv)
{
    unsigned ret0 = 0, ret = 0, height = 0, maxSizeofLevel = 0, parentsWithOneChild = 0;
    double time = 0, time1 = 0, time2 = 0, time3 = 0, time5 = 0;
    FILE * fp = fopen("nv_10000000.txt", "r");
    tree semen;
    semen.read(fp);// Было 3 с половой на первой задаче
    semen.print(0);
    time = clock();
    ret0 = semen.countLeafNodes();
    time = (clock() - time)/CLOCKS_PER_SEC;
    time1 = clock();
    ret = semen.countMaxLRDiff();
    time1 = (clock() - time1) /   CLOCKS_PER_SEC;
    time2 = clock();
    height = semen.countTreeHeight();
    time2 = (clock() - time2) / CLOCKS_PER_SEC;
    time3 = clock();
    maxSizeofLevel = semen.countMaxLevelSize();
    time3 = (clock() - time3)/CLOCKS_PER_SEC;
    time5 = clock();
    parentsWithOneChild = semen.countParentsWithOneChild();
    time5 = (clock() - time5)/CLOCKS_PER_SEC;
    printf("This tree contains %d leaves\nElapsed = %.2f\n", ret0, time);
    printf("Max LR Diff in this tree is %d\nElapsed = %.2f\n", ret, time1);
    printf("This tree is %d levels high\nElapsed = %.2f\n", height, time2);
    printf("This tree has a level %d elements as a maximum\nElapsed = %.2f\n", maxSizeofLevel, time3);
    printf("This tree has %d elements with one child\nElapsed = %.2f\n", parentsWithOneChild, time5);
    fclose(fp);
    return 0;
}
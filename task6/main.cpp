#include "list2.h"

int main(int argc, char** argv)
{
    int k = 4;
    FILE* fp = fopen("test.txt", "r");
    list2 l;
    l.read(fp, 10);
    list2_node* x = l.jumpTo(2);
    list2_node* y = l.jumpTo(4);
    l.solveProblem3(2);
    l.print();
    printf("length = %d\n", l.get_length());
    fclose(fp);
    return 0;
}
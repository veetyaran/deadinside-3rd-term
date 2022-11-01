#include "list.h"

io_status read (FILE *fp = stdin, unsigned int max_read = -1)
{
    unsigned int counter = 0;
    char* name = nullptr;
    int value = 0;
    while(fscanf(fp, "%s%d", name, &value) == 2 && counter != max_read)
    {
        printf("read successful\n");
        ++counter;
    }
    return io_status::success;
}
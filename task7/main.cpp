#define private public
#include "2tree.h"
#include "stdio.h"
#include <time.h>

#define PROFILE(argv0, task, code) \
{ \
    double t = clock(); \
    auto return_value = code; \
    t = (clock() - t) / CLOCKS_PER_SEC; \
    printf("%s : Task = %d Result = %d Elapsed = %.2f\n", argv0, task, return_value, t); \
}

int main(int argc, char** argv)
{
    int r = 0;
    const char* filename = nullptr;
    FILE* fp = nullptr;
    io_status errorstatus = io_status::success;
    if (argc != 3)
        return exitcode(io_status::format);

    if (!(sscanf(argv[1], "%d", &r) == 1))
    {
        return exitcode(io_status::format);
    }
    filename = argv[2];

    fp = fopen(filename, "r");
    if (!fp)
        return exitcode(io_status::opent);

    tree T;
    errorstatus = T.read(fp);
    if (errorstatus == io_status::format)
    {
        fclose(fp);
        return exitcode(errorstatus);
    }

    printf("Tree:\n");
    T.print(r);

    PROFILE(argv[0], 1, T.countLeafNodes());
    PROFILE(argv[0], 2, T.countTreeHeight());
    PROFILE(argv[0], 3, T.countMaxLevelSize());
    PROFILE(argv[0], 4, T.countMaxLRDiff());
    PROFILE(argv[0], 5, T.countParentsWithOneChild());

    fclose(fp);
    return 0;
}
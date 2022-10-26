#include "student.h"

int solveProblem1(student* array, int size, student& x)
{
    int head = 0, tail = size, mid;
    while(head != tail)
    {   
        mid = (head + tail)/2;
        if(x > array[mid])
            head = mid + 1;
        else
            tail = mid;
    }
    return head;
}


int main(int argc, char** argv)
{
    int n, s, p, smvalue;
    char* smname, filename; 
    student sm1;

    if(argc == 5)
    {
        if(sscanf(argv[1], "%s%d", smname, &smvalue) != 2 || sscanf(argv[2], "%d", &n) != 1 || sscanf(argv[3], "%d", &p) != 1 || sscanf(argv[4], "%d", &s) || n < 0 || p < 0 || s < 0 || s > 4)
        {
            printf("Usage: x(\"<name> <value>\") n p s(integer from 0 to 4) filename");
            return static_cast<int>(io_status::format);
        }
        else
        {
            if(argc == 6 && s == 0)
            {
                filename = argv[5];
            }

        }
    }
    

}
#include <stdio.h>
#include <time.h>
#include "error.h"
#include "data_array.h"
#include "data.h"
#define TASK 1

int findPlaceForX(const data_array &array, data& x);
int main(int argc, char** argv)
{
    char *filename = nullptr, *filename_x = nullptr;
    double t;
    int n, s, p, diff, res = 0;
    if((argc != 5)&&(argc != 6)) 
    {
        printf("invalid number of arguments\n");
        return INVALID_NUM_OF_ARGUMENTS;
    }
    filename_x = argv[1];
    if (
        (sscanf(argv[2], "%d", &n) != 1 || n < 0) ||
        (sscanf(argv[3], "%d", &p) != 1 || p < 0) ||
        (sscanf(argv[4], "%d", &s) != 1 || s > 4 || s < 0)
    ) {
        puts("input error");
        return INPUT_ERROR;
    }
    //memory alloc for the data type array
    data_array array(n);

    if(n != 0) array.get_ptr()[0].set_p(p);
    if(!s)
    {    //initialisation of data_array elements from the file
        if(argc == 6)
        {
            filename = argv[5];
        }
        else{ return -1; }
        if(array.readDataArray(filename) != 1)
        {
            printf("READ ERROR\n");
            return -1;
        }
    }
    else
    {    //initialisation of data_array elements from using a formulae
        array.initDataArray(s);
    }
    data x;
    FILE* fp_x = fopen(filename_x, "r");
    if(!fp_x)
    {
        printf("cannot open file with data X\n");
        return -1;
    }
    if(x.read(fp_x) == 0)
    {
        printf("Array:\n");
        array.printDataArray(p);
        t = clock();
        res = findPlaceForX(array, x);
        t = (clock() - t)/CLOCKS_PER_SEC;
        
    }
    else{printf("cannot read data X from opened file");}
    printf("New array:\n");
    array.printDataArray(p);
    diff = array.find_diff();
    printf ("%s : Task = %d Diff = %d Res = %d Elapsed = %.2f\n", argv[0], TASK, diff, res, t);
    return 0;
}
int findPlaceForX(const data_array &array, data& x)
{
    int n = array.get_size_();
    int head = 0, tail = n - 1, mid = 0;
    //if(array.get_ptr()[head] > array.get_ptr()[tail]) return -1;
        while (head != tail)
        {
            mid = (tail + head)/2;
            if(x > array.get_ptr()[mid])
		{
			head = mid + 1;
		}
		else
		{
			tail = mid;
		}          
        }
        printf("%d\n", array.get_ptr()[head].get_n());
        if((head == n - 1) && (x > array.get_ptr()[n - 1]))
	{
		return head + 1;
	}
    return head;
}
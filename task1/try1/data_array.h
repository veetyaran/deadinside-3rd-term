#ifndef data_array_H

#include <stdio.h>
#include "data.h"

class data_array
{
    private:
        data* ptr = nullptr;
        int n = 0;
        int p = 0;
        int s = 0;
    public:
    data_array() = default;
    ~data_array() = default;
    void printDataArray(FILE* fp = stdout);
};
void printDataArray(FILE* fp)
{
    for(int i = 0; i < data_array->p; i++)
    {
        if(i == data_array->n) break;
        data_array->ptr[i].print(fp);
    }  
    return;
}

/*data_array()
{
    for(int i = 0; i < n; i++)
    {
        data_array[i].m = 0;
        data_array
    }
}*/
#endif
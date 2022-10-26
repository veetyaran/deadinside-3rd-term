#include "data_array.h"

double f(int s, int n, int i);

void data_array::printDataArray(int maxsize, FILE* fp)
{
    for(int i = 0; i < maxsize; i++)
    {
        if(i == size_) break;
        ptr_[i].print(fp);
    }  
    return;
}

//data_array constructor
data_array::data_array(int size)
{
    ptr_ = new data[size];
    size_ = size;   
}
//data_array destructor;
data_array::~data_array()
{
    delete[]ptr_;
}
//data_array copy constructor


int data_array:: readDataArray(const char* filename)
{
    FILE* fp;
    fp  = fopen(filename, "r");
    if(!fp)
    {
        return -1;
    }
    for(int i = 0; i < size_; i++)
    {
        if(ptr_[i].read(fp) != 1)
        { 
            fclose(fp);
            return -1;
        }
    }
    fclose(fp);
    return 1;
}
void data_array:: initDataArray(int s)
{
    for(int i = 0; i < size_; i++)
    {
        ptr_[i].init(f(s, get_size_(), i));
    }
}
 int data_array:: find_diff()
 {
    int diff = 0;
    if(size_ < 2)
    {return 0;}
    for(int i = 1; i < size_; i++)
    {
        if(ptr_[i] < ptr_[i - 1])
        {
            diff++;
        }
    }
    return diff;
 }
double f(int s, int n, int i)
{
    i++;
    switch(s)
    {
        case 1: return i;
        case 2: return n - i;
        case 3: return (double)i / 2;
        case 4: return (double)n - (double)i / 2;
    }
    return 0;
}
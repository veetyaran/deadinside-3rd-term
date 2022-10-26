#ifndef data_array_H
#define data_array_H
#include "data.h"

class data_array
{
    private:
        data* ptr_ = nullptr;
        int size_ = 0;
    public:
        data_array(int n);
        ~data_array();
        //copy ctor
        data_array(const data_array &array) = delete;
        //operator=
        data_array& operator= (const data_array&) = delete;

        void printDataArray(int maxsize, FILE* fp = stdout);
        data* get_ptr()const {return ptr_;}
        smileyface readDataArray(FILE* fp = stdin);
        void initDataArray(int s);
        int find_diff()const;
        int get_size_() const { return size_;}
};

void data_array::printDataArray(int maxsize, FILE* fp)
{
    for(int i = 0; i < (maxsize < size_ ? maxsize :  size_); i++)
    {
        get_ptr()[i].data::print(fp);
    }
}

smileyface data_array::readDataArray (FILE* fp)
{
    for(int i = 0; i < size_; i++)
    {
        if(get_ptr()[i].read(fp) != static_cast<int>(smileyface::nice))
        return smileyface::readnt;
    }
    return smileyface::nice;
}

void data_array::initDataArray (int s)
{
    for(int i = 0; i < size_; i++)
    {
        get_ptr()[i].init(s);
    }
}

int data_array::find_diff()const
{
    int count = 0;
    for(int i = 0; i < size_; i++)
    {
        if(ptr_[i - 1] > ptr_[i]) count++;
    }
    return count;
}

#endif
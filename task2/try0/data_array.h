#ifndef data_array_H
#define data_array_H
#include <stdio.h>
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
        int readDataArray(const char* filename);
        void initDataArray(int s);
        int find_diff();
        int get_size_() const { return size_;}
};
#endif
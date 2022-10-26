#include "student.h"

class student_array
{
private://
    student* ptr_ = nullptr;
    int size_ = 0;
public://
    student_array(int size);
    ~student_array();
    //copy ctor
    student_array(const student_array &array);
    //operator= overload
    student_array& operator= (const student_array&) = delete;
    //get a pointer to a certain student
    student* get_ptr()const{return ptr_;}
    //get size_
    int get_size()const {return size_;}
    //function for the "diff" slot in output
    int find_diff()const;
};

//s_a ctor
student_array::student_array(int size)
{
    ptr_ = new student[size];
    size_ = size;
}
//s_a ~ctor
student_array::~student_array()
{
    delete[]ptr_;
}
//copy ctor
student_array::student_array(const student_array &array)
{
    student_array* copy = new student_array(size_);
    for(int i = 0; i < size_; i++)
    {
        copy.get_ptr()[i];
    }
}

#ifndef LIST_H
#define LIST_H
#include "student.h"
class list_node : public student
{
private:
	list_node * next = nullptr;
public:
	list_node() = default;
	~list_node() = default;
	list_node(const list_node& x) = delete;
    list_node* get_next(){return next;}
friend class list;
};

class list
{
private:
list_node * head = nullptr;
public:
	list() = default;
	~list()
    {
        list_node *current, *next;
        for(current = head; current; current = next)
        {
            next = current->get_next();
            delete current;
        }
    }
	list(const list& x) = delete;
	list(list&& x) = delete;
	int read (FILE *fp = stdin, unsigned int max_read = -1);
	void print (unsigned int r = 10, FILE *fp = stdout);
	unsigned int get_length ();
};
#endif
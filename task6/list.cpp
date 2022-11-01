#include "list.h"
#include <utility>

list_node::list_node (list_node&& x)
{
    swap(x);
    std::swap(next, x.next);
}

io_status list::read (FILE *fp, unsigned int max_read)
{
    unsigned int counter = 0;
    list_node tmp;
    list_node** p_current = &head;
    io_status errorstatus = io_status::success; 

    if(!fp)
        return io_status::memory;
    
    while((errorstatus = tmp.read(fp)) == io_status::success && counter != max_read)
    {
        (*p_current) = new list_node((list_node&&)tmp);
        if(!(*p_current))
            return io_status::memory;
        p_current = &((*p_current)->next);
        printf("read successful\n");
        ++counter;
    }
    return errorstatus;
}
void list::print(unsigned int r, FILE *fp)
{
    list_node* current = head;
    unsigned int i = 0;
    for(current = head; current && i < r; i++, current = current->next)
    {
        (*current).print(fp);
    }
}

unsigned int list::get_length()
{
    unsigned int counter = 0;
    list_node* current = head;
    while(current)
    {
        ++counter;
        current = current->next;
    }
    return counter;
}

list_node* list::get_tail()
{
    list_node* tail;
    for(list_node* current = head; current; current = current->next)
    {
        if(current->next == nullptr)
            tail = current;
    }
    return tail;
}

void list::popNext(list_node* x)
{
    if(x->next == nullptr)
        return;
    if(x->next->next == nullptr)
    {
        delete x->next->next;
        x->next = nullptr;
        return;
    }
    x->next = x->next->next;
    delete x->next;
    return;
}
void list::addNext(list_node* x, list_node* newnode)
{
    newnode->next = x->next;
    x->next = newnode;
}
void list::popfront()
{
    list_node* buf;
    buf = head;
    head = head->next;
    delete buf;
    return;
}
void list::pushfront(student&& x)
{
    list_node* newnode = new list_node((list_node&&)x);
    newnode->next = head;
    head = newnode;
    return;
}
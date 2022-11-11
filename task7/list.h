#ifndef LIST_H
#define LIST_H

template <class T> 
struct list_node
{
	T value;
	list_node<T>* next = nullptr;
	list_node<T>* prev = nullptr;
};

template <class T>
class list
{
public:
    list() = default;
	~list() = default;
	list_node<T>* head = nullptr;
	list_node<T>* tail = nullptr;
	unsigned int size = 0;
    void push(T k)
	{
		list_node<T>* node = new list_node<T>;
		node->value = k;
		++size;
		list_node<T>* tmp;
		tmp = head;
		head = node;
		if(tail == nullptr)
			tail = head;
		node->next = tmp;
		node->prev = nullptr;
		if(tmp != nullptr)
			tmp->prev = node;
		return;
	}
 
    T pop()
	{
		T ret;
		list_node<T>* buf;
		buf = head;
		head = head->next;
		if(head)
			head->prev = nullptr;
		ret = (T&&)buf->value;
		delete buf;
		--size;
		return ret;
	}
	T popback()
	{
		T ret;
		list_node<T>* buf;
		buf = tail;
		tail = buf->prev;
		if(tail)
			tail->next = nullptr;
		else {head = nullptr;}
		ret = (T&&)buf->value;
		delete buf;
		--size;
		return ret;
	}
	bool isEmpty()const
	{
		return head == nullptr;
	}
};
#endif
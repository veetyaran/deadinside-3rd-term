#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef STUDENT_H
#define STUDENT_H
#define LEN 1234
enum class io_status
{
	success,
	read,
	memory,
	eof,
	open,
	format,
};
void errors(io_status ret);
class student
{
	private:
		char * name = nullptr;
		int value = 0;
	public:
		student () = default;
		student (const student& x) = delete;
		student (student&& x) 
		{
			name = x.name; x.name = nullptr;
			value = x.value; x.value = 0;
		}
		~student (){erase();}
		student& operator= (const student& x) = delete;
		student& operator= (student&& x)
		{
			if (this == &x)
				return *this;
			erase ();
			name = x.name; x.name = nullptr;
			value = x.value; x.value = 0;
			return *this;
		}		
		int get_value() const {return value;}
		char* get_name() const {return name;}
		void set_value(int v) {value = v;}
		void set_name(char* n) {name = n;}
		void print () const{printf("%s %d\n", name, value);}
		int cmp (const student& x) const
		{
			if (name == nullptr)
			{
				if (x.name != nullptr)
					return 1;
				return value - x.value;
			}
			if (x.name == nullptr)
				return -1;
			int res = strcmp (name, x.name);
			if (res)
				return res;
			return value - x.value;
		}
		int operator< (const student& x) const { return cmp (x) < 0; }
		int operator<= (const student& x) const { return cmp (x) <= 0; }
		int operator> (const student& x) const { return cmp (x) > 0; }
		int operator>= (const student& x) const { return cmp (x) >= 0; }
		int operator== (const student& x) const { return cmp (x) == 0; }
		int operator!= (const student& x) const { return cmp (x) != 0; }
		io_status read(FILE * fp = stdin)
		{
			char n[LEN];
			int v;
			if(fscanf (fp, "%s%d", n, &v) != 2)
			{
				if(! feof (fp))
					return io_status::format;
				return io_status::eof;
			}
			erase();
			return init (n, v);
		}
	private:
		void erase()
		{
			value = 0;
			if (name != nullptr)
			{
				delete [] name;
				name = nullptr;
			}
		}
		io_status init (const char * n, int v)
		{
			value = v;
			if (n != nullptr)
			{
				size_t len = strlen (n);
				name = new char [len + 1];
				if (name != nullptr)
				{
					for (size_t i = 0; i <= len; i++)
						name[i] = n[i];
				}
				else
					return io_status::memory;
			}
			return io_status::success;
		}
};
class tree_node : public student
{
	private:
		tree_node * down = nullptr;
		tree_node * level = nullptr;
	public:
		tree_node () = default;
		tree_node (const tree_node& x) = delete;
		tree_node (tree_node&& x) : student ((student&&)x)
		{
			erase_links ();
			x.erase_links ();
		}
		~tree_node ()
		{
			erase_links ();
		}
		tree_node& operator= (const tree_node& x) = delete;
		tree_node& operator= (tree_node&& x)
		{
			if (this == &x)
				return *this;
			(student&&) *this = (student&&) x;
			erase_links ();
			x.erase_links ();
			return *this;
		}
		friend class tree;
	private:
		void erase_links ()
		{
			down = nullptr;
			level = nullptr;
		}
};
class tree
{
	private:
		tree_node * root = nullptr;
	public:
		tree () = default;
		tree (const tree& x) = delete;
		tree (tree&& x)
		{
			root = x.root; x.root = nullptr;
		}
		~tree ()
		{
			delete_subtree (root);
			root = nullptr;
		}
		tree& operator= (const tree& x) = delete;
		tree& operator= (tree&& x)
		{
			if (this == &x)
				return *this;
			delete_subtree (root);
			root = x.root; x.root = nullptr;
			return *this;
		}
		void print (unsigned int r = 10) const
		{
			print_subtree (root, 0, r);
		}
		io_status read (FILE * fp = stdin);
		tree_node* get_root(){return root;}
	private:
		static void delete_subtree (tree_node *curr)
		{
			if (curr == nullptr)
				return;
			tree_node *p, *next;
			for(p = curr->down; p; p = next)
			{
				next = p->level;
				delete_subtree (p);
			}
			delete curr;
		}
		static void print_subtree (tree_node * curr, int level, int r)
		{
			if (curr == nullptr || level > r)
				return;
			int spaces = level * 2;
			for(int i = 0; i < spaces; i++)
				printf (" ");
			curr->print ();
			for(tree_node * p = curr->down; p; p = p->level)
				print_subtree (p, level + 1, r);
		}
		static void add_node_subtree (tree_node* curr, tree_node* x)
		{
			if (curr->down == nullptr)// No any child node
			{
				curr->down = x;
				return;
			}
			if (*x < *curr)
			{
				if (*curr->down < *curr) // head of the list of child nodes < *curr
					add_node_subtree (curr->down, x);
				else
				{
					x->level = curr->down;
					curr->down = x;
				}
			}
			else if (*x == *curr)
			{
				if (curr->down->level != nullptr)
				{
					x->level = curr->down->level;
					curr->down->level = x;
				}
				else if (*curr->down < *curr)
				{
					curr->down->level = x;
				}
				else
				{
					x->level = curr->down;
					curr->down = x;
				}
			}
			else // *x > *curr
			{
				tree_node * p;
				for (p = curr->down; p->level; p = p->level);
				if (*p > *curr)	// tail of the list of child nodes > *curr
					add_node_subtree (p, x);
				else
					p->level = x; // append at end of the list
			}
		}
	public:
		int get_len_tree(tree_node *curr, int i);
		void len_subtree_levels(tree_node *curr, int *lvl, int i);
		int task01(int k);
		int f01(tree_node *curr, int k);
		int task02(int k);
		int f02(tree_node *curr, int k, int *res);
		int task03(int k);
		int f03(tree_node *curr, int k, int *res, int *i);		
		int task04(int k);
		int f04(tree_node *curr, int *lvl, int k);	
		int task05(int k);
		int f05(tree_node *curr, int k, int level);
		int task06(int k);
		int f06(tree_node *curr, int k, int level);
};
#endif

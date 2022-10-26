#include "data_array.h"
int f(int s, int n, int i)
{
	switch(s)
	{
		case 1:
			return i;
		case 2:
			return n - i;
		case 3:
			return i / 2;
		case 4:
			return n - i / 2;	
		default:
			return 0;
	}
}
int read_array(data* data_arr, int n, const char* filename)
{
	FILE* fp;
	if(!(fp = fopen(filename, "r")))
	{return ERROR_OPEN;}
	for (int i = 0; i < n; i++)
	{
		if(data_arr[i].read(fp) != SUCCESS)
		{
			fclose(fp);
			return ERROR_READ;
		}
	}
	fclose(fp);
	return SUCCESS;
}
void init_array(data* data_arr, int n, int s)
{
	for(int i = 0; i < n; i++)
	{
		data_arr[i].init(f(s, n, i));
	}
}
void print_array(data* data_arr, int n)
{
	int copy_p = data:: get_p();
	int print_size = ((n > copy_p)? copy_p : n);
	for(int i = 0; i < print_size; i++)
	{
		data_arr[i].print();
	}
}
int diff(data* data_arr, int n)
{
	int k = 0;
	if(n < 2)
	{ return 0;}
	for(int i = 1; i < n; i++)
	{
		if(data_arr[i] < data_arr[i - 1])
			k++;
	}
	return k;
}
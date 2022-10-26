#include "sort.h"
#include <time.h>
//1) n – размерность массива,
//2) p – количество выводимых значений в массиве,
//3) s – задает номер формулы для инициализации массива, должен быть равен 0 при вводе массива из файла,
//4) filename – имя файла, откуда надо прочитать массив. Этот аргумент отсутствует, если s!= 0.

// ./a08.out n p s filename
int data:: p = 0;
int main(int argc, char *argv[])
{
	double t;
	int dif;
	char* filename;
	size_t n, s, q;
	if((argc != 4 && argc != 5)
		|| sscanf(argv[1], "%lu", &n) != 1
		|| sscanf(argv[2], "%lu", &q) != 1
		|| sscanf(argv[3], "%lu", &s) != 1
		|| s > 4)
	{
		printf("Usage: %s n p s filename\n", argv[0]);
		return -1;
	}
	data:: set_p(q);
	data* data_arr_a = new data [n];
	if(!data_arr_a)
	{
		printf("ERROR: Cannot allocate memory\n");
		return -1;
	}
	if(!s)
	{
		filename = argv[4];
		if(errors_array(read_array(data_arr_a, n, filename)) != SUCCESS)
		{ 
			delete data_arr_a;
			return -1;
		}
	}
	else
	{
		init_array(data_arr_a, n, s);
	}
	data* data_arr_b = new data [n];
	if(!data_arr_b)
	{
		printf("ERROR: Cannot allocate memory\n");
		delete data_arr_a;
		return -1;
	}
	printf("Array:\n");
	print_array(data_arr_a, n);
	t = clock_t();
	sort08(data_arr_a, n, data_arr_b);
	t = (clock_t()- t) / CLOCKS_PER_SEC;
	printf("New array:\n");
	print_array(data_arr_a, n);
	dif = diff(data_arr_a, n);
	printf ("%s : Task = %d Diff = %d Elapsed = %.2f\n", argv[0], 8, dif, t);
	delete data_arr_a;
	delete data_arr_b;
	return 0;
}
#include "sort.h"
#include <time.h>
//1) filename1 – дополнительный аргумент (x – имя файла, откуда надо прочитать один объект типа data)
//2) n – размерность массива,
//3) p – количество выводимых значений в массиве,
//4) s – задает номер формулы для инициализации массива, должен быть равен 0 при вводе массива из файла,
//5) filename2 – имя файла, откуда надо прочитать массив. Этот аргумент отсутствует, если s!= 0 .

// ./a01.out filename1 n p s filename2
int data:: p = 0;
int main(int argc, char *argv[])
{
	double t;
	int dif, res;
	char* filename1, * filename2;
	FILE* file1;
	size_t n, s, q;
	data x;
	if(argc != 5 && argc != 6)
	{
		printf("Usage: %s filename1 n p s filename2\n", argv[0]);
		return -1;
	}
	filename1 = argv[1];
	if(sscanf(argv[2], "%lu", &n) != 1
		|| sscanf(argv[3], "%lu", &q) != 1
		|| sscanf(argv[4], "%lu", &s) != 1 || s > 4)
	{
		printf("Usage: %s filename1 n p s filename2\n", argv[0]);
		return -1;
	}
	data:: set_p(q);
	data* data_arr = new data [n];
	if(!data_arr)
	{
		printf("ERROR: Cannot allocate memory\n");
		return -1;
	}
	if(!(file1 = fopen(filename1, "r")))
	{
		printf("ERROR: Cannot open\n");
		return -1;
	}
	if(errors_array(x.read(file1)) != SUCCESS)
	{ 
		delete data_arr;
		return -1;
	}
	if(!s)
	{
		filename2 = argv[5];
		if(errors_array(read_array(data_arr, n, filename2)) != SUCCESS)
		{ 
			delete data_arr;
			return -1;
		}
	}
	else
	{
		init_array(data_arr, n, s);
	}
	printf("Array:\n");
	print_array(data_arr, n);
	t = clock_t();
	res = sort01(data_arr, n, x);
	t = (clock_t()- t) / CLOCKS_PER_SEC;
	dif = diff(data_arr, n);
	printf ("%s : Task = %d Diff = %d Res = %d Elapsed = %.2f\n", argv[0], 1, dif, res, t);
	delete data_arr;
	return 0;
}
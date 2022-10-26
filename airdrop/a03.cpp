#include "sort.h"
#include <time.h>
//1) m – дополнительный аргумент (m целое число – индекс элемента в массиве (m= 0, . . . ,n−1)),
//2) n – размерность массива,
//3) p – количество выводимых значений в массиве,
//4) s – задает номер формулы для инициализации массива, должен быть равен 0 при вводе массива из файла,
//5) filename – имя файла, откуда надо прочитать массив. Этот аргумент отсутствует, если s!= 0.

// ./a03.out m n p s filename
int data:: p = 0;
int main(int argc, char *argv[])
{
	double t;
	int dif, res;
	char* filename;
	size_t m, n, q, s;
	if((argc != 5 && argc != 6)
		||sscanf(argv[1], "%lu", &m) != 1
		|| sscanf(argv[2], "%lu", &n) != 1
		|| sscanf(argv[3], "%lu", &q) != 1
		|| sscanf(argv[4], "%lu", &s) != 1
		|| s > 4)
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
	if(!s)
	{
		filename = argv[5];
		if(errors_array(read_array(data_arr, n, filename)) != SUCCESS)
		{ 
			delete data_arr;
			return -1;
		}
	}
	else
	{
		init_array(data_arr, n, s);
	}
	data& x = data_arr[m]; /////ссылка на a[m]
	printf("Array:\n");
	print_array(data_arr, n);
	t = clock_t();
	res = sort03(data_arr, x, n);
	t = (clock_t()- t) / CLOCKS_PER_SEC;
	printf("New array:\n");
	print_array(data_arr, n);
	dif = diff(data_arr, n);
	printf ("%s : Task = %d Diff = %d Res = %d Elapsed = %.2f\n", argv[0], 3, dif, res, t);
	delete data_arr;
	return 0;
}
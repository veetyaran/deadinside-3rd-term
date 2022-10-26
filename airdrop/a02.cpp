#include "sort.h"
#include <time.h>
//1) n – размерность массива a,
//2) pa – количество выводимых значений в массиве a,
//3) sa – задает номер формулы для инициализации массива a , должен быть равен 0 при вводе массива из файла,
//4) filenamea – имя файла, откуда надо прочитать массив. Этот аргумент отсутствует, если sa!= 0,
//5) m – размерность массива b,
//6) pb – количество выводимых значений в массиве b,
//7) sb – задает номер формулы для инициализации массива b, должен быть равен 0 при вводе массива из файла,
//8) filenameb – имя файла, откуда надо прочитать массив. Этот аргумент отсутствует, еслиsb!= 0.

// ./a02.out n pa sa filename1 m pb sb filename2

int data:: p = 0;
int main(int argc, char *argv[])
{
	double t;
	int dif;
	char* filename_a, * filename_b;
	size_t n, pa, sa, m, pb, sb, i = 4;
	//array a
	if((argc != 9 && argc != 8 && argc != 7)
		||sscanf(argv[1], "%lu", &n) != 1
		|| sscanf(argv[2], "%lu", &pa) != 1
		|| sscanf(argv[3], "%lu", &sa) != 1 || sa > 4)
	{
		printf("Usage: %s n pa sa filename_a m pb sb filename_b\n", argv[0]);
		return -1;
	}
	data:: set_p(pa);
	data* data_arr_a = new data [n];
	if(!data_arr_a)
	{
		printf("ERROR: Cannot allocate memory\n");
		return -1;
	}
	if(!sa)
	{
		filename_a = argv[4];
		if(errors_array(read_array(data_arr_a, n, filename_a)) != SUCCESS)
		{ 
			delete data_arr_a;
			return -1;
		}
		i = 5;
	}
	else
	{
		init_array(data_arr_a, n, sa);
	}
	printf("Array_a:\n");
	print_array(data_arr_a, n);
	//array b
	if( sscanf(argv[i], "%lu", &m) != 1
	|| sscanf(argv[i + 1], "%lu", &pb) != 1
	|| sscanf(argv[i + 2], "%lu", &sb) != 1 || sb > 4)
	{
		printf("Usage: %s n pa sa filename_a m pb sb filename_b\n", argv[0]);
		delete data_arr_a;
		return -1;
	}
	data:: set_p(pb);
	data* data_arr_b = new data [m];
	if(!data_arr_b)
	{
		printf("ERROR: Cannot allocate memory\n");
		delete data_arr_a;
		return -1;
	}
	if(!sb)
	{
		filename_b = argv[i + 3];
		if(errors_array(read_array(data_arr_b, m, filename_b)) != SUCCESS)
		{ 
			delete data_arr_a;
			delete data_arr_b;
			return -1;
		}
	}
	else
	{
		init_array(data_arr_b, m, sb);
	}
	printf("Array_b:\n");
	print_array(data_arr_b, m);
	//array_c
	data:: set_p(pa + pb);
	data* data_arr_c = new data [n + m];
	if(!data_arr_c)
	{
		printf("ERROR: Cannot allocate memory\n");
		delete data_arr_a;
		delete data_arr_b;
		return -1;
	}
	t = clock_t();
	sort02(data_arr_a, n, data_arr_b, m, data_arr_c);
	t = (clock_t()- t) / CLOCKS_PER_SEC;
	printf("New array:\n");
	print_array(data_arr_c, n + m);
	dif = diff(data_arr_c, n + m);
	printf ("%s : Task = %d Diff = %d Elapsed = %.2f\n", argv[0], 2, dif, t);
	delete data_arr_a;
	delete data_arr_b;
	delete data_arr_c;
	return 0;
}
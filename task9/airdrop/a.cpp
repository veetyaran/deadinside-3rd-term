#include "student.h"
#include <time.h>
//1) r – количество выводимых уровней в дереве,
//2) filename – имя файла, откуда надо прочитать дерево,
//3) k – параметр задачи.
//./a.out r name.txt

int main(int argc, char *argv[])
{
	double t = 0;
	char *name = 0;
	int r = 0, k = 0, res = 0;
	io_status ret;	
	if(argc != 4 || sscanf(argv[1], "%d", &r) != 1 || sscanf(argv[3], "%d", &k) != 1)
	{
		printf("Usage: %s r file\n", argv[0]);
		return -1;
	}
	name = argv[2];
	FILE* fp = fopen(name, "r");
	if(!fp)
	{
		ret = io_status:: open;
		errors(ret);
		return -1;
	}
	tree my_tree;
	ret = my_tree.read(fp);
	if(ret != io_status:: success)
	{
		fclose(fp);
		errors(ret);
		return -1;
	}
	printf("Tree:\n");
	my_tree.print(r);
//task01
	t = clock();
	res = my_tree.task01(k);
	t = (clock()- t) / CLOCKS_PER_SEC;
	printf ("%s : Task = %d k = %d Result = %d Elapsed = %.2f\n", argv[0], 1, k, res, t);

//task02
	t = clock();
	res = my_tree.task02(k);
	t = (clock()- t) / CLOCKS_PER_SEC;
	printf ("%s : Task = %d k = %d Result = %d Elapsed = %.2f\n", argv[0], 2, k, res, t);

//task03
	t = clock();
	res = my_tree.task03(k);
	t = (clock()- t) / CLOCKS_PER_SEC;
	printf ("%s : Task = %d k = %d Result = %d Elapsed = %.2f\n", argv[0], 3, k, res, t);

//task04
	t = clock();
	res = my_tree.task04(k);
	t = (clock()- t) / CLOCKS_PER_SEC;
	printf ("%s : Task = %d k = %d Result = %d Elapsed = %.2f\n", argv[0], 4, k, res, t);
	
//task05
	t = clock();
	res = my_tree.task05(k);
	t = (clock()- t) / CLOCKS_PER_SEC;
	printf ("%s : Task = %d k = %d Result = %d Elapsed = %.2f\n", argv[0], 5, k, res, t);
	
//task06
	t = clock();
	res = my_tree.task06(k);
	t = (clock()- t) / CLOCKS_PER_SEC;
	printf ("%s : Task = %d k = %d Result = %d Elapsed = %.2f\n", argv[0], 6, k, res, t);

	fclose(fp);
	return 0;
}
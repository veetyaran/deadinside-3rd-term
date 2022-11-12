#include "student.h"
#include <time.h>
//1) r – количество выводимых уровней в дереве,
//2) filename – имя файла, откуда надо прочитать дерево.
//./a.out r name.txt

int main(int argc, char *argv[])
{
	double t = 0;
	char *name = 0;
	int r = 0, res = 0;
	io_status ret;	
	if(argc != 3 || sscanf(argv[1], "%d", &r) != 1)
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
		errors(ret);
		return -1;
	}
	printf("Tree:\n");
	my_tree.print(r);
//task01
	t = clock();
	res = my_tree.task01(my_tree.get_root());
	t = (clock()- t) / CLOCKS_PER_SEC;
	printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 1, res, t);

//task02
	t = clock();
	res = my_tree.task02(my_tree.get_root(), 0);
	t = (clock()- t) / CLOCKS_PER_SEC;
	printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 2, res, t);

//task03
	t = clock();
	res = my_tree.task03();
	t = (clock()- t) / CLOCKS_PER_SEC;
	printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 3, res, t);

//task04
	t = clock();
	res = my_tree.task04(my_tree.get_root(), 0);
	t = (clock()- t) / CLOCKS_PER_SEC;
	printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 4, res, t);
//task05
	t = clock();
	res = my_tree.task05(my_tree.get_root());
	t = (clock()- t) / CLOCKS_PER_SEC;
	printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], 5, res, t);
	return 0;
}
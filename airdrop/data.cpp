#include "data.h"

int data:: read(FILE* fp)
{
	int i = 0;
	double x;
	if(fscanf(fp, "%d", &m) != 1)
	{return ERROR_READ;}
	int real_m = m;
	if(m > M)
	{ m = M;}
	for(i = 0; i < m; i++)
	{
		if(fscanf(fp, "%lf", a + i) != 1)
			{return ERROR_READ;}		
	}
	if(real_m > M)
	{
		for(i = 0; i < m - M; i++)
		{
			if(fscanf(fp, "%lf", &x) != 1)
				{return ERROR_READ;}
		}
	}
	return SUCCESS;
}
void data:: init(int s)
{ 
	m = s;
}
void data:: print (FILE * fp)
{
	printf("%d	", m);
	int print_size = ((m > p)? p : m);
	for(int i = 0; i < print_size; i++)
	{
		fprintf(fp, "%lf ", a[i]);
	}
	fprintf(fp, "\n");
}
void data:: swap(data& x)
{
	double t_ai;
	int t_m;

	t_m = m;
	m = x.m;
	x.m = t_m;
	for(int i = 0; i < M; i++)
	{
		t_ai = (x.a)[i];
		(x.a)[i] = a[i];
		a[i] = t_ai;
	}
}
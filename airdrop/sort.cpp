#include "sort.h"
int sort01(data* a, int n, data& x)
{	
	int b1 = 0, b2 = n - 1, s = 0;
	while(b1 < b2)
	{
		s = (b1 + b2)/2;
		if(x > a[s])
		{
			b1 = s + 1;
		}
		else
		{
			b2 = s;
		}
	}
	if((b1 == n - 1) && (x > a[n - 1]))
	{
		return b1 + 1;
	}
	return b1;
}
void sort02(data* a, int n, data* b, int m, data* c)
{
	int i = 0, j = 0, k = 0;
	while((i < n) && (j < m))
	{
		if(a[i] < b[j])
		{
			c[k] = (data&&)(a[i]);
			i++;
			k++;
		}
		else
		{
			c[k] = (data&&)(b[j]);
			j++;
			k++;
		}
	}
	while(i < n)
	{
		c[k++]=(data&&)a[i++];
	}
	while(j < m)
	{
		c[k++]=(data&&)b[j++];
	}
}
int sort03(data* a, data& x, int n)
{
	int i = 0, j = n - 1;
	while(i < j)
	{
		while((i <= j) && a[i] < x)
		{
			i++;
		}
		while((i < j) && a[j] > x)
		{
			j--;
		}
		if (i < j)
		{
			if(!(a[j] > (a[i])))
			{
				j--;
				continue;
			}		
			a[i].swap(a[j]);
		}
	}	
	return i;
}
void sort04(data *a, int n)
{
	int i = 0, j = 0;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n - i - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				a[j].swap(a[j+1]);
			}
		}
	}
}
void sort05(data *a, int n)
{
	int i = 0, j = 0, k = 0;
	for(i = 0; i < n - 1; i++)
	{
		for(j = i; j < n; j++)
		{
			if(a[j] < a[k])
			{
				k = j;
			}
		}
		a[i].swap(a[k]);
		k = i + 1;
	}
}
void sort06(data *a, int n)
{
	int i = 0, j = 0, k = 0;
	data temp;
	for(i = 1; i < n; i++)
	{
		j = 0;
		while(a[j] < a[i])
		{
			j++;
		}
		temp = (data&&)a[i];
		for(k = i; k > j; k--)
		{
			a[k] = (data&&)a[k - 1];
		}
		a[j] = (data&&)temp;
	}
}
void sort07(data *a, int n)
{
	int i, j, k = 0;
	data temp;
	if(n > 1)
	{
		for(i = 1; i < n; i++)
		{
			j = sort01(a, i, a[i]);
			temp = (data&&)a[i];
			for(k = i; k > j; k--)
			{
				a[k] = (data&&)a[k - 1];
			}
			a[j] = (data&&)temp;
		}
	}
}
void sort08(data *a, int n, data *b)
{
	data* resarr = a;
	int raz = 1;
	int i, j;
	data *aaa, *bbb;
	int co;
	int ost = 0;
	for(raz = 1; raz <= n/2; raz*=2)
	{
		co = (n/raz)/2;
		aaa = a;
		bbb = b;
		for(i = 0; i < co; i++)
		{
				sort02(aaa, raz, aaa + raz, raz, bbb);
				aaa += 2*raz;
				bbb += 2*raz;
		}
		ost = n % (2*raz);
		if (ost > raz)
		{
				sort02(aaa, raz, aaa + raz, ost - raz, bbb);				
		}
		else
		{
			for (j = 0; j < ost; j++)
			{
				*bbb =(data&&) *aaa;
				aaa++;
				bbb++; 
			}

		}
		swap_(&a, &b);
	}
	if(ost)
	{
		sort02(a, n - ost, a + n - ost, ost, b);
		swap_(&a, &b);
	}
	if (resarr != a)
	{
		for(i = 0; i < n; i++)
		{
			resarr[i] = (data&&)a[i];
		}
	}
}
void swap_(data **x, data **y)
{
	data *tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
void sort09(data* a, int n)
{
	int res = 0;
	while(n > 1)
	{	
		res = sort03_(a, n);
		if(res == 0)
		{
			n -= 1;
			a += 1;
			continue;
		}
		if(res >= n - 1)
		{
			n -= 1;
			continue;
		}
		if((n / 2) > res)
		{
			sort09_array(a, res);
			a += (res + 1);
			n = n - (res + 1);
		}else
		{
			sort09_array(a + res + 1, n - (res + 1));
			n = res;
		}
		
	}
}
void sort09_array(data *a, int n)
{
	int res = 0;
	while(n > 1)
	{		
		res = sort03_(a, n);		
		if(res == 0)
		{
			n -= 1;
			a += 1;
			continue;
		}
		if(res >= n - 1)
		{
			n -= 1;
			continue;
		}
		if((n / 2) > res)
		{
			sort09_array(a, res);
			a += res + 1;
			n -= res + 1;
		}
		else
		{
			sort09_array(a + res + 1, n - res + 1);
			n = res;
		}
		
	}
}
int sort03_(data *a, int n)
{
	int i = 0, j = n - 1, k = n/2;
	while(i < j)
	{
		while((i <= j) && a[i] < a[k])
		{
			i++;
		}
		while((i < j) && a[j] > a[k])
		{
			j--;
		}
		if (i < j)
		{
			if(!(a[j] > a[i]))
			{
				j--;
				continue;
			}		
			if(i == k)
			{
				k = j;
			}
			else
			{
				if(k == j) k = i;
			}
			a[i].swap(a[j]);
		}
	}	
	return i;
}
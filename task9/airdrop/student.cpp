#include "student.h" 
void errors(io_status ret)
{
	if(ret != io_status:: success)
    {
		switch(ret)
		{
			case io_status:: read:
				printf("Error read\n");
					break;
			case io_status:: memory:
				printf("Not enough memory\n");
					break;
			case io_status:: eof:
				printf("Empty\n");
					break;
			case io_status:: open:
				printf("Cannot open\n");
					break;
			case io_status:: format:
				printf("Error format\n");
					break;
			default:
				printf("Unknown ERROR\n");
		}
	}
}
io_status tree:: read(FILE * fp)
{
	tree_node x;
	while(x.read(fp) == io_status:: success)
	{
		tree_node *curr = new tree_node((tree_node &&)x);
		if(!curr)
			return io_status:: memory;
		if(!root)
			root = curr;
		else
			add_node_subtree(root, curr);
	}
	if(!feof(fp))
		return io_status:: read;
	return io_status:: success;
}
/*
TASKS
*/
int tree:: task01(int k)
{	
	if(!root)
		return 0;
	return f01(root, k);
}
int tree:: f01(tree_node *curr, int k)
{
	if(curr == nullptr)
		return 0;
	tree_node *p;
	int i = 0, res = 0;
	for(p = curr->down; p; p = p->level)
	{		
		i++;
		res += f01(p, k);	
	}
	if(k == i)
		return res + 1;
	return res;
}
//количество элементов в поддеревьях, имеющих не более k вершин
int tree:: task02(int k)
{
	if(!root)
		return 0;	
	tree_node *p;		
	int i = 0, res = 0;
	for(p = root->down; p; p = p->level)			
		i = f02(p, k, &res);
	(void)i;
	return res;
}
int tree:: f02(tree_node *curr, int k, int *res)
{
	if(curr == nullptr)
		return 0;
	tree_node *p;
	int i = 1;
	for(p = curr->down; p; p = p->level)
		i += f02(p, k, res);	
	if(i <= k)
	{		
		*res += i;
		return i;
	}
	return i;
}
//количество элементов в поддеревьях, имеющих не более k уровней
int tree:: task03(int k)
{
	if(!root)
		return 0;	
	tree_node *p;		
	int i = 0, res = 0, level = 0;
	for(p = root->down; p; p = p->level, i = 0)			
		level = f03(p, k, &res, &i);
	(void)level;
	return res;
}
int tree:: f03(tree_node *curr, int k, int *res, int *i)
{
	if(curr == nullptr)
		return 0;
	int level = 0, j = 1, j1 = 0, j2 = 0;
	tree_node *p = curr->down;
	if(p)
		level++;		
	for(; p; p = p->level)
	{
		j2 = j1;
		j1 = f03(p, k, res, i);	 
		if(j1 < j2)
			j1 = j2;		
		j += *i;
		*i = 0;
	}
	level += j1;
	*i = j;
	if(level + 1 <= k)		
		*res += j;
	return level;
}
//количество элементов поддеревьях, имеющих не более k узлов в любом уровне
int tree:: get_len_tree(tree_node *curr, int i)
{
	if(curr == nullptr)
		return 0;
	if(curr->down == nullptr)
		return i+1;
	tree_node *p;
	int	j1 = 0, j2 = 0;		
	for(p = curr->down; p; p = p->level)
	{
		j2 = j1;
		j1 = get_len_tree(p, i+1);
		if(j1 < j2)
			j1 = j2;
	}
	return j1;
}
int tree:: task04(int k)
{
	if(!root)
		return 0;
	if(k <= 0)
		return 0;
	int res = 0;
	int len = get_len_tree(root, 0);
	int *lvl = new int[len]();
	if(!lvl)
	{			
		errors(io_status:: memory);
		return -1;
	}
	for(tree_node *p = root->down; p; p = p->level)
		res += f04(p, lvl, k);			
	delete [] lvl;
	return res;
}
int tree:: f04(tree_node *curr, int *lvl, int k)
{
	if(curr == nullptr)
		return 0;
	int flag = 0, res = 0;
	len_subtree_levels(curr, lvl, 0);
	for(int j = 0; lvl[j] != 0; j++)
	{
		res += lvl[j];
		if(lvl[j] > k)
			flag = 1;
		lvl[j] = 0;
	}
	if(flag)
		res = 0;
	for(tree_node *p = curr->down; p; p = p->level)
		res += f04(p, lvl, k);	
	return res;	
}
void tree:: len_subtree_levels(tree_node *curr, int *lvl, int i)
{
	if(curr == nullptr)
		return;	
	lvl[i]++;
	for(tree_node *p = curr->down; p; p = p->level)
		len_subtree_levels(p, lvl, i + 1);	
	return;	
}
//количество элементов на k-м уровне
int tree:: task05(int k)
{	
	if(!root)
		return 0;
	if(!k)
		return 1;
	return f05(root, k, 0);
}
int tree:: f05(tree_node *curr, int k, int level)
{
	if(curr == nullptr)
		return 0;
	tree_node *p;
	int i = 0, res = 0;
	for(p = curr->down; p; p = p->level)
	{
		i++;
		res += f05(p, k, level + 1);	
	}		
	if(level == k - 1)
		return res + i;
	return res;
}
//количество элементов во всех ветвях длины не менее k, начиная с корня
int tree:: task06(int k)
{	
	if(!root)
		return 0;
	return f06(root, k, 1);
}
int tree:: f06(tree_node *curr, int k, int level)
{
	if(curr == nullptr)
		return 0;
	if(curr->down == nullptr)
	{	
		if(level >= k)
			return level;		
		return 0;
	}
	int res = 0;
	for(tree_node *p = curr->down; p; p = p->level)
		res += f06(p, k, level + 1);	
	return res;
}
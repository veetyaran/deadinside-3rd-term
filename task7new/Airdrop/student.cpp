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
io_status tree:: read(FILE * fp, unsigned int max_read)
{
	unsigned int count = 0;
	tree_node x;
	while(count < max_read && x.read(fp) == io_status:: success)
	{
		tree_node *curr = new tree_node((tree_node &&)x);
		if(!curr)
			return io_status:: memory;
		if(!root)
			root = curr;
		else
			add_node_subtree(root, curr);
	}
	if(count >= max_read)
		return io_status:: success;
	if(!feof(fp))
		return io_status:: read;
	return io_status:: success;
}
/*
TASKS
*/
int tree:: task01(tree_node *curr)
{
	if(curr == nullptr)
		return 0; 
	if(curr->left == nullptr && curr->right == nullptr)
		return 1;
	else
		return task01(curr->left) + task01(curr->right);
}
int tree:: task02(tree_node *curr, int i)
{
	if(curr == nullptr)
		return 0;
	if(curr->left == nullptr && curr->right == nullptr)
		return i+1;
	else
	{
		int i_left = 0, i_right = 0;
		i_left = task02(curr->left, i+1);
		i_right = task02(curr->right, i+1);
		if(i_left > i_right)
			return i_left;
		else
			return i_right;
	}
}
int tree:: task03()
{
	if(root == nullptr)
		return 0;
	int len_tree = task02(root, 0);
	int max = 0, level_size = 0;
	for(int level = 0; level < len_tree; level++)
	{
		level_size = get_level_size(root, 0, 0, level);
		if(level_size > max)
			max = level_size;
	}
	if(!max)
		return 1;
	return max;
}
int tree:: get_level_size(tree_node *curr, int i, int j, int level)
{
	if(curr == nullptr)
		return 0;
	if(j == level)
	{	
		if(curr->left)
			i++;
		if(curr->right)
			i++;
		return i;
	}
	else
	{
		int i_left = 0, i_right = 0;
		i_left = get_level_size(curr->left, i, j+1, level);
		i_right = get_level_size(curr->right, i, j+1, level);
		return i_left + i_right;
	}
}
int tree:: task04(tree_node *curr, int max_diff)
{
	if(curr == nullptr)
		return 0;
	if(curr->left == nullptr && curr->right == nullptr)
		return 0;
	else
	{
		int diff = get_diff(curr);
		if(diff < max_diff)
			diff = max_diff;			
		int diff_l = task04(curr->left, diff);
		int diff_r = task04(curr->right, diff);			
		if(diff_l >= diff)			
		{
			if(diff_r >= diff_l)
				return diff_r;
			else
				return diff_l;
		}
		else if(diff_r >= diff)
			return diff_r;
		else
			return diff;
	}		
}
int tree:: get_diff(tree_node *curr)
{
	int diff = task02(curr->left, 0) - task02(curr->right, 0);
	if(diff < 0)
		return diff * (-1);
	return diff;
}
int tree:: task05(tree_node *curr)
{
	if(curr == nullptr)
		return 0; 
	if(curr->left == nullptr && curr->right == nullptr)
		return 0;
	else
	{
		int i = 0;
		if(!(curr->left && curr->right))
			i = 1;
		return task05(curr->left) + task05(curr->right) + i;
	}
}
#include "2tree.h"
#include "list.h"
#include <algorithm>

void tree::addNodeSubtree(tree_node* current, tree_node* x)
{
    tree_node* iterator = current;
    while(true)
    {
        if(*x < *iterator)
        {
            if(iterator->left == nullptr)
            {
                iterator->left = x;
                break;
            }
            else
            {
                iterator = iterator->left;
                continue;
            }
        }
        else
        {
            if(iterator->right == nullptr)
            {
                iterator->right = x;
                break;
            }
            else
            {
                iterator = iterator->right;
                continue;
            }
        }
    }
    return;
}

io_status tree::read(FILE * fp, unsigned int max_read)
{
    io_status errorstatus = io_status::success;
    unsigned int counter = 0;
    tree_node tmp;
    if(!fp)
        return io_status::memory;
    while(counter < max_read && (errorstatus = tmp.read(fp)) == io_status::success)
    {
        ++counter;
        tree_node* current = new tree_node((tree_node&&)tmp);
        if(current == nullptr)
            return io_status::memory;
        if(root==nullptr)
            root = current;
        else addNodeSubtree(root, current);
    }
    if(counter >= max_read)
        return io_status::success;
    if(!feof(fp))
        return errorstatus;
    return io_status::success;
}

unsigned int tree::countLeafNodes()
{
    unsigned int leafCounter = 0;
    if(!root)
        return 0;
    list<tree_node*> l;
    l.push(root);
    while(!l.isEmpty())
    {
        tree_node* current = l.pop();
        if(current->right != nullptr)
            l.push(current->right);
        if(current->left != nullptr)
            l.push(current->left);
        if(current->left == nullptr && current->right == nullptr)
            ++leafCounter;
    }
    return leafCounter;
}

unsigned int tree::countLeafNodesRecursively(tree_node* current)
{
    unsigned int counter = 0;
    if(!current->left && !current->right)
        ++counter;
    if(current->left != nullptr)
    {
        counter += countLeafNodesRecursively(current->left);
    }
    if(current->right != nullptr)
    {
        counter += countLeafNodesRecursively(current->right);
    }
    return counter;
}

unsigned int tree::countTreeHeight()
{
    unsigned int levelCounter = 0;
    unsigned int size = 0;
    tree_node* current = nullptr;
    if(!root)
        return 0;
    list<tree_node*> l;
    l.push(root);
    while(!l.isEmpty())
    {
        ++levelCounter;
        size = l.size;
        while(size != 0)
        {
            current = l.popback();
            if(current->left != nullptr)
                l.push(current->left);
            if(current->right != nullptr)
                l.push(current->right);
            size--;
        }
    }
    return levelCounter;
}

unsigned int tree::countSubtreeHeight(tree_node* current)
{
    unsigned int levelCounter = 0;
    unsigned int size = 0;
    tree_node* current1 = current;
    if(!current1)
        return 0;
    list<tree_node*> l;
    l.push(current1);
    while(!l.isEmpty())
    {
        ++levelCounter;
        size = l.size;
        while(size != 0)
        {
            current1 = l.popback();
            if(current1->left != nullptr)
                l.push(current1->left);
            if(current1->right != nullptr)
                l.push(current1->right);
            size--;
        }
    }
    return levelCounter;
}
unsigned int tree::countMaxLevelSize()
{
    unsigned int maxsize = 0;
    unsigned int size = 0;
    tree_node* current = nullptr;
    if(!root)
        return 0;
    list<tree_node*> l;
    l.push(root);
    while(!l.isEmpty())
    {
        size = l.size;
        if(size > maxsize)
            maxsize = size;
        while(size != 0)
        {
            current = l.popback();
            if(current->left != nullptr)
                l.push(current->left);
            if(current->right != nullptr)
                l.push(current->right);
            size--;
        }
    }
    return maxsize;
}
unsigned int tree::countParentsWithOneChild()
{
    unsigned int counter = 0;
    if(!root)
        return 0;
    list<tree_node*> l;
    l.push(root);
    while(!l.isEmpty())
    {
        tree_node* current = l.pop();
        if(current->right != nullptr)
            l.push(current->right);
        if(current->left != nullptr)
            l.push(current->left);
        if(current->left == nullptr && current->right != nullptr)
            ++counter;
        if(current->left != nullptr && current->right == nullptr)
            ++counter;
    }
    return counter;
}

unsigned int tree::countMaxLRDiffSubtreeRecursively(tree_node* current)
{
    unsigned int ret = 0;
    
}

unsigned int tree::countMaxLRDiff()
{
    return countMaxLRDiffSubtreeRecursively(root);
}
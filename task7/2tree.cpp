#include "2tree.h"

#include <algorithm>
#include <boost/pool/pool_alloc.hpp>
#include <list>

using cool_list = std::list<
    tree_node*,
    boost::fast_pool_allocator<
        tree_node*,
        boost::default_user_allocator_new_delete,
        boost::details::pool::null_mutex,
        20 * sizeof(tree_node*)
    >
>;

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

    cool_list l;
    l.push_front(root);
    while(!l.empty())
    {
        tree_node* current = l.front();
        l.pop_front();
        if(current->right != nullptr)
            l.push_front(current->right);
        if(current->left != nullptr)
            l.push_front(current->left);
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
    cool_list l;
    l.push_front(root);
    while(!l.empty())
    {
        ++levelCounter;
        size = l.size();
        while(size != 0)
        {
            current = l.back();
            l.pop_back();
            if(current->left != nullptr)
                l.push_front(current->left);
            if(current->right != nullptr)
                l.push_front(current->right);
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
    cool_list l;
    l.push_front(current1);
    while(!l.empty())
    {
        ++levelCounter;
        size = l.size();
        while(size != 0)
        {
            current1 = l.back();
            l.pop_back();
            if(current1->left != nullptr)
                l.push_front(current1->left);
            if(current1->right != nullptr)
                l.push_front(current1->right);
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
    cool_list l;
    l.push_front(root);
    while(!l.empty())
    {
        size = l.size();
        if(size > maxsize)
            maxsize = size;
        while(size != 0)
        {
            current = l.back();
            l.pop_back();
            if(current->left != nullptr)
                l.push_front(current->left);
            if(current->right != nullptr)
                l.push_front(current->right);
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
    cool_list l;
    l.push_front(root);
    while(!l.empty())
    {
        tree_node* current = l.front();
        l.pop_front();
        if(current->right != nullptr)
            l.push_front(current->right);
        if(current->left != nullptr)
            l.push_front(current->left);
        if(current->left == nullptr && current->right != nullptr)
            ++counter;
        if(current->left != nullptr && current->right == nullptr)
            ++counter;
    }
    return counter;
}

unsigned int tree::countSubtreeHeightRecursively(tree_node* current)
{
    if(!current)
        return 0;
    unsigned int l = 0, r = 0;
    if(current->left == nullptr && current->right == nullptr)
    {
        return 0;
    }
    else
    {
        l = countSubtreeHeightRecursively(current->left);
        r = countSubtreeHeightRecursively(current->right);

        if (l > r)
        {
            l = l + 1;
            return l;
        }
        else
        {
            r = r + 1;
            return r;
        }
    }
}
unsigned int tree::countLRDiffHere(tree_node* current, unsigned int maxdiff)
{
    unsigned int  l = 0, r = 0, diff = 0;
    if(!current)
        return 0;
    l = countSubtreeHeightRecursively(current->left);
    r = countSubtreeHeightRecursively(current->right);
    auto R = std::minmax(l, r);
    diff = R.second - R.first;
    if(maxdiff < diff)
        return diff;
    else return maxdiff;
}

unsigned int tree::countMaxLRDiffRecursively(tree_node* current, unsigned int max)
{
    unsigned int diffHere = 0, diffL = 0, diffR = 0, maxdiff = max;
    if(!current->left && !current->right)
        return 0;
    diffHere = countLRDiffHere(current, maxdiff);
    if(diffHere > maxdiff)
        maxdiff = diffHere;
    if(current->left)
        diffL = countMaxLRDiffRecursively(current->left, maxdiff);
    if(current->right)
        diffR = countMaxLRDiffRecursively(current->right, maxdiff);
    if(diffL > maxdiff && diffL >= diffR)
        maxdiff = diffL;
    if(diffR > maxdiff && diffR > diffL)
        maxdiff = diffR;
    return maxdiff;
}
unsigned int tree::countMaxLRDiff()
{
    return countMaxLRDiffRecursively(root);
}
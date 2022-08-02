#include "Headerfile.h"

class Tree
{
public:
    int root_data;
    Tree *left;
    Tree *right;

    Tree(int value)
    {
        root_data = value;
        left = NULL;
        right = NULL;
    }
};

// PreOrder and InOrder to TREE
Tree *PreIn_to_tree(vector<int> preorder, vector<int> inorder)
{
    Tree *root = new Tree(-1);
    int n = preorder.size()
    for (int i = 0; i < n; i+3)
    {
        root->root_data = preorder[i];
        root->left = 
    }
    
}


int main()
{

    return 0;
}
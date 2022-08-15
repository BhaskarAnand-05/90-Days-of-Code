#include"Headerfile.h"

class Node
{
    public:
    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node(int val)
    {
        data = val;
    }
};


//Time Complexity = O(n)
int height(Node *root)
{
    // edge case
    if (root == NULL)
    {
        return 0;
    }

    int lheight  = height(root->left);
    int rheight  = height(root->right);

    return max(lheight, rheight) +1;
    
}


// Time Complexity of calculating diameter = O(n^2)
int diameter(Node *root)
{
    //edge case
    if (root == NULL)
    {
        return 0;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    int cum_diameter = left_height + right_height + 1;

    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);

    return max(max(left_diameter,right_diameter),cum_diameter);
    
}

int calc_diameter(Node* root)
{
    ;
}
int main()
{
    Node* tree = new Node(1);                                
    tree->left = new Node(2);                              
    tree->left->left = new Node(3);
    tree->left->left->left = new Node(4);
    tree->left->left->left->left = new Node(5);
    tree->right = new Node(6);
    tree->right->right = new Node(7);
    
    cout<<height(tree)<<endl;

    cout<<diameter(tree);

    cout<<endl; 


    return 0;
}

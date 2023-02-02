#include"Headerfile.h"

// Vertical Order Traversal
vector<int> Vertical_Order()


int main()
{
    Node *tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->left->right = new Node(5);
    tree->right->left = new Node(6);
    tree->right->right = new Node(7);
    tree->left->right->right = new Node(8);

    return 0;
}
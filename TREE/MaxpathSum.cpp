#include "Headerfile.h"

int maxpathsum(Node *root)
{
    // edge case
    if (!root)
        return -1;

    int leftsum = maxpathsum(root->left);
    int rightsum = maxpathsum(root->right);

    int maxi = max((leftsum + rightsum + root->data), maxi);

    return root->data + max(leftsum, rightsum);
}

int main()
{
    Node *tree = new Node(1);
    tree->left = new Node(2);
    tree->left->left = new Node(3);
    tree->left->left->left = new Node(4);
    tree->left->left->left->left = new Node(5);
    tree->right = new Node(6);
    tree->right->right = new Node(7);

    int res = maxpathsum(tree);

    cout << res << endl;

    return 0;
}
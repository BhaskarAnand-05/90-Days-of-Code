#include "Headerfile.h"

void solve(vector<int> &inorder, Node *root)
{
    if (root->left)
    {
        solve(inorder, root->left);
    }
    inorder.push_back(root->data);
    if (root->right)
    {
        solve(inorder, root->right);
    }
}

// Recursive Travesals
vector<int> INORDER(Node *root)
{
    vector<int> inorder;
    // edge case
    if (!root)
        return inorder;

    solve(inorder, root);
    return inorder;
}

// Level Order Traversal

vector<int> Level_Order(Node *root)
{
    vector<int> ans;

    // edge case
    if (!root)
        return ans;

    queue<Node *> q;
    q.push(root);
    

    Node *curr = root;

    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
        
        ans.push_back(curr->data);
    }
    return ans;
}

int main()
{
    Node *tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->left->right = new Node(5);
    tree->right->left = new Node(6);
    tree->right->right = new Node(7);

    // cout << endl
    //      << "Inorder" << endl;
    cout << endl
         << "Level Order" << endl;
    vector<int> ans = Level_Order(tree);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    
    

    return 0;
}
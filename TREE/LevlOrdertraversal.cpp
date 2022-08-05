#include "Headerfile.h"
#include <queue>
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
    ~Node();
};

void LevelOrdertraversal(Node *Tree)
{
    if (Tree == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(Tree);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp != NULL)
        {
            cout << temp->data << "  ";
            if (Tree->left)
            {
                q.push(Tree->left);
            }
            if (Tree->right)
            {
                q.push(Tree->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

int main()
{
    Node *t1 = new Node(1);
    t1->left = new Node(2);
    t1->right = new Node(3);
    t1->left->left = new Node(4);
    t1->left->right = new Node(5);
    t1->right->left = new Node(6);
    t1->right->right = new Node(7);

    LevelOrdertraversal(t1);
    cout << endl;

    return 0;
}
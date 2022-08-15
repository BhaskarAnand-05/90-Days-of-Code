#include "Headerfile.h"

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

vector<int> Preorder(Node *root)
{
    vector<int> preorder;

    // Edge Case
    if (root == NULL)
    {
        return preorder;
    }

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *temp = st.top();
        preorder.push_back(temp->data);
        st.pop();

        if (temp->right)
        {
            st.push(temp->right);
        }
        if (temp->left)
        {
            st.push(temp->left);
        }
    }
    return preorder;
}

vector<int> Inorder(Node *root)
{
    vector<int> inorder;
    // Edge Case
    if (root == NULL)
        return inorder;

    stack<Node*> st;
    st.push(root);

    Node*temp ;

    while (!st.empty())
    {
        while (root != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }

        temp = st.top();
        st.pop();

        cout<<temp->data<<" ";
        temp = temp->right;
        
    }
    return inorder;
    
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

    cout << "Preorder" << endl;
    vector<int> ans = Preorder(t1);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout <<endl <<"Inorder" << endl;
    vector<int> res = Inorder(t1);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
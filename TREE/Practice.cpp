// Inorder Traversal

#include "Headerfile.h"

vector<int> postorder(Node *root)
{
    vector<int> POSTORDER;
    // edge case
    if (!root)
        return POSTORDER;

    stack<Node *> st1, st2;
    st1.push(root);
    Node *temp = root;

    while (!st1.empty() && temp != NULL)
    {
        temp = st1.top();
        st1.pop();

        st2.push(temp);
        if (temp->left)
            st1.push(temp->left);
        if (temp->right)
            st1.push(temp->right);
    }
    while (!st2.empty())
    {
        Node* t1 = st2.top();
        POSTORDER.push_back(t1->data);
        st2.pop();
    }

    return POSTORDER;
}

// vector<int> inorder(Node *root)
// {
//     vector<int> INORDER;

//     // Edge Case
//     if (root == NULL)
//         return INORDER;

//     stack<Node *> st;
//     st.push(root);
//     Node *head = root;

//     while (!st.empty())
//     {
//         while (head != NULL)
//         {
//             st.push(head);
//             head = head->left;
//         }

//         head = st.top();
//         st.pop();

//         INORDER.push_back(head->data);
//         head = head->right;
//     }
//     return INORDER;
// }

int main()
{
    Node *t1 = new Node(1);
    t1->left = new Node(2);
    t1->right = new Node(3);
    t1->left->left = new Node(4);
    t1->left->right = new Node(5);
    t1->left->right->right = new Node(6);

    // cout << "Preorder" << endl;
    // vector<int> ans = Preorder(t1);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl
    //      << "Inorder" << endl;
    // vector<int> res = inorder(t1);
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << " ";
    // }
    cout << endl
         << "PostOrder" << endl;
    vector<int> result = postorder(t1);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
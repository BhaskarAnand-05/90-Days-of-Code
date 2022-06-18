#include "Headerfile.h"

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        node *n;
        data = val;
        next = NULL;
    }
};

void insertatBEG(node *&head, int value)
{
    node *n = new node(value);
    n->next = head;
    head = n;
}

void insertatTAIL(node *&head, int val)
{

    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void print(node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data << "->NULL" << endl;
}

// Delete without head pointer

// void deletenode(node *&dnode)
// {

//     while (dnode->next != NULL)
//     {
//         node *temp = dnode->next;

//         dnode->data = temp->data;

//         dnode->next = temp->next;
        
//         delete temp;
//     }

    
// }

// node *removeDuplicates(node *head)
// {
//     node *temp = head;
//     node *temp2 = head;
//     node *todelete;

//     while (temp != NULL)
//     {
//         while (temp2 != NULL)
//         {
//             if (temp2->next->data == temp->next->data)
//             {
//                 todelete = temp->next;
//                 temp->next = temp->next->next;
//             }

//             temp2 = temp2->next;
//         }
//         delete todelete;

//         temp = temp->next;
//     }

//     return temp;
// }
int main()
{
    node *head = NULL;

    insertatTAIL(head, 1);
    insertatTAIL(head, 12);
    insertatTAIL(head, 34);
    insertatTAIL(head, 12);
    insertatTAIL(head, 55);
    insertatTAIL(head, 189);
    insertatTAIL(head, 342);

    print(head);
    insertatTAIL(head, 55);
    print(head);
    
    node* res=removeDuplicates(head);
    print(res);

    return 0;
}
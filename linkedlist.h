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

void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void deletenode(node *&head, int val)
{
    node *temp = head;

    while (temp != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;
}

void deleteatBEG(node* &head)
{
    if(head==NULL)
    {
        return;
    }
    node* todelete=head;
    head= head->next;
    delete todelete;
}

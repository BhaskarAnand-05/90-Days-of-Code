#include "Headerfile.h"

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        node *n;
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertatBEG(node *&head, int val)
{
    node *n = new node(val);

    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }

    head = n;
}
void insertatTAIL(node *&head, int val)
{

    node *temp = head;
    node *n = new node(val);
    if (head == NULL)
    {
        insertatBEG(head, val);
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
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

void deletenode(node *&head, int val)
{
    node *temp = head;
    node *delnode;

    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    delnode = temp->next;
    temp->next = temp->next->next;
    temp->next->next->prev = temp;

    delete delnode;
}
void insertatMID(node *&head, int val)
{
    node *temp = head;
    node *n = new node(val);

    while (temp->next->data <= val)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
    n->prev = temp;
    temp->next->prev = n;
}

void deleteatBEG(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *delnode = head;
    head = head->next;
    head->prev = NULL;
    delete delnode;
}



int main()
{
    node *head = NULL;

    insertatTAIL(head, 2);
    print(head);
    insertatTAIL(head, 25);
    insertatTAIL(head, 39);
    insertatTAIL(head, 87);
    insertatTAIL(head, 143);
    insertatTAIL(head, 243);
    insertatMID(head, 50);

    print(head);

    deletenode(head, 87);

    print(head);

    deleteatBEG(head);
    print(head);

    return 0;
}
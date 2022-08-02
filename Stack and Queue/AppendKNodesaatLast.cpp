#include "Headerfile.h"

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        Node *n;
        data = val;
        next = NULL;
    }
};

void insertatTail(Node *&head, int val)
{
    Node *n = new Node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    // n->next = NULL;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << " NULL" << endl;
}

Node *AppendatLast(Node *&head, int k)
{
    Node *newhead = NULL;
    Node *newtail = NULL;
    Node *temp = head;
    int count = 0;

    while (temp != NULL && count != k)
    {
        temp = temp->next;
        count += 1;
    }

    if (count < k)
    {
        cout << "Less Elements" << endl;
        return NULL;
    }

    newtail = temp;

    newhead = temp->next;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    newtail->next = NULL;

    return newhead;
}

int main()
{
    Node *head = NULL;

    insertatTail(head, 1);
    insertatTail(head, 2);
    insertatTail(head, 3);
    insertatTail(head, 4);
    insertatTail(head, 5);
    insertatTail(head, 6);
    insertatTail(head, 7);
    insertatTail(head, 8);
    insertatTail(head, 9);
    insertatTail(head, 10);
    insertatTail(head, 11);
    insertatTail(head, 12);

    display(head);

    Node *Nhead = AppendatLast(head, 15);

    display(Nhead);

    return 0;
}
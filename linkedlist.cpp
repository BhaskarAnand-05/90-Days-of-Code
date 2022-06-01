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

void insertatMID(node *&head, int value, int key)
{
    node *N = new node(value);
    node *temp = head;
    while (temp->next->data != key)
    {
        temp = temp->next;
    }
    N->next = temp->next;
    temp->next = N;
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
void deletehead(node *&head)
{
    node *temp = head;
    head = head->next;
    delete temp;
}

bool search(node *head, int val)
{
    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data = val)
        {
            return true;
        }

        temp = temp->next;
    }
    return false;
}
void deletion(node *&head, int val)
{
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todel = temp->next;
    temp->next = temp->next->next;
    delete todel;
}

// Reverse a LInked List   ITERATIVE

node *ReverseLL(node *&head)
{

    node *previous = NULL;
    node *current = head;
    node *Next = current->next;

    while (current != NULL)
    {
        Next = current->next;
        current->next = previous;

        previous = current;
        current = Next;
    }

    return previous;
}

// Reverse a Linked List RECURSIVE

node *reverse(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *new_head = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return new_head;
}

// Reverse K nodes in linked list

node *reversek(node *&head, int k)
{
    node *previous = NULL;
    node *current = head;
    node *next;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;

        count++;
    }
    if (next != NULL)
    {
        head->next = reversek(next, k);
    }

    return previous;
}

// Make a cycle in the linked list

void makecycle(node *&head, int pos)
{

    node *startcycle;
    node *temp = head;
    int count = 1;

    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startcycle = temp;
        }

        temp = temp->next;
        count++;
    }

    temp->next = startcycle;
}

// Detect Cycle in the linked list

bool detectcycle(node *head)
{

    node *fastptr = head;
    node *slowptr = head;

    while (fastptr != NULL && fastptr->next != NULL)
    {
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;

        if (fastptr == slowptr)
        {
            return true;
        }
    }

    return false;
}

// Delete a Cycle in the linked list

void deletecycle(node *&head)
{
    node *fastptr = head;
    node *slowptr = head;

    while (fastptr != slowptr)
    {
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
    }
    fastptr = head;

    while (fastptr->next != slowptr->next)
    {
        fastptr = fastptr->next;
        slowptr = slowptr->next;
    }
    slowptr->next = NULL;

    return;
}

int main()
{
    node *head = NULL;

    insertatTAIL(head, 1);
    insertatTAIL(head, 12);
    insertatTAIL(head, 34);

    print(head);
    insertatTAIL(head, 55);
    print(head);
    insertatMID(head, 22, 34);
    print(head);
    insertatTAIL(head, 99);
    // deletion(head, 22);
    // print(head);
    // deletehead(head);
    // print(head);

    // cout << endl
    //      << " Found Status " << search(head, 22);

    node *NewHead = reversek(head, 2);

    print(NewHead);

    makecycle(head, 3);
    // print(head);
    cout << detectcycle(head)<<endl;
    deletecycle(head);
    cout << detectcycle(head);

    return 0;
}

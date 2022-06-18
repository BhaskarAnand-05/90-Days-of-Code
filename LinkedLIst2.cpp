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

// Merge two sorted linked list

// node *Merge(node *&first, node *&second)
// {
//     if (first == NULL)
//     {
//         return second;
//     }
//     if (second == NULL)
//     {
//         return first;
//     }

//     node *result = new node(-1);
//     node *temp = result;

//     while (first != NULL && second != NULL)
//     {
//         if (first->data < second->data)
//         {
//             temp->next = first;
//             temp = first;
//             first = first->next;
//         }
//         else
//         {
//             temp->next = second;
//             temp = second;
//             second = second->next;
//         }
//     }

//     while (first != NULL)
//     {
//         temp->next = first;
//         temp = first;
//         first = first->next;
//     }
//     while (second != NULL)
//     {
//         temp->next = second;
//         temp = second;
//         second = second->next;
//     }

//     result = result->next;

//     return result;
// }

// intersection of the linked list

// to make two linked list intersect

void intersect(node *&head1, node *&head2, int pos)
{
    node *temp = head1;
    pos--;

    while (pos--)
    {
        temp = temp->next;
    }

    node *temp2 = head2;

    while (temp2 != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

int length(node *head)
{

    node *temp = head;
    int p = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        p++;
    }

    return p;
}

int intersection(node *head1, node *head2)
{
    // lenghts of the linkedlist
    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;
    node *ptr1;
    node *ptr2;

    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d--)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

// int length(node *head)
// {
//     node *temp = head;
//     int count = 0;

//     while (temp != NULL)
//     {

//         temp = temp->next;
//         count++;
//     }

//     return count;
// }

// node *removeNthFromEnd(node *head, int n)
// {

//     node *temp = head;
//     node *todelete;

//     int len = length(head);

//     int count = 0;

//     while (count != (len - n) || temp != NULL)
//     {
//         temp = temp->next;
//         count++;
//     }

//     todelete = temp->next;

//     temp->next = temp->next->next;

//     delete todelete;

//     return temp;
// }

// remove duplictaes -sorted linked list

void removeduplicates(node *&head)
{
    node *ptr1, *dup;
    ptr1 = head;

    if (head == NULL)
    {
        return;
    }
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        if (ptr1->data == ptr1->next->data)
        {
            dup = ptr1->next;
            ptr1->next = ptr1->next->next;
            delete dup;
        }
        else
            ptr1 = ptr1->next;
    }
}

// multiply two linked List

long long multiplyLinkedList(node *head1, node *head2)
{
    long long num1 = 0, num2 = 0;
    long long N = 1000000007;

    while (head1 != NULL || head2 != NULL)
    {
        if (head1)
        {
            num1 = (num1 * 10) % N + head1->data;
            head1 = head1->next;
        }
        if (head2)
        {
            num2 = (num2 * 10) % N + head2->data;
            head2 = head2->next;
        }
    }

    return ((num1) % N * (num2) % N) % N;
}

int main()
{
    node *head = NULL;

    insertatTAIL(head, 1);
    insertatTAIL(head, 2);
    insertatTAIL(head, 3);
    insertatTAIL(head, 4);
    insertatTAIL(head, 5);
    // insertatTAIL(head, 189);
    // insertatTAIL(head, 342);

    print(head);
    // insertatTAIL(head, 555);
    // print(head);

    node *Head = NULL;

    insertatTAIL(Head, 2);
    insertatTAIL(Head, 1);
    insertatTAIL(Head, 3);
    insertatTAIL(Head, 4);
    // insertatTAIL(Head, 65);
    // insertatTAIL(Head, 789);
    // insertatTAIL(Head, 942);

    print(Head);
    // insertatTAIL(Head, 942);
    // print(Head);

    // intersect(head, Head, 3);
    // print(head);
    // print(Head);
    // cout<<endl<<intersection(head,Head);

    // removeduplicates(Head);

    cout<<endl<<multiplyLinkedList(head,Head);
    // print(result);
    return 0;
}
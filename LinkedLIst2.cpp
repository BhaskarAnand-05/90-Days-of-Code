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
    node* ptr1;
    node* ptr2;

    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1=head1;
        ptr2=head2;
    }
    else
    {
        d = l2 - l1;
        ptr1=head2;
        ptr2=head1;
    }

    while (d--)
    {
        ptr1=ptr1->next;
        if (ptr1==NULL)
        {
            return -1;
        }
        
    }

    while (ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1==ptr2)
        {
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    return -1;

}



















int main()
{
    node *head = NULL;

    insertatTAIL(head, 1);
    insertatTAIL(head, 12);
    insertatTAIL(head, 34);
    insertatTAIL(head, 43);
    insertatTAIL(head, 55);
    insertatTAIL(head, 189);
    insertatTAIL(head, 342);

    print(head);
    insertatTAIL(head, 555);
    print(head);

    node *Head = NULL;

    insertatTAIL(Head, 2);
    insertatTAIL(Head, 11);
    insertatTAIL(Head, 22);
    insertatTAIL(Head, 45);
    insertatTAIL(Head, 65);
    insertatTAIL(Head, 789);
    insertatTAIL(Head, 942);

    print(Head);
    insertatTAIL(Head, 1055);
    print(Head);

    intersect(head, Head, 3);
    print(head);
    print(Head);
    cout<<endl<<intersection(head,Head);

    return 0;
}
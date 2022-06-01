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

// Merge sort for linked list



// tofind the mid of ll recursively
node *findmid(node *&head)
{
    node *tortoise = head;
    node *hare = head->next;

    while (hare != NULL && hare->next != NULL)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
    }

    return tortoise;
}



// Merge function

node *Merge(node *&left, node *&right)
{

    
    node *dummy = new node(-1);
    node *temp = dummy;

    
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
        while (left != NULL)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        while (right != NULL)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }

        dummy = dummy->next;

        return dummy;
    }


node *mergesortll(node *&head)
{
    // base case
    if (head == NULL && head->next == NULL)
    {
        return head;
    }

    node *mid = findmid(head);

    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    // to sort the left and right part

    left = mergesortll(left);
    right = mergesortll(right);

    // merging two sorted ones

    node *Output = Merge(left, right);

    return Output;
}

int main()
{
    node *head = NULL;

    insertatTAIL(head, 1);
    insertatTAIL(head, 12);
    insertatTAIL(head, 34);
    insertatTAIL(head, 43);
    insertatTAIL(head, 35);
    insertatTAIL(head, 789);
    insertatTAIL(head, 342);

    print(head);
    insertatTAIL(head, 55);
    print(head);

    node *MergerSort = mergesortll(head);
    print(MergerSort);

    return 0;
}
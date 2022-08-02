#include "Headerfile.h"

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertatTAIL(Node *&head, int val)
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
}

Node *addTwoNumbers(Node *head1, Node *head2)
{
    int sum = 0;
    Node *Sum = NULL;

    int carry = 0;

    while (head1 != NULL && head2 != NULL)
    {
        sum = (head1->data + head2->data + carry)%10;
        carry = sum / 10;
        Node *temp = new Node(sum % 10);
        Sum->next = temp;
        Sum = temp;
        head1 = head1->next;
        head2 = head2->next;
    }

    return Sum;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    insertatTAIL(head1, 5);
    insertatTAIL(head1, 6);
    insertatTAIL(head1, 3);
    print(head1);
    cout << getnum(head1) << endl;

    insertatTAIL(head2, 8);
    insertatTAIL(head2, 4);
    insertatTAIL(head2, 2);
    print(head2);

    Node *result = addTwoNumbers(head1, head2);
    print(result);

    return 0;
}
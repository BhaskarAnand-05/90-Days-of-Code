#include "Headerfile.h"
#include"Queue.h"

int n = 100;

class Stack
{

public:
    int top;
    int *array;

    Stack()
    {
        array = new int[n];
        top = -1;
    }
    void push(int val)
    {

        if (top == (n - 1))
        {
            cout << endl
                 << "Overflow";
            return;
        }
        else
            top++;
        array[top] = val;
    }

    char pop()
    {

        if (top == -1)
        {
            cout << endl
                 << "Underflow";
            return -1;
        }
        else
        {
            return array[top--];
        }
    }

    char returntop()
    {
        if (top == -1)
        {
            cout << endl
                 << "Stack Empty";
        }

        return array[top];
    }

    int isempty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

void displaystack(Stack s)
{
    for (int i = s.top; i >= 0; i--)
    {
        cout << s.array[i] << " ";
    }
    cout << endl;
}

void reversequeue(Queue &Q)
{
    Stack s;
    
    if (Q.isempty())
    {
        return;
    }
    
    while (!Q.isempty())
    {
        s.push(Q.pop());
    }

    while (!s.isempty())
    {
        Q.push(s.returntop());
        s.pop();
    }

    return;   
    
}



int main()
{
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    
    displayqueue(q);
    cout<<endl;

    reversequeue(q);
    displayqueue(q);
    cout<<endl;


    return 0;
}
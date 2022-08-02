#include "Headerfile.h"

class Queue
{
private:
    int N = 100;
    int *array;
    int front;
    int rear;

public:
    Queue()
    {
        array = new int[N];
        front = rear = -1;
    }

    void enqueue(int val)
    {
        if (rear == N - 1)
        {
            cout << "Overflow" << endl;
            return;
        }

        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }

        
        array[rear] = val;
        rear++;
    }

    int dequeue()
    {
        if (front > rear || front == -1)
        {
            cout << "Empty Queue" << endl;
            return -1;
        }

        return array[front++];
    }

    int Front()
    {
        if (front > rear || front == -1)
        {
            cout << "Empty Queue" << endl;
            return -1;
        }

        return array[front];
    }

    int size()
    {
        return (rear - front + 1);
    }

    bool isEmpty()
    {
        if (front > rear || front == -1)
        {
            return true;
        }
        else
            return false;
    }
};

int n=100;

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

// Queue Reversal Function
Queue rev(Queue Q)
{
    Stack S;
    if (Q.isEmpty())
    {
        return Q;
    }

    while (!Q.isEmpty())
    {
        S.push(Q.Front());
        Q.dequeue();
    }

    while (!S.isempty())
    {
        Q.enqueue(S.returntop());
        S.pop();
    }

    return Q;
}

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.Front() << endl;
    // q.dequeue();

    // cout << q.Front() << endl;
    // q.dequeue();

    // cout << q.Front() << endl;
    // q.dequeue();

    // cout << q.Front() << endl;
    // q.dequeue();

    Queue Q = rev(q);
    cout << Q.Front() << endl;
    // q.isEmpty();
    return 0;
}
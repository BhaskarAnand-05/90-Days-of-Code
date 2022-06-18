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

    void push(int val)
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

    int pop()
    {
        if (front > rear || front == -1)
        {
            cout << "Empty Queue" << endl;
            return -1;
        }

        return array[front++];
    }

    int top()
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

    bool isempty()
    {
        if (front > rear || front == -1)
        {
            return true;
        }
        else
            return false;
    }
};

int main()
{
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.top() << endl;
    q.pop();

    cout << q.top() << endl;
    q.pop();

    cout << q.top() << endl;
    q.pop();

    cout << q.top() << endl;
    q.pop();
    // q.isempty();
    return 0;
}
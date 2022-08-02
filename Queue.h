#include "Headerfile.h"

class Queue
{
public:
    int N = 100;
    int *array;
    int front;
    int rear;

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

void displayqueue(Queue Q)
{
    int i;
    if (Q.front == -1)
    {
        printf("Queue is empty \n");
        return;
    }
    else
    {
        for (i = Q.front; i <= Q.rear-1; i++)
            printf("%d ", Q.array[i]);
        cout << endl;
    }
}
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

int n = 100;

class Stack
{

public:
    int top;
    char *array;

    Stack()
    {
        array = new char[n];
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

    void pop()
    {

        if (top == -1)
        {
            cout << endl
                 << "Underflow";
            return ;
        }
        
        top--;
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

// Infix to postfix

int retprecedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
        return -1;
}

string infixtopostfix(string &str)
{
    Stack s;
    string res;
    int i = 0;

    while (str[i])
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            res += str[i];
        }

        else if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!s.isempty() && s.returntop() != '(')
            {
                res += s.returntop();
                s.pop();
            }
            
            // to pop '('  
            if (!s.isempty())
            {
                s.pop();
            }
        }

        else
        {
            while (!s.isempty() && (retprecedence(s.returntop()) > retprecedence(str[i])))
            {
                res += s.returntop();
                s.pop();
            }
            s.push(str[i]);
        }

        i++;
    }

    while (!s.isempty())
    {
        res += s.returntop();
        s.pop();
    }

    return res;
}

int main()
{
    string s = "(a-b/c)*(a/k-l)";

    string result = infixtopostfix(s);
    

    cout<<endl<<result;
    // Queue q;

    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);
    // q.enqueue(4);

    // cout << q.Front() << endl;
    // q.dequeue();

    // cout << q.Front() << endl;
    // q.dequeue();

    // cout << q.Front() << endl;
    // q.dequeue();

    // cout << q.Front() << endl;
    // q.dequeue();

    // Queue Q = rev(q);
    // cout << Q.Front() << endl;
    // q.isEmpty();
    return 0;
}
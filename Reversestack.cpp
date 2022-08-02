#include "Headerfile.h"

class Stack
{

public:
    int n = 100;
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

void putelement(Stack &s, int element)
{
    if (s.isempty())
    {
        s.push(element);
        return;
    }
    
    int topelement=s.returntop();
    s.pop();

    putelement(s,element);
    s.push(topelement);
    
}

void reversestack( Stack & s)
{
    if (s.isempty())
    {
        return;
    }   

    int endelement;
    endelement= s.returntop();
    s.pop();
    reversestack(s);

    putelement(s,endelement);
    
}

int main()
{
    Stack s;

    s.push(50);
    s.push(45);
    s.push(20);
    s.push(30);
    s.push(60);

    reversestack(s);

    displaystack(s);
    return 0;

}
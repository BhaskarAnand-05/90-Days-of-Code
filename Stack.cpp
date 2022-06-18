#include "Headerfile.h"

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

int postfix(string str)
{
    Stack s;
    int a = 0, b = 0;
    int temp = 0;


    for (int i = 0; str[i]; ++i)
    {
        if (isdigit(str[i]))
        {
            s.push(str[i]-'0');
        }
        else
        {
            a = s.pop();
            b = s.pop();
            switch (str[i])
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(b - a);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                s.push(a / b);
                break;

            default:
                break;
            }
        }
    }

    return s.pop();
    
}

int main()
{
    string str;
    cin>>str;

    cout << endl
         << postfix(str);

    // Stack s;

    // s.push(50);
    // s.push(45);
    // s.push(20);
    // s.push(30);
    // s.push(60);

    // displaystack(s);

    // int val = s.returntop();

    // cout << val<<
    //           endl;
    // s.pop();

    // int value = s.returntop();

    // cout<< value <<endl;
    return 0;
}
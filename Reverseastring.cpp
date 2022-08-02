#include "Headerfile.h"

class stack
{
private:
    int n = 100;
    char *array;
    int top;

public:
    stack()
    {
        array = new char[n];
        top = -1;
    }

    void push(char val)
    {
        if (top == n - 1)
        {
            cout << "Overflow" << endl;
            return;
        }

        top++;
        array[top] = val;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Underflow" << endl;
            return -1;
        }

        return array[top--];
    }

    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};

void reversestr(string & str)
{
    stack s1;

    // if (strlen(str)==0)
    // {
    //     cout<<"String Empty"<<endl;
    //     return;
    // }

    int i = 0;

    while (str[i])
    {
        s1.push(str[i]);
        i++;
    }

    int j = 0;
    while (!s1.isempty())
    {
        str[j] = s1.pop();
        j++;
    }

    return ;
}

int main()
{
    string s;

    cin>>s;

    reversestr(s);
   
    cout<<endl<<s;

    return 0;
}
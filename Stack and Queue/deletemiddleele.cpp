#include "Headerfile.h"
#include <stack>

void solve(stack<int> &inputstack, int size, int count)
{
    if (inputstack.empty())
    {
        cout << "Stack Empty" << endl;
        return;
    }

    if (count == size / 2)
    {
        inputstack.pop();
        return;
    }

    int ele = 0;
    ele = inputstack.top();
    inputstack.pop();

    solve(inputstack, size, count + 1);

    inputstack.push(ele);
}

void deleteMiddleElement(stack<int> &inputstack, int size)
{

    int count = 0;

    solve(inputstack, size, count);
}

void displaystack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);

    displaystack(S);

    deleteMiddleElement(S, 5);

    displaystack(S);

    deleteMiddleElement(S, 5);

    displaystack(S);

    deleteMiddleElement(S, 5);

    displaystack(S);

   
    return 0;
}

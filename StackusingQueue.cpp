#include "Headerfile.h"
#include "Queue.h"

class StackusingQueue
{
private:
    int n;
    Queue q1;
    Queue q2;

public:
    StackusingQueue()
    {
        n = 0;
    }

    void push(int val)
    {
        // if (q1.isempty())
        // {
        //     return;
        // }

        q2.push(val);
        n++;

        while (!q1.isempty())
        {
            q2.push(q1.top());
            q1.pop();
        }

        Queue temp = q2;
        q2 = q1;
        q1 = temp;
    }
    void Pop()
    {
        q1.pop();
        n--;
    }

    int top()
    {
        return q1.top();
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

int main()
{
    StackusingQueue s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    displaystack(s1);
    return 0;
}
#include"Headerfile.h"
#include"Queue.h"
#include"stack.h"

void reversekelequeue(Queue &q, int num)
{
    int count=0;
    int temp=0;
    Stack s;
    while (!q.isempty() && count<num)
    {
        s.push(q.pop());
        count++;
    }

    while (!s.isempty())
    {
        q.push(s.returntop());
        s.pop();
    }
    while (!q.isempty() &&  temp< (q.size()-num-1))
    {
        q.push(q.pop());
        temp++;
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
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);

    displayqueue(q);

    reversekelequeue(q,6);
    displayqueue(q);
    return 0;
}
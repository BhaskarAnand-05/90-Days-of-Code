#include "Headerfile.h"
#include "linkedlist.h"
class queue
{
private:
    node *front;
    node *back;

public:
    queue()
    {
        front = back=NULL;
    }

    void push(int val)
    {
       node*n=new node(val);

       if (front==NULL)
       {
         front=n;
         back = front;
         return;
       }
       back->next=n; 
       back=n;    
              
    }

    void pop()
    {
        if (front==NULL)
        {
            return;
        }
        
        deleteatBEG(front);
    }

    int top()
    {
        return front->data;
    }

    bool isEmpty()
    {
        if (front==NULL)
        {
            return true;
        }
        
        return false;
    }


};

int main()
{
    // node *head;

    // insertatTAIL(head, 1);
    // insertatTAIL(head, 2);
    // insertatTAIL(head, 3);
    // insertatTAIL(head, 4);
    // insertatTAIL(head, 5);

    // display(head);

    // deleteatBEG(head);
    // display(head);
    queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<q.top()<<endl;
    q.pop();
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    q.pop();
    cout<<endl<<q.isEmpty();

    return 0;
}
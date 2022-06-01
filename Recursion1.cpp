#include "Headerfile.h"

int Sum(int n)
{
    if (n==0)
    {
        return 0;            ///////////// THIS IS TO STOP AT N==0 OTHERWISE THE N-1 WILL LEAD TO MINUS INFINITY
    }
    
    int prevsum= Sum(n - 1);
    return n + prevsum;
}

int main()
{
    int n;

    cout<<"Enter n\n";
    cin >> n;

       cout << "Sum= " << Sum(n);

    return 0;
}

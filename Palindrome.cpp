#include "Headerfile.h"
int  isPalindrome(int x)
    {
        int num = 0;
        while (x!=0)
        {
            num = num * 10 + (x % 10);
            x = x / 10;
        }

        return num;

        // if (num == x)
        //     return num;

        // else
        //     return false;
    }
int main()
{
    int x = 635;

    cout<< isPalindrome(x);

    return 0;

}
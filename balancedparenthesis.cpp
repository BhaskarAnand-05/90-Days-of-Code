#include "Headerfile.h"
#include "stack.h"

bool BalancedPraenthesis(string str)
{
    int i = 0;
    Stack s;
    int flag = 0;

    while (str[i])
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else
        {

            if (s.isempty())
            {
                return false;
            }
            char ch;
            ch = s.pop();

            if (ch == '(' && str[i] == ')' || (ch == '{' && str[i] == '}') || (ch == '[' && str[i] == ']'))
            {
                continue;
            }

            else
                return false;
        }
        i++;
    }
    return s.isempty();
    
}

int main()
{
    string s = "((((()))))";

    cout << BalancedPraenthesis(s) << endl;
    return 0;
}
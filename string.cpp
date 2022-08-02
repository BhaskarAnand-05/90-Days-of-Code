#include"Headerfile.h"

int main()
{
    int count=0;
    char* s = "string";
    for (int i = 0; s[i]; i++)
    {
        count=i;
    }
    cout<< count<< endl;
    cout<< strlen(s);
    return 0;
}
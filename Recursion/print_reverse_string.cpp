#include<bits/stdc++.h>

using namespace std;

void reverse(string str)
{
    string revstring;
    int n;
    n= sizeof(str);
    if (str == "/0")
    {
        cout<<"Entered string is empty";
    }

    else 
    {
       for (int i = 0; i <= n; i++)
       {
           for (int j = n; j >= 0; j--)
           {
               revstring[i] = str[j];
           }
           
       }
       
    }

    cout<<"\n Thre verse string = "<< revstring;

}
int main()
{
    string name;
    cout<<"Enter Name ";
    cin>>name;
    reverse(name);
    return 0;
}
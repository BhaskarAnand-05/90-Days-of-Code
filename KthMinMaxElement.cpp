#include <iostream>
using namespace std;

// Function to sort the array
void bubb_sort( int arr[], int size)
{
    int temp=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                }
        }
        
    }
    
}
void getMinMax(int arr[],int Size,int K)
{
   int arrK_max=0;
   int arrK_min=0; 
   bubb_sort(arr,Size);
   for (int  i = 0; i < Size; i++)
   {
       cout<<arr[i]<<endl;
   }
   
   arrK_max=arr[Size-K];
   arrK_min=arr[K-1];
   cout<<"The Kth Max Element is "<<arrK_max<<endl;
   cout<<"The Kth Min Element is "<<arrK_min;
}




// Driver code
int main()
{
    int arr[] = {7,10,4,3,20,15};
    int arr_size = 7;
    int k;
    cin>>k;
    getMinMax(arr, arr_size,k);

    return 0;
}
// C++ program of above implementation
#include <iostream>
using namespace std;


void getMinMax(int arr[], int size)
{   //  If there is only one element in the array then
    int arr_min=arr[0];
    int arr_max=arr[0];

    // If there are only two  elements in the array
    if (arr[0] < arr [1]){
        arr_min = arr[0];
        arr_max = arr[1];
    }
    else
    {   arr_min = arr[1];
        arr_max = arr[0];        
    }
    
    for (int  i = 0; i < size; i++)
    {
        if(arr[i] < arr_min)
        {
            arr_min=arr[i];
        }
        if (arr[i] > arr_max)
        {
            arr_max=arr[i];
        }
        else
        continue;
        
    }
    cout << "Minimum element is "
         << arr_min << endl;
    cout << "Maximum element is "
         << arr_max;
}

// Driver code
int main()
{
    int arr[] = {1000, 11, 445,
                 1, 330, 3000};
    int arr_size = 6;

    getMinMax(arr, arr_size);

    return 0;
}

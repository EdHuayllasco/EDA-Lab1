#include  <iostream>
using namespace std;
int shellSort(int arr[], int n)
{
    for (int i = n/2; i > 0; i /= 2)
    {
        for (int j = i; j < n; j += 1)
        {
            int temp = arr[j];
            int z;           
            for (z = j; z >= i && arr[z - i] > temp; z -= i)
                arr[z] = arr[z - i];
            arr[z] = temp;
        }
    }
    return 0;
}
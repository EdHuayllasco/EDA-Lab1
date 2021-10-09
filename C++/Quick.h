#include<iostream>
using namespace std;
int partition (int arr[], int inicio, int fin)
{
    int pivote = arr[fin]; 
    int i = (inicio - 1); 
 
    for (int j = inicio; j <= fin- 1; j++)
    {
        if (arr[j] <= pivote)
        {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[fin]);
    return (i + 1);
}
void quickSort(int arr[], int inicio, int fin)
{
    if (inicio < fin)
    {
        int pi = partition(arr, inicio, fin);
        quickSort(arr, inicio, pi - 1);
        quickSort(arr, pi + 1, fin);
    }
}
#include <iostream>
using namespace std;
void heap_rec(int arr[], int n, int i)
{
    int max_largo = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    if (l < n && arr[l] > arr[max_largo])
        max_largo = l;
    if (r < n && arr[r] > arr[max_largo])
        max_largo = r;
    if (max_largo != i) {
        swap(arr[i], arr[max_largo]);
        heap_rec(arr, n, max_largo);
    }
}
 
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heap_rec(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heap_rec(arr, i, 0);
    }
}
#include <iostream>
using namespace std;
int insertionSortCosto(int arr[], int n){
    int asign=0, compa=0;
    int key, j;
    asign +=8;
    for (int i = 1; i < n; i++){
        compa+=2;
        key = arr[i];
        j = i - 1;
        asign+=16;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
            asign+=16;
        }compa+=4;
        arr[j + 1] = key;
        asign+=8;
    }compa+=2;
   return asign+compa;
}
void insertionSort(int arr[], int n) //SORT
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
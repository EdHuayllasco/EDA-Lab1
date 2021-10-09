#include <iostream>
using namespace std;
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)     
    for (j = 0; j < n-i-1; j++) 
        if (arr[j] > arr[j+1]) 
            swap(&arr[j], &arr[j+1]); 
} 
int bubbleSortCosto(int arr[], int n) { 
    int asig=0, comp=0;
    int temp;
    for (int i = 0; i < n-1; i++) {
        comp+=2;
        asig+=8;
        for (int j = 0; j < n-i-1; j++) {
            comp+=2;
            if (arr[j] > arr[j+1]) {
                comp+=2;

                temp = arr[j];      asig+=8;
                arr[j] = arr[j+1];  asig+=8;
                arr[j+1] = temp;    asig+=8;
            }
            else
                comp+=2;
        }comp += 2;
    }comp += 2;
    return comp+asig;   
} 
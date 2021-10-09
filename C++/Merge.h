#include <iostream>
using namespace std;

void merge(int array[], int izq, int mid, int derecha)
{
    auto const subarrayuno = mid - izq + 1;
    auto const subarraidos = derecha - mid;

    auto *izqArray = new int[subarrayuno],
         *derechaArray = new int[subarraidos];

    for (auto i = 0; i < subarrayuno; i++)
        izqArray[i] = array[izq + i];
    for (auto j = 0; j < subarraidos; j++)
        derechaArray[j] = array[mid + 1 + j];

    auto indicedesubarrayuno = 0,  
        indicedesubarraidos = 0;  
    int indicedeMergedArray = izq; 

    while (indicedesubarrayuno < subarrayuno && indicedesubarraidos < subarraidos)
    {
        if (izqArray[indicedesubarrayuno] <= derechaArray[indicedesubarraidos])
        {
            array[indicedeMergedArray] = izqArray[indicedesubarrayuno];
            indicedesubarrayuno++;
        }
        else
        {
            array[indicedeMergedArray] = derechaArray[indicedesubarraidos];
            indicedesubarraidos++;
        }
        indicedeMergedArray++;
    }
    while (indicedesubarrayuno < subarrayuno)
    {
        array[indicedeMergedArray] = izqArray[indicedesubarrayuno];
        indicedesubarrayuno++;
        indicedeMergedArray++;
    }
    while (indicedesubarraidos < subarraidos)
    {
        array[indicedeMergedArray] = derechaArray[indicedesubarraidos];
        indicedesubarraidos++;
        indicedeMergedArray++;
    }
}
void mergeSort(int array[], int inicio, int fin)
{
    // Caso base
    if (inicio >= fin)
        return;

    int mid = inicio + (fin - inicio) / 2;
    mergeSort(array, inicio, mid);
    mergeSort(array, mid + 1, fin);
    merge(array, inicio, mid, fin);
}
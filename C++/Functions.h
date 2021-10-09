#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime> 
#include <fstream>
#include "Bubblesort.h"
#include "Insertion.h"
#include "Heap.h"
#include "Selection.h"
#include "Shell.h"
#include "Quick.h"
#include "Merge.h"
using namespace std;
void Generar_espacio(int **&a,int num_arreglo, int tamano){
    // GENERAMOS ESPACIO DE MEMORIA
    a = new int*[num_arreglo];
    for (int i = 0; i < num_arreglo; i++)
    {
        *(a+i)=new int[tamano];
    }
}
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 
int **Copia(int num_arreglo,int tamano){ 
    int** Matriz;
    Generar_espacio(Matriz,num_arreglo,tamano);
    ifstream arch("Entrada.txt", ifstream::in); 
    int a;
    for (int j=0;j<tamano;j++){
        arch >> a;
        Matriz[0][j]=a;
    }       
    return Matriz;
}
double timeforarray(int **a , int num_arreglo, int tamano){
    int  **Matriz = Copia(num_arreglo,tamano);
    unsigned t0, t1;
    double media_time= 0;    
    // TOMAMOS EL TIEMPO QUE DEMORA EL INSERTIONSORT EN ORDENAR CADA UNO DE LOS 10 ARRAYS   
    for (int i = 0; i < num_arreglo; i++)
    {        
        t0=clock();
        insertionSort(*(Matriz+i),tamano);
        t1 = clock();
        //CALCULAMOS EL TIEMPO EN MILISEGUNDOS
        double time = (double(t1-t0)/CLOCKS_PER_SEC*1000);
        media_time = media_time + time;
    }
    // SE CALCULA  EL PROMEDIO
    media_time = media_time/num_arreglo;
    //RETORNAMOS EL PROMEDIO
    return media_time;
}
double timeforarrayBubble(int **a , int num_arreglo, int tamano){
    int  **Matriz = Copia(num_arreglo,tamano);
    unsigned t0, t1;
    double media_time= 0;    
    // TOMAMOS EL TIEMPO QUE DEMORA EL INSERTIONSORT EN ORDENAR CADA UNO DE LOS 10 ARRAYS   
    for (int i = 0; i < num_arreglo; i++)
    {        
        t0=clock();
        bubbleSort(*(Matriz+i),tamano);
        t1 = clock();
        //CALCULAMOS EL TIEMPO EN MILISEGUNDOS
        double time = (double(t1-t0)/CLOCKS_PER_SEC*1000);
        media_time = media_time + time;
    }
    // SE CALCULA  EL PROMEDIO
    media_time = media_time/num_arreglo;
    //RETORNAMOS EL PROMEDIO
    return media_time;
}
double timeofarrayHeap(int **a , int num_arreglo, int tamano){
    int  **Matriz = Copia(num_arreglo,tamano);
    unsigned t0, t1;
    double media_time= 0;    
    // TOMAMOS EL TIEMPO QUE DEMORA EL INSERTIONSORT EN ORDENAR CADA UNO DE LOS 10 ARRAYS   
    for (int i = 0; i < num_arreglo; i++)
    {        
        t0=clock();
        heapSort(*(Matriz+i),tamano);
        t1 = clock();
        //CALCULAMOS EL TIEMPO EN MILISEGUNDOS
        double time = (double(t1-t0)/CLOCKS_PER_SEC*1000);
        media_time = media_time + time;
    }
    // SE CALCULA  EL PROMEDIO
    media_time = media_time/num_arreglo;
    //RETORNAMOS EL PROMEDIO
    return media_time;
}
double timeofSelection(int **a , int num_arreglo, int tamano){
    int  **Matriz = Copia(num_arreglo,tamano);
    unsigned t0, t1;
    double media_time= 0;    
    // TOMAMOS EL TIEMPO QUE DEMORA EL INSERTIONSORT EN ORDENAR CADA UNO DE LOS 10 ARRAYS   
    for (int i = 0; i < num_arreglo; i++)
    {        
        t0=clock();
        selectionSort(*(Matriz+i),tamano);
        t1 = clock();
        //CALCULAMOS EL TIEMPO EN MILISEGUNDOS
        double time = (double(t1-t0)/CLOCKS_PER_SEC*1000);
        media_time = media_time + time;
    }
    // SE CALCULA  EL PROMEDIO
    media_time = media_time/num_arreglo;
    //RETORNAMOS EL PROMEDIO
    return media_time;
}
double timeofShell(int **a , int num_arreglo, int tamano){
    int  **Matriz = Copia(num_arreglo,tamano);
    unsigned t0, t1;
    double media_time= 0;    
    // TOMAMOS EL TIEMPO QUE DEMORA EL INSERTIONSORT EN ORDENAR CADA UNO DE LOS 10 ARRAYS   
    for (int i = 0; i < num_arreglo; i++)
    {        
        t0=clock();
        shellSort(*(Matriz+i),tamano);
        t1 = clock();
        //CALCULAMOS EL TIEMPO EN MILISEGUNDOS
        double time = (double(t1-t0)/CLOCKS_PER_SEC*1000);
        media_time = media_time + time;
    }
    // SE CALCULA  EL PROMEDIO
    media_time = media_time/num_arreglo;
    //RETORNAMOS EL PROMEDIO
    return media_time;
}
double timeofQuick(int **a , int num_arreglo, int tamano){
    int  **Matriz = Copia(num_arreglo,tamano);
    unsigned t0, t1;
    double media_time= 0;    
    // TOMAMOS EL TIEMPO QUE DEMORA EL INSERTIONSORT EN ORDENAR CADA UNO DE LOS 10 ARRAYS   
    for (int i = 0; i < num_arreglo; i++)
    {        
        t0=clock();
        quickSort(*(Matriz+i),0,tamano-1);
        t1 = clock();
        //CALCULAMOS EL TIEMPO EN MILISEGUNDOS
        double time = (double(t1-t0)/CLOCKS_PER_SEC*1000);
        media_time = media_time + time;
    }
    // SE CALCULA  EL PROMEDIO
    media_time = media_time/num_arreglo;
    //RETORNAMOS EL PROMEDIO
    return media_time;
}
double timeofMerge(int **a , int num_arreglo, int tamano){
    int  **Matriz = Copia(num_arreglo,tamano);
    unsigned t0, t1;
    double media_time= 0;    
    // TOMAMOS EL TIEMPO QUE DEMORA EL INSERTIONSORT EN ORDENAR CADA UNO DE LOS 10 ARRAYS   
    for (int i = 0; i < num_arreglo; i++)
    {        
        t0=clock();
        mergeSort(*(Matriz+i),0,tamano-1);
        t1 = clock();
        //CALCULAMOS EL TIEMPO EN MILISEGUNDOS
        printArray(*(Matriz+i),tamano);
        double time = (double(t1-t0)/CLOCKS_PER_SEC*1000);
        media_time = media_time + time;
    }
    // SE CALCULA  EL PROMEDIO
    media_time = media_time/num_arreglo;
    //RETORNAMOS EL PROMEDIO
    return media_time;
}
void sumaPromediosGeneral(ofstream& Salida1,int **a, int num_arreglo, int tamano){
    //Salida1<<timeforarray(a,num_arreglo,tamano)<<" ";
    Salida1<<timeforarrayBubble(a,num_arreglo,tamano)<<" ";
    //Salida1<<timeofarrayHeap(a,num_arreglo,tamano)<<" ";
    //Salida1<<timeofSelection(a,num_arreglo,tamano)<<" ";
    //Salida1<<timeofShell(a,num_arreglo,tamano)<<" ";
    //Salida1<<timeofQuick(a,num_arreglo,tamano)<<" ";
    //Salida1<<timeofMerge(a,num_arreglo,tamano)<<endl;
}
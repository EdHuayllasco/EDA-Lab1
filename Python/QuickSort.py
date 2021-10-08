from time import time

# QuickSort  
def partition(start, end, array):
    pivot_index = start 
    pivot = array[pivot_index]
    while start < end:
        while start < len(array) and array[start] <= pivot:
            start += 1
        while array[end] > pivot:
            end -= 1
        if(start < end):
            array[start], array[end] = array[end], array[start]
    array[end], array[pivot_index] = array[pivot_index], array[end]
    return end
def quickSort(start, end, array):
    if (start < end):
        p = partition(start, end, array)
        quickSort(start, p - 1, array)
        quickSort(p + 1, end, array)
# Funcion para leer el archivo txt con N numeros 
def lectura(N):
    arreglo = []
    arr = []
    arch = open('Entrada.txt', 'r')
    for linea in arch:
        arreglo.append(int(linea))
    arch.close() 
    for i in range (N):
        arr.append(arreglo[i])
    return arr
# Funcion para imprimir un arreglo
def imprimir(arr):
    f = open ('Salida.txt','w')
    f.writelines(str(arr))
    f.close() 

#Main
N = int(input())
arr = lectura(N) # N -> cantidad de numeros del arreglo
# Tiempos
start = time()
quickSort(0,N-1,arr)
finish = time()
print((finish-start)*1000,end = '')
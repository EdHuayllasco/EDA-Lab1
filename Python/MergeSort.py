from time import time

# MergeSort
def mergeSort(arr):
    if len(arr) > 1:
        mid = len(arr)//2
        L = arr[:mid]
        R = arr[mid:]
        mergeSort(L)
        mergeSort(R)
        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1
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
mergeSort(arr)
finish = time()
print((finish-start)*1000,end = '')
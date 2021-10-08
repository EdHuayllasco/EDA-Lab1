from time import time

# Bubble Sort
def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]
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
bubbleSort(arr)
finish = time()
print((finish-start)*1000,end = '')
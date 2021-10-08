from time import time

# InsertionSort
def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = key
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
insertionSort(arr)
finish = time()
print((finish-start)*1000,end = '')
from time import time

# Selection Sort
def selectionSort(arr):
    temp = 0
    arr2 = arr.copy()
    for i in range(len(arr2)):
        minimo = i
        for j in range(i+1,len(arr2)):
            if arr2[minimo] > arr2[j]:
                minimo = j
        temp = arr2[i]
        arr2[i] = arr2[minimo]
        arr2[minimo] = temp
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
selectionSort(arr)
finish = time()
imprimir(arr)
print((finish-start)*1000,end = '')
#include <iostream>
#include <fstream>
#include "Functions.h"
using namespace std;
int main (){    
    ifstream archivo;
    ofstream Salida1;    
    
    archivo.open("input.txt",ios::in);
    Salida1.open("salida1.txt",ios::out);
    //LEEMOS EL ARCHIVO
    while (!archivo.eof())
    {   
        int **a, num_arreglo, tamano;
        archivo>>num_arreglo>>tamano;            
        //ESCRIBIMOS EN NUESTRO ARCHIVO DE SALIDA
        Salida1<<tamano<<" ";
        Generar_espacio(a,num_arreglo,tamano);
        sumaPromediosGeneral(Salida1, a,num_arreglo,tamano);
    }
    Salida1.close();
}

#include <iostream>

using namespace std;

void mostrar(int arr[], int tam) {
    for (int i = 0; i < tam; i++)
        cout << " " << arr[i];
    cout << endl;
}

void CountingSort(int arr[], int tam) {
    const int rango = 10;
    int arr_rango[rango] = { 0 };
    int arr_ord[rango] = { 0 };

    for (int j = 0; j < rango; j++)                //contamos la cantidad de veces..
        for (int i = 0; i < tam; i++)              //..que se repiten los elementos
            if (arr[i] == j)
                arr_rango[j] += 1;

    for (int i = 0; i < rango-1; i++)                //hacemos las sumas acumuladas..
        arr_rango[i + 1] += arr_rango[i];            //..para obtener las posiciones

    for (int i = 0; i < tam; i++) {                          //asignamos cada elemento..
        arr_ord[arr_rango[arr[i]] - 1] = arr[i];             //..a la posicion que 
        arr_rango[arr[i]] -= 1;                              //..le corresponde
        //disminuimos en 1 al elemento del arreglo.. 
    }   //..de sumas para no repetir posiciones

    for (int i = 0; i < tam; i++)           //copiamos el arreglo ordenado al arreglo original
        arr[i] = arr_ord[i];
}

int main()
{
    int arr[] = { 7, 4, 1, 2, 7, 5, 2 };
    int tam = 7;

    mostrar(arr, tam);

    CountingSort(arr, tam);
    
    mostrar(arr, tam);

    return 0;
}


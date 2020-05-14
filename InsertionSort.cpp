
#include <iostream>

using namespace std;

void mostrar(int arr[], int tam) {
    for (int i = 0; i < tam; i++)
        cout << " " << arr[i];
    cout << endl;
}

void insertionSort(int arr[], int tam) {
    int actual, j;
    for (int i = 1; i < tam; i++) {         //recorremos el arreglo desde la posicion 1
        actual = arr[i];                    
        j = i - 1;
        while (arr[j] > actual && j >= 0) {    //recorremos la parte izquierda del arreglo
            arr[j + 1] = arr[j];               
            j--;
        }
        arr[j + 1] = actual;              //establecemos el elemento actual...
    }                                     //...en la posicion que le corresponde
}

int main()
{
    int arr[] = { 3,4,1,5,2 };
    int tam = 5;

    mostrar(arr, tam);

    insertionSort(arr, tam);

    mostrar(arr, tam);

    return 0;
}


#include <iostream>

using namespace std;

void mostrar(int arr[], int tam) {
    for (int i = 0; i < tam; i++)
        cout << " " << arr[i];
    cout << endl;
}

void intercambiar(int& a, int& b){
    int aux = a;
    a = b;
    b = aux;
}

void SelectionSort(int arr[], int tam) {
    int indice_menor;                            //posicion del elemento menor
    for (int i = 0; i < tam-1; i++) {
        indice_menor = i;
        for(int j = i + 1 ; j < tam ; j++)           //ubicamos el elemento menor
            if (arr[j] < arr[indice_menor])
                indice_menor = j;
        intercambiar(arr[indice_menor],arr[i]);        //establecemos al elemento menor..
    }                                                  //..en las primeras posiciones
}

int main()
{
    int arr[] = { 3,1,5,2,4 };
    int tam = 5;

    mostrar(arr, tam);

    SelectionSort(arr, tam);

    mostrar(arr, tam);

    return 0;
}

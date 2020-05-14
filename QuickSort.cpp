
#include <iostream>

using namespace std;

void mostrar(int arr[], int tam) {
    for (int i = 0; i < tam; i++)
        cout << " " << arr[i];
    cout << endl;
}

void intercambiar(int& a, int& b) {
    int aux = a;
    a = b;
    b = aux;
}

int particion(int arr[], int menor, int mayor) {
    int pivote = arr[mayor];                // el pivote sera el ultimo elemento
    int i = (menor - 1);                // indice de el elemento mas pequeño

    for (int j = menor; j <= mayor - 1; j++)         //si el elemento actual es mas pequeño..  
        if (arr[j] <= pivote) {                        //..que o igual al pivote
            i++;                                // incrementa el indice del elemento mas pequeño
            intercambiar(arr[i], arr[j]);
        }
    intercambiar(arr[i + 1], arr[mayor]);
    return (i + 1);
}

void quickSort(int arr[], int menor, int mayor) {
    if (menor < mayor) {
        int indice_part = particion(arr, menor, mayor);

        quickSort(arr, menor, indice_part - 1);
        quickSort(arr, indice_part + 1, mayor);
    }
}

int main()
{
    int arr[] = { 2,4,1,5,3 };
    int tam = 5;

    mostrar(arr, tam);

    quickSort(arr, 0, tam - 1);

    mostrar(arr, tam);

    return 0;
}


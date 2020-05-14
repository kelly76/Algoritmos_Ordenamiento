
#include<iostream> 

using namespace std;

void mostrar(int arr[], int tam) {
	for (int i = 0; i < tam; i++)
		cout << " " << arr[i];
	cout << endl;
}

int mayor(int arr[], int tam) {           //encuentra el mayor elemento de un arreglo
	int mayor = arr[0];
	for (int i = 1; i < tam; i++)
		if (arr[i] > mayor)
			mayor = arr[i];
	return mayor;
}

void insertionSort(int arr[], int tam, int exp) {
	int actual_dig, j, actual_elem;
	for (int i = 0; i < tam; i++) {
		actual_dig = (arr[i] / exp) % 10;             //contiene el digito
		actual_elem = arr[i];                       //contiene el elemento original
		j = i - 1;
		while (j >= 0 && (arr[j] / exp) % 10 > actual_dig) {    //comparamos por digitos
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = actual_elem;            //asignamos el elemento original
	}
}

void countingSort(int arr[], int tam, int exp)
{
	const int rango = 10;
	int arr_ord[rango] = { 0 };
	int arr_count[rango] = { 0 };

	for (int i = 0; i < tam; i++)                //numero de repeticiones de cada elemento
		arr_count[(arr[i] / exp) % 10]++;          //(arr[i] / exp) % 10 nos da los digitos
												    

	for (int i = 1; i < 10; i++)                  //obtenenemos las posiciones
		arr_count[i] += arr_count[i - 1];         
 
	for (int i = tam - 1; i >= 0; i--) {                       //asignamos los elementos originales
		arr_ord[arr_count[(arr[i] / exp) % 10] - 1] = arr[i]; 
		arr_count[(arr[i] / exp) % 10]--;
	}

	for (int i = 0; i < tam; i++)
		arr[i] = arr_ord[i];
}

void radixSort(int arr[], int tam) {                  //funcion principal

	int myr = mayor(arr, tam);
 
	for (int exp = 1; myr / exp > 0; exp *= 10) {        
		//countingSort(arr, tam, exp);                      //podemos utilizar diversos.. 
		insertionSort(arr, tam, exp);                       //..algoritmos de ordenamiento
	}
}

int main()
{
	int arr[] = { 34,78,105,1,13 };
	int tam = 5;

	mostrar(arr, tam);

	radixSort(arr, tam);

	mostrar(arr, tam);

	return 0;
}


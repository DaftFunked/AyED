#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para intercambiar dos elementos en un vector
void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Función para dividir el arreglo y colocar el pivote en su posición correcta
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // seleccionamos el último elemento como pivote
    int i = low - 1; // índice del elemento más pequeño

    for (int j = low; j < high; j++) {
        // Si el elemento actual es menor o igual que el pivote
        if (arr[j] <= pivot) {
            i++; // incrementamos el índice del elemento más pequeño
            swap(arr, i, j); // intercambiamos arr[i] y arr[j]
        }
    }
    swap(arr, i + 1, high); // colocamos el pivote en su posición correcta
    return i + 1; // retornamos la posición del pivote
}

// Función recursiva para ordenar el arreglo usando QuickSort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // obtenemos la posición del pivote
        int pi = partition(arr, low, high);

        // ordenamos los subarreglos antes y después del pivote
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int N;
    cin >> N;

    // leer los elementos del arreglo
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // procesar las instrucciones
    int M;
    cin >> M;

    char instruction;
    int K;
    bool left_to_right = true; // bandera para indicar el sentido de indizado

    if (M <= 1) {
        return 0; // Si solo hay una instrucción o ninguna, se termina el programa
    }

    // ordenar el arreglo inicial
    quickSort(arr, 0, N - 1); // Se ordena el arreglo inicial

    // Ciclo para procesar las instrucciones
    for (int i = 0; i < M; ++i) {
        cin >> instruction;
        if (instruction == '<') {
            left_to_right = true; // Si la instrucción es '<', se indica el sentido de indizado como de izquierda a derecha
        } else if (instruction == '>') {
            left_to_right = false; // Si la instrucción es '>', se indica el sentido de indizado como de derecha a izquierda
        } else {
            cin >> K; // obtener el índice K
            if (left_to_right) {
                cout << arr[K] << endl; // Si el sentido de indizado es de izquierda a derecha, se imprime el valor del K-ésimo elemento
            } else {
                cout << arr[N - 1 - K] << endl; // Si el sentido de indizado es de derecha a izquierda, se imprime el valor del (N - 1 - K)-ésimo elemento
            }
        }
    }

    return 0; // Se retorna 0 para indicar que el programa se ejecutó correctamente
}
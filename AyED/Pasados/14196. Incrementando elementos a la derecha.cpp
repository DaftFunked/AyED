#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N; // Se lee el valor de N, la cantidad de elementos en el arreglo A
    
    vector<int> A(N); // Se declara un vector A de tamaño N para almacenar los elementos del arreglo
    vector<int> increments(N, 0); // Se declara un vector increments de tamaño N, inicializado con 0s, para llevar el conteo de incrementos
    
    for (int i = 0; i < N; ++i) { // Se itera sobre los elementos del arreglo A
        cin >> A[i]; // Se lee cada elemento del arreglo A y se almacena en el vector A
        if (i > 0 && A[i - 1] % 2 != 0) { // Si el elemento anterior es impar
            increments[i]++; // Se incrementa el contador de incrementos en la posición i
        }
    }
    
    int inc = 0; // Variable para llevar el total de incrementos necesarios
    
    for (int i = N - 2; i >= 0; --i) { // Se itera sobre los elementos del arreglo A en orden inverso, empezando desde el penúltimo elemento
        inc += increments[i + 1]; // Se actualiza el total de incrementos necesarios sumando el incremento en la posición i+1
        if (A[i] % 2 != 0) { // Si el elemento actual es impar
            A[i] += inc; // Se incrementa el elemento actual por el total de incrementos
        }
    }
    
    // Imprimir el arreglo resultante
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " "; // Se imprime cada elemento del arreglo A seguido de un espacio
    }
    cout << endl; // Se imprime un salto de línea al final para un formato más limpio
    
    return 0; // Se retorna 0 para indicar que el programa se ejecutó correctamente
}



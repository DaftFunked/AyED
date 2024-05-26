#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N; // Se lee el valor de N, la cantidad de elementos en el arreglo A
    
    vector<int> A(N); // Se declara un vector A de tamaño N para almacenar los elementos del arreglo
    
    // Se lee cada elemento del arreglo A
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    cin >> M; // Se lee el valor de M, la cantidad de enteros a sumar
    for (int i = 0; i < M; ++i) { // Se itera M veces para leer los enteros a sumar
        int increment;
        cin >> increment; // Se lee el entero a sumar
        if (increment % 2 == 0) { // Si el entero a sumar es par
            for (int j = 0; j < N; j += 2) { // Se itera sobre las posiciones pares del arreglo A
                A[j] += increment; // Se suma el entero a la posición par del arreglo A
            }
        } else { // Si el entero a sumar es impar
            for (int j = 1; j < N; j += 2) { // Se itera sobre las posiciones impares del arreglo A
                A[j] += increment; // Se suma el entero a la posición impar del arreglo A
            }
        }
    }
    
    // Imprimir el arreglo resultante
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " "; // Se imprime cada elemento del arreglo A seguido de un espacio
    }
    cout << endl; // Se imprime un salto de línea al final para un formato más limpio
    
    return 0; // Se retorna 0 para indicar que el programa se ejecutó correctamente
}

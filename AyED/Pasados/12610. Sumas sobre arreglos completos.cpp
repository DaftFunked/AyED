#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M; // Se leen dos enteros: N (tamaño del arreglo) y M (cantidad de incrementos)
    
    vector<int> A(N); // Se declara un vector A de tamaño N para almacenar los elementos del arreglo
    
    // Se lee cada elemento del arreglo A
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Se itera sobre los M incrementos
    for (int i = 0; i < M; ++i) {
        int increment;
        cin >> increment; // Se lee el siguiente incremento
        
        // Se suma el incremento a todos los elementos de A
        for (int j = 0; j < N; ++j) {
            A[j] += increment;
        }
    }
    
    // Imprimir el arreglo resultante
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " "; // Se imprime cada elemento del arreglo A seguido de un espacio
    }
    cout << endl; // Se imprime un salto de línea al final para un formato más limpio
    
    return 0; // Se retorna 0 para indicar que el programa se ejecutó correctamente
}


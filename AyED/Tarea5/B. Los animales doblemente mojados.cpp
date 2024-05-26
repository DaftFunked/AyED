#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    cin >> N; // Leer el número de parejas de enteros

    unordered_set<int> mar1, mar2; // Conjuntos para almacenar los animales en cada mar

    // Leer y procesar las parejas de enteros
    for (int i = 0; i < N; ++i) {
        int A, M;
        cin >> A >> M;

        // Agregar el animal al conjunto correspondiente al mar
        if (M == 1) {
            mar1.insert(A);
        } else if (M == 2) {
            mar2.insert(A);
        }
    }

    int cantidad = 0; // Inicializar contador para animales mojados en ambos mares

    // Iterar sobre los animales en el primer mar
    for (int animal : mar1) {
        // Verificar si el animal está presente en el segundo mar
        if (mar2.count(animal) > 0) {
            cantidad++; // Incrementar el contador si el animal está en ambos mares
        }
    }

    cout << cantidad << endl; // Imprimir la cantidad de animales mojados en ambos mares

    return 0;
}
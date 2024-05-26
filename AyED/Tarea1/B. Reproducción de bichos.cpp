#include <iostream>

using namespace std;

// Función para calcular el número total de bichos después de D días
int total_bichos(int N, int D) {
    // Inicializamos el número de bichos de cada tipo en el primer día
    int A = N; // N bichos de tipo A
    int B = 0; // Inicialmente no hay bichos de tipo B
    int C = 0; // Inicialmente no hay bichos de tipo C

    // Iteramos a través de los días
    for (int i = 0; i < D; ++i) {
        // Calculamos cuántos bichos de cada tipo se producirán en este día
        int nuevoA = 2 * A + C; // Un bicho de tipo A produce 2 de tipo A y 1 de tipo C
        int nuevoB = 3 * B + 3 * A; // Un bicho de tipo B produce 3 de tipo B y 3 de tipo A
        int nuevoC = C + A * 1 + B * 2 + C * 4; // Un bicho de tipo C produce 1 de tipo A, 2 de tipo B y 4 de tipo C

        // Actualizamos el número total de bichos de cada tipo para el siguiente día
        A = nuevoA;
        B = nuevoB;
        C = nuevoC;
    }

    // Calculamos el número total de bichos después de D días
    int total_bichos = A + B + C;
    return total_bichos;
}

int main() {
    // Pedimos al usuario que ingrese los valores de N y D
    int N, D;
    cin >> N >> D;

    // Calculamos y mostramos el número total de bichos después de D días
    cout << total_bichos(N, D) << endl;

    return 0;
}

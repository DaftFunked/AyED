#include <iostream>

using namespace std;

// Función para calcular el N-ésimo número de Fibonacci
int fibonacci(int n, int &f) {
    f++; // Incrementa el contador de llamadas
    if (n <= 1)
        return n;
    // Llama recursivamente a la función para calcular los números de Fibonacci de n-1 y n-2
    return fibonacci(n - 1, f) + fibonacci(n - 2, f);
}

int main() {
    int N;
    cin >> N; // Entrada del usuario: el valor de N

    int F = 0; // Inicializa el contador de llamadas
    // Calcula el N-ésimo número de Fibonacci y cuenta el número de llamadas recursivas
    int result = fibonacci(N, F);

    // Imprime el resultado y el número de llamadas recursivas
    cout << result << " " << F << endl;

    return 0;
}

#include <iostream>

using namespace std;

int main() {
    // Se declara una variable para almacenar el valor de N
    long long N;
    // Se lee el valor de N desde la entrada estándar
    cin >> N;

    // Se calcula la suma de los primeros N términos de la serie utilizando la fórmula de la suma de una progresión aritmética
    // La fórmula es: suma = N * (N + 1) / 2
    long long suma = (N * (N + 1)) / 2;

    // Se imprime la suma total
    cout << suma << endl;

    return 0;
}


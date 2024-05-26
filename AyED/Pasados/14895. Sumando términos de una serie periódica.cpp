#include <iostream>

using namespace std;

int main() {
    // Se declara una variable para almacenar el valor de N
    long long N;
    // Se lee el valor de N desde la entrada estándar
    cin >> N;

    // Calculamos cuántas veces se repite completamente la serie
    long long repeticiones_completas = N / 3;
    
    // Calculamos el resto de la división para determinar los términos adicionales al final
    long long terminos_extra = N % 3;

    // Calculamos la suma de los primeros 3 términos de la serie
    long long suma_base = 1 + 2 + 3;

    // Calculamos la suma total
    long long suma_total = repeticiones_completas * suma_base;

    // Sumamos los términos adicionales al final
    for (int i = 1; i <= terminos_extra; ++i) {
        suma_total += i;
    }

    // Se imprime la suma total
    cout << suma_total << endl;

    return 0;
}


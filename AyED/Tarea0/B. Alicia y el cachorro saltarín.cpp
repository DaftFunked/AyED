#include <iostream>
#include <vector>

using namespace std;

// Función para contar las caídas del cachorro en la posición de Alicia
int contarCaidasCachorro(const vector<int>& saltosCachorro, int posicionAlicia) {
    int caidas = 0; // Inicializamos el contador de caídas del cachorro en la posición de Alicia
    int posicionCachorro = 0; // Inicializamos la posición actual del cachorro

    // Iteramos sobre los saltos del cachorro
    for (size_t i = 0; i < saltosCachorro.size(); ++i) {
        // Actualizamos la posición del cachorro sumando la cantidad de saltos en este momento
        posicionCachorro += saltosCachorro[i];
        
        // Si la posición del cachorro coincide con la posición de Alicia, incrementamos el contador de caídas
        if (posicionCachorro == posicionAlicia) {
            caidas++;
        }
    }

    // Devolvemos el número total de caídas del cachorro en la posición de Alicia
    return caidas;
}

int main() {
    int N;
    cin >> N; // Leemos el número de saltos del cachorro desde la entrada estándar

    vector<int> saltosCachorro(N); // Creamos un vector para almacenar los saltos del cachorro

    // Leemos los saltos del cachorro y los almacenamos en el vector
    for (int i = 0; i < N; ++i) {
        cin >> saltosCachorro[i];
    }

    int A;
    cin >> A; // Leemos la posición de Alicia desde la entrada estándar

    // Llamamos a la función para contar las caídas del cachorro en la posición de Alicia
    int caidas = contarCaidasCachorro(saltosCachorro, A);

    // Mostramos el resultado en la salida estándar
    cout << caidas << endl;

    return 0; // Indicamos que el programa se ha ejecutado correctamente
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Lectura de la entrada
    int N, M;
    cin >> N; // Leer el tamaño del arreglo
    vector<int> arreglo(N);
    for (int i = 0; i < N; ++i) {
        cin >> arreglo[i]; // Leer los elementos del arreglo
    }
    cin >> M; // Leer la cantidad de eventos a procesar
    
    bool reestablecer = false; // Variable para indicar si se debe reestablecer el arreglo
    int incrementos = 0; // Contador de incrementos

    // Procesamiento de los eventos
    for (int i = 0; i < M; ++i) {
        int tipo_evento;
        cin >> tipo_evento; // Leer el tipo de evento
        if (tipo_evento == 0) {
            reestablecer = true; // Marcar que se debe reestablecer el arreglo
            incrementos = 0; // Reiniciar el contador de incrementos
        } else {
            incrementos++; // Incrementar el contador de incrementos
        }
    }

    if (reestablecer) { // Si se debe reestablecer el arreglo
        // Salida del estado final
        for (int i = 0; i < N; ++i) {
            cout << incrementos << " "; // Imprimir el valor de incrementos para cada elemento
        } 
        cout << endl;
    } else {
        // Aplicar eventos de tipo 1 al arreglo
        for (int i = 0; i < N; ++i) {
            arreglo[i] += incrementos; // Incrementar cada elemento del arreglo
        }

        // Salida del estado final del arreglo
        for (int i = 0; i < N; ++i) {
            cout << arreglo[i] << " "; // Imprimir el estado final del arreglo
        }
        cout << endl;
    }
    return 0;
}


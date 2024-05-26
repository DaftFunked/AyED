#include <iostream>
#include <vector>

using namespace std;

// Función para buscar la puerta correspondiente para una llave
int buscarPuerta(const vector<int>& chapas, int llave) {
    int izquierda = 0;
    int derecha = chapas.size() - 1;
    
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        
        if (chapas[medio] == llave) {
            return medio + 1; // Devolver el número de la puerta (empezando desde 1)
        } else if (chapas[medio] < llave) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    
    return 0; // Si no se encuentra ninguna puerta para la llave
}

int main() {
    int M;
    cin >> M; // Leer la cantidad de tamaños de chapas
    
    vector<int> chapas(M);
    for (int i = 0; i < M; ++i) {
        cin >> chapas[i]; // Leer los tamaños de las chapas
    }
    
    int N;
    cin >> N; // Leer la cantidad de tamaños de llaves
    
    for (int i = 0; i < N; ++i) {
        int llave;
        cin >> llave; // Leer el tamaño de la llave
        
        // Buscar la puerta correspondiente para la llave
        int puerta = buscarPuerta(chapas, llave);
        cout << puerta << endl; // Imprimir el número de la puerta
    }
    
    return 0;
}
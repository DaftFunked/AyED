#include <iostream>
#include <set>
using namespace std;

// Función para sumar 3 a todos los elementos pares del arreglo
void cambiaPares(set<int>& arreglo) {
    set<int> nuevosValores;
    for (int num : arreglo) {
        if (num % 2 == 0) {
            nuevosValores.insert(num + 3); // Si es par, se suma 3 al valor y se agrega al nuevo set
        } else {
            nuevosValores.insert(num); // Si es impar, se agrega al nuevo set sin modificar
        }
    }
    arreglo = nuevosValores; // Actualizamos el set original con los nuevos valores
}

int main() {
    int n, m;
    cin >> n; // Tamaño del arreglo
    set<int> arreglo; // Utilizamos un set en lugar de un vector para garantizar elementos únicos y ordenados
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        arreglo.insert(num); // Insertamos los elementos en el set
    }

    cin >> m; // Número de comandos a procesar

    bool cambiaParesLlamado = false; // Flag para indicar si se ha llamado a cambiaPares()

    for (int i = 0; i < m; ++i) {
        string comando;
        cin >> comando;
        if (comando == "EXISTE") {
            int k;
            cin >> k; // Leer el entero a buscar
            // Verificar si k existe en el set e imprimir el resultado (1 si existe, 0 si no)
            cout << (arreglo.count(k)) << endl;
        } else if (comando == "CAMBIA_PARES" && !cambiaParesLlamado) {
            cambiaPares(arreglo); // Sumar 3 a todos los elementos pares del arreglo
            cambiaParesLlamado = true; // Actualizamos el flag para indicar que se ha llamado a cambiaPares()
        }
    }

    return 0;
}

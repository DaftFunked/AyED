#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int n, m;
    cin >> n; // Leemos el número de cactus

    vector<int> cactus(n); // Creamos un vector para almacenar las posiciones de los cactus

    // Leer las posiciones de los cactus y almacenarlas en un vector
    for (int i = 0; i < n; ++i) {
        cin >> cactus[i];
    }

    // Ordenar las posiciones de los cactus de menor a mayor
    sort(cactus.begin(), cactus.end());

    cin >> m; // Leemos el número de posiciones consideradas por John Carter

    vector<int> posiciones(m); // Creamos un vector para almacenar las posiciones consideradas por John Carter

    // Leer las posiciones consideradas por John Carter y almacenarlas en un vector
    for (int i = 0; i < m; ++i) {
        cin >> posiciones[i];
    }

    // Iteramos sobre las posiciones consideradas por John Carter
    for (int j = 0; j < m; ++j) {
        int posicion = posiciones[j];

        // Si la posición considerada está fuera del rango de cactus, pasamos a la siguiente posición
        if (posicion < cactus[0] || posicion > cactus[n - 1]) continue;

        // Iteramos sobre los cactus para encontrar la distancia entre dos cactus que John Carter pasará
        for (int k = 0; k < n; ++k) {
            if (posicion <= cactus[k]) {
                // Si la posición coincide exactamente con un cactus, la distancia es 0
                if (posicion == cactus[k])
                    cout << "0 ";
                // Si no coincide exactamente, calculamos la distancia entre el cactus actual y el anterior
                else
                    cout << cactus[k] - cactus[k - 1] << " ";
                break;
            }
        }
    }

    return 0;
}
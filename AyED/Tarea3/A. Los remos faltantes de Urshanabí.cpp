#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Definimos una estructura llamada Tree para representar cada árbol.
struct Tree {
    int x, y;          // Coordenadas del árbol
    double distance;   // Distancia del árbol al origen

    // Constructor de la estructura Tree que inicializa las coordenadas (x, y) y calcula la distancia al origen.
    Tree(int _x, int _y) : x(_x), y(_y) {
        distance = sqrt(x * x + y * y); // Calcula la distancia utilizando el teorema de Pitágoras.
    }
};

// Función de comparación para ordenar los árboles según su distancia.
bool compareTrees(const Tree &a, const Tree &b) {
    return a.distance < b.distance; // Compara las distancias entre dos árboles.
}

int main() {
    int N, R;
    cin >> N >> R; // Leemos el número de árboles (N) y el número de remos que necesitamos (R).

    vector<Tree> trees; // Creamos un vector para almacenar los árboles.

    // Leemos las coordenadas de cada árbol y los agregamos al vector.
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        trees.emplace_back(x, y); // Agregamos un árbol al final del vector.
    }

    // Ordenamos los árboles según su distancia al origen utilizando la función de comparación.
    sort(trees.begin(), trees.end(), compareTrees);

    double totalDistance = 0;

    // Sumamos las distancias de los primeros R árboles al origen para obtener la distancia total que debe caminar Gilgamesh.
    for (int i = 0; i < R; ++i) {
        totalDistance += trees[i].distance;
    }

    // Multiplicamos por 2 para representar el viaje de ida y vuelta por cada árbol.
    // Redondeamos el resultado al entero más cercano.
    int roundedDistance = static_cast<int>(round(totalDistance * 2));
    cout << roundedDistance << endl; // Imprimimos la distancia total redondeada.

    return 0;
}
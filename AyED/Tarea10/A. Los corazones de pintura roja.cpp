#include <iostream>
#include <vector>

using namespace std;

// Función para contar triángulos en el grafo
int contarTriangulos(const vector<vector<int>>& grafo) {
    int n = grafo.size(); // Obtiene el número de nodos en el grafo
    int contador = 0; // Inicializa el contador de triángulos en 0

    // Bucle para recorrer todos los nodos
    for (int i = 0; i < n; ++i) {
        // Bucle anidado para recorrer los nodos restantes
        for (int j = i + 1; j < n; ++j) {
            // Bucle anidado para recorrer los nodos restantes
            for (int k = j + 1; k < n; ++k) {
                // Verifica si hay una arista entre los nodos i, j y k, si la hay, incrementa el contador
                if (grafo[i][j] && grafo[j][k] && grafo[k][i]) {
                    ++contador;
                }
            }
        }
    }

    // Devuelve el número total de triángulos encontrados
    return contador;
}

int main() {
    int N;
    cin >> N; // Lee el número de nodos en el grafo

    // Declara una matriz para almacenar el grafo
    vector<vector<int>> grafo(N, vector<int>(N));

    // Lee la matriz de adyacencia que representa el grafo
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grafo[i][j];
        }
    }

    // Llama a la función contarTriangulos para contar los triángulos en el grafo y almacena el resultado
    int triangulos = contarTriangulos(grafo);

    // Imprime el número total de triángulos encontrados
    cout << triangulos << endl;

    return 0;
}

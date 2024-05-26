#include <iostream>  
#include <vector>    
#include <algorithm> 
#include <climits>   

using namespace std;

int main() {
    int N, M;
    cin >> N >> M; 

    // Inicializamos la matriz de distancias con un tamaño N x N y valores iniciales INT_MAX
    vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
    
    // Establecemos la distancia de una cueva a sí misma como 0
    for (int i = 0; i < N; ++i) {
        dist[i][i] = 0;
    }

    // Leemos los senderos
    for (int i = 0; i < M; ++i) {
        int u, v, l;
        cin >> u >> v >> l; // Leemos los extremos del sendero (u y v) y su longitud (l)
        dist[u][v] = l;     // Establecemos la distancia entre las cuevas u y v
        dist[v][u] = l;     // Establecemos la distancia entre las cuevas v y u (es un grafo no dirigido)
    }

    // Aplicamos el algoritmo de Floyd-Warshall
    // Este algoritmo encuentra las distancias mínimas entre todas las parejas de nodos
    for (int k = 0; k < N; ++k) {         // Iteramos sobre todos los nodos como nodos intermedios
        for (int i = 0; i < N; ++i) {     // Iteramos sobre todos los nodos de origen
            for (int j = 0; j < N; ++j) { // Iteramos sobre todos los nodos de destino
                // Si la distancia a través del nodo k es menor que la distancia directa, la actualizamos
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Encontramos la cueva óptima
    int mejorCueva = -1;    // Variable para almacenar la mejor cueva
    int mejorSuma = INT_MAX; // Variable para almacenar la mejor suma de distancias
    for (int i = 0; i < N; ++i) {
        int suma = 0; // Variable para almacenar la suma de distancias desde la cueva i a todas las demás
        for (int j = 0; j < N; ++j) {
            suma += dist[i][j]; // Sumamos las distancias desde la cueva i a la cueva j
        }
        // Si la suma de distancias es menor que la mejor suma encontrada hasta ahora, actualizamos
        if (suma < mejorSuma) {
            mejorSuma = suma;
            mejorCueva = i;
        }
    }

    // Imprimimos el resultado
    cout << mejorCueva << " " << mejorSuma << endl; 

    return 0; 
}
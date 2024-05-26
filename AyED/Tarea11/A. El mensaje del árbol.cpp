#include <iostream>  
#include <vector>    
#include <queue>     
#include <tuple>     
#include <string>    
#include <functional>

using namespace std;

// Estructura para almacenar la información de una arista
struct Arista {
    int u, v, costo;
    string mensaje;
};

// Comparador para la cola de prioridad para desempatar por el orden de entrada
struct Comparador {
    // Definimos el operador de comparación
    bool operator()(const tuple<int, int, int, string, int>& a, const tuple<int, int, int, string, int>& b) {
        int costoA, costoB, indexA, indexB;
        // Extraemos los valores de las tuplas
        tie(ignore, ignore, costoA, ignore, indexA) = a;
        tie(ignore, ignore, costoB, ignore, indexB) = b;
        if (costoA != costoB)
            return costoA > costoB; // Primero comparamos por costo
        return indexA > indexB;     // Si los costos son iguales, comparamos por el índice de entrada
    }
};

int main() {
    int n, m;
    cin >> n >> m; // Leemos el número de vértices (n) y aristas (m)

    // Lista de adyacencia para la gráfica
    vector<vector<tuple<int, int, string, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, k;
        string s;
        // Leemos los extremos de la arista (u, v), el costo (k) y el mensaje (s)
        cin >> u >> v >> k >> s;
        adj[u].emplace_back(v, k, s, i); // Añadimos la arista a la lista de adyacencia del vértice u
        adj[v].emplace_back(u, k, s, i); // Añadimos la arista a la lista de adyacencia del vértice v (grafo no dirigido)
    }

    // Cola de prioridad para seleccionar la arista de menor costo
    priority_queue<tuple<int, int, int, string, int>, vector<tuple<int, int, int, string, int>>, Comparador> pq;
    
    vector<bool> enMST(n, false); // Para marcar los vértices que ya están en el MST
    vector<string> mensajeFinal;  // Para almacenar el mensaje final en el orden correcto

    // Empezamos desde el vértice 0 (puede ser cualquier vértice)
    enMST[0] = true;
    for (const auto& arista : adj[0]) {
        int v, costo, index;
        string mensaje;
        // Extraemos los valores de cada arista adyacente al vértice 0
        tie(v, costo, mensaje, index) = arista;
        // Añadimos la arista a la cola de prioridad
        pq.emplace(0, v, costo, mensaje, index);
    }

    // Mientras haya aristas que procesar
    while (!pq.empty()) {
        // Extraemos la arista de menor costo
        auto [u, v, costo, mensaje, index] = pq.top();
        pq.pop();

        if (enMST[v])
            continue; // Si el vértice ya está en el MST, ignoramos esta arista

        // Agregamos la arista al MST
        enMST[v] = true;
        mensajeFinal.push_back(mensaje); // Añadimos el mensaje de la arista al mensaje final

        // Añadimos las nuevas aristas del vértice recién agregado
        for (const auto& arista : adj[v]) {
            int next, nextCosto, nextIndex;
            string nextMensaje;
            tie(next, nextCosto, nextMensaje, nextIndex) = arista;
            if (!enMST[next]) {
                // Añadimos las aristas adyacentes al nuevo vértice al MST
                pq.emplace(v, next, nextCosto, nextMensaje, nextIndex);
            }
        }
    }

    // Imprimimos el mensaje final
    for (const string& msg : mensajeFinal) {
        cout << msg << endl;
    }

    return 0; 
}
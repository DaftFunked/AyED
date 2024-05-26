#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Función DFS para explorar el grafo y encontrar componentes conexas
void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true; // Marca el nodo como visitado
    // Recorre todos los nodos adyacentes al nodo actual
    for (int neighbor : graph[node]) {
        // Si el vecino no ha sido visitado, realiza DFS en él
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

// Función para contar la cantidad de componentes conexas en el grafo
int countConnectedComponents(const vector<vector<int>>& graph) {
    int n = graph.size(); // Obtiene el número de nodos en el grafo
    vector<bool> visited(n, false); // Inicializa un vector para marcar los nodos visitados
    int count = 0; // Inicializa el contador de componentes conexas en 0

    // Realiza DFS en todos los nodos no visitados
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(graph, visited, i);
            ++count; // Incrementa el contador después de realizar DFS en un nodo no visitado
        }
    }

    return count; // Devuelve el número total de componentes conexas
}

int main() {
    int N, M;
    cin >> N >> M; // Lee el número de nodos y el número de aristas

    // Declara un vector de vectores para representar el grafo
    vector<vector<int>> graph(N);

    // Lee las aristas y construye el grafo
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v; // Lee los nodos extremos de la arista
        // Agrega la arista a la lista de adyacencia de ambos nodos
        graph[u].push_back(v);
        graph[v].push_back(u); // Esto es específico para un grafo no dirigido
    }

    // Llama a la función countConnectedComponents para contar las componentes conexas en el grafo y almacena el resultado
    int componentesConexas = countConnectedComponents(graph);

    // Imprime el número total de componentes conexas
    cout << componentesConexas << endl;

    return 0;
}

#include <iostream> 
#include <vector> 
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Definición de la clase Grafo
class Grafo {
private:
    unordered_map<int, vector<int>> adj; // Lista de adyacencia para representar el grafo

public:
    // Método para agregar una arista al grafo
    void agregarArista(int origen, int destino) {
        adj[origen].push_back(destino); // Agrega el destino a la lista de adyacencia del origen
    }

    // Método de búsqueda en profundidad (DFS)
    void DFS(int v, unordered_set<int>& visitados, vector<int>& orden) {
        visitados.insert(v); // Marca el nodo como visitado
        orden.push_back(v); // Agrega el nodo al orden de visita

        // Recorre todos los nodos adyacentes al nodo actual
        for (int u : adj[v]) {
            if (visitados.find(u) == visitados.end()) { // Si el nodo no ha sido visitado
                DFS(u, visitados, orden); // Realiza DFS desde el nodo adyacente
            }
        }
    }

    // Método para encontrar el orden de visita de los globos
    vector<int> ordenDeVisita(int inicio) {
        unordered_set<int> visitados; // Conjunto para mantener un registro de los nodos visitados
        vector<int> orden; // Vector para almacenar el orden de visita

        DFS(inicio, visitados, orden); // Llama a DFS desde el nodo de inicio

        return orden; // Devuelve el orden de visita de los globos
    }
};

int main() {
    int N;
    cin >> N; // Lee el número de globos

    Grafo grafo; // Crea un objeto de la clase Grafo

    // Lee las N - 1 parejas de enteros que representan las flechas
    for (int i = 0; i < N - 1; ++i) {
        int X, Y;
        cin >> X >> Y;
        grafo.agregarArista(X, Y); // Agrega la flecha al grafo
    }

    vector<int> orden = grafo.ordenDeVisita(0); // Encuentra el orden de visita comenzando desde el globo 0

    // Imprime el orden de visita de los globos
    for (int globo : orden) {
        cout << globo << " ";
    }
    cout << endl;

    return 0;
}
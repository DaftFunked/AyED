#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj; // Lista de adyacencia para representar el árbol

// Función para realizar BFS y devolver el nodo más lejano y su distancia desde el nodo inicial
pair<int, int> bfs(int inicio, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(inicio);
    dist[inicio] = 0;
    
    int nodo_mas_lejano = inicio;
    int max_dist = 0;
    
    while (!q.empty()) {
        int nodo = q.front();
        q.pop();
        
        for (int vecino : adj[nodo]) {
            if (dist[vecino] == -1) { // Si el vecino no ha sido visitado
                dist[vecino] = dist[nodo] + 1;
                q.push(vecino);
                if (dist[vecino] > max_dist) {
                    max_dist = dist[vecino];
                    nodo_mas_lejano = vecino;
                }
            }
        }
    }
    
    return {nodo_mas_lejano, max_dist};
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n + 1);
    
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // Primer BFS desde un nodo arbitrario (nodo 1)
    pair<int, int> p1 = bfs(1, n);
    // Segundo BFS desde el nodo más lejano encontrado en el primer BFS
    pair<int, int> p2 = bfs(p1.first, n);
    
    // El diámetro del árbol es la distancia máxima encontrada en el segundo BFS
    cout << p2.second << endl;
    
    return 0;
}

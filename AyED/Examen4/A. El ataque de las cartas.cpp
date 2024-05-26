#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }

    // Creamos un comparador personalizado para la cola de prioridad
    auto comp = [](int a, int b) { return a < b; };
    priority_queue<int, vector<int>, decltype(comp)> pq(comp); // Cola de prioridad con comparador personalizado

    // Llenamos la cola de prioridad con las energías iniciales de las cartas
    for (int i = 0; i < N; ++i) {
        pq.push(C[i]);
    }

    vector<int> resultado;

    // Ejecutamos los manazos
    for (int i = 0; i < M; ++i) {
        int maxE = pq.top(); // Obtenemos la energía de la carta con mayor energía
        pq.pop(); // Removemos la carta de la cola
        resultado.push_back(maxE); // Agregamos la energía al resultado

        int nvE = maxE / 2; // Calculamos la nueva energía después del manazo
        if (nvE > 0) { // Si la nueva energía es mayor que cero, la agregamos de nuevo a la cola
            pq.push(nvE);
        }
    }

    // Imprimimos el resultado
    for (int i = 0; i < M; ++i) {
        cout << resultado[i];
        if (i < M - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}

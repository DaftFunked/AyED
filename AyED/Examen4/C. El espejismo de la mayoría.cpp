#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Estructura para almacenar información de un nodo
struct Nodo {
    char opinion;
    vector<int> contactos;
};

int main() {
    int N;
    cin >> N;

    vector<Nodo> nodos(N);

    // Leer datos de entrada para cada nodo
    for (int i = 0; i < N; ++i) {
        char opinion;
        int P;
        cin >> opinion >> P;
        nodos[i].opinion = opinion;
        nodos[i].contactos.resize(P);
        for (int j = 0; j < P; ++j) {
            cin >> nodos[i].contactos[j];
        }
    }

    int contadorA = 0, contadorB = 0;

    // Determinar la opinión percibida por cada nodo
    for (int i = 0; i < N; ++i) {
        unordered_map<char, int> conteoOpiniones;
        for (int contacto : nodos[i].contactos) {
            conteoOpiniones[nodos[contacto].opinion]++;
        }

        // Determinar la opinión mayoritaria entre los contactos
        char opinionPercibida = nodos[i].opinion;
        if (conteoOpiniones['A'] > conteoOpiniones['B']) {
            opinionPercibida = 'A';
        } else if (conteoOpiniones['B'] > conteoOpiniones['A']) {
            opinionPercibida = 'B';
        }

        // Contar la opinión percibida
        if (opinionPercibida == 'A') {
            contadorA++;
        } else {
            contadorB++;
        }
    }

    // Determinar y mostrar la opinión mayoritaria percibida
    if (contadorA > contadorB) {
        cout << 'A' << " " << contadorA << endl;
    } else {
        cout << 'B' << " " << contadorB << endl;
    }

    return 0;
}

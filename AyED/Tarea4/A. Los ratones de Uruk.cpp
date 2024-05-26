#include <iostream>
#include <vector>
#include <algorithm> // Se incluye la biblioteca <algorithm> para usar la función sort()

using namespace std;

// Estructura para representar un ratón o un agujero
struct Entity {
    string name;    // Nombre del ratón o agujero
    int position;   // Posición del ratón o agujero en el plano
};

// Función de comparación para ordenar las entidades por su posición
bool compareByPosition(const Entity& a, const Entity& b) {
    return a.position < b.position; // Retorna verdadero si la posición de a es menor que la posición de b
}

int main() {
    int numRats, numHoles;
    cin >> numRats; // Se lee el número de ratones

    // Se crea un vector de ratones con tamaño numRats
    vector<Entity> rats(numRats);
    // Se lee el nombre y la posición de cada ratón y se almacenan en el vector de ratones
    for (int i = 0; i < numRats; ++i) {
        cin >> rats[i].name >> rats[i].position;
    }

    cin >> numHoles; // Se lee el número de agujeros

    // Se crea un vector de agujeros con tamaño numHoles
    vector<Entity> holes(numHoles);
    // Se lee el nombre y la posición de cada agujero y se almacenan en el vector de agujeros
    for (int i = 0; i < numHoles; ++i) {
        cin >> holes[i].name >> holes[i].position;
    }

    // Se ordenan los ratones y los agujeros según su posición en el plano
    sort(rats.begin(), rats.end(), compareByPosition);
    sort(holes.begin(), holes.end(), compareByPosition);

    // Asignar ratones a agujeros en el orden de izquierda a derecha e imprimir la asignación
    for (int i = 0; i < numRats; ++i) {
        cout << rats[i].name << " " << holes[i].name << endl;
    }

    return 0;
}

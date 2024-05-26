#include <iostream> 
#include <vector> 
#include <string> 

using namespace std;

// Definición de la estructura de un nodo de la lista doblemente enlazada
struct Node {
    string name; // Nombre del animal
    Node* prev; // Puntero al nodo anterior
    Node* next; // Puntero al nodo siguiente
    Node(string _name) : name(_name), prev(nullptr), next(nullptr) {} // Constructor para inicializar el nodo con un nombre dado
};

// Función para eliminar el nodo del principio de la lista
void removeFront(vector<Node>& animals) {
    if (!animals.empty()) { // Verificar si la lista no está vacía
        cout << animals.front().name << endl; // Imprimir el nombre del animal que se va
        animals.erase(animals.begin()); // Eliminar el primer nodo de la lista
    }
}

// Función para eliminar el nodo del final de la lista
void removeBack(vector<Node>& animals) {
    if (!animals.empty()) { // Verificar si la lista no está vacía
        cout << animals.back().name << endl; // Imprimir el nombre del animal que se va
        animals.pop_back(); // Eliminar el último nodo de la lista
    }
}

int main() {
    int N;
    cin >> N; 

    vector<Node> animals; 

    for (int i = 0; i < N; ++i) { // Iterar sobre cada evento
        char T, L; 
        string name; 

        cin >> T >> L; 
        if (T == 'E') { // Si es un evento de llegada
            cin >> name; // Leer el nombre del animal
            if (L == 'I') { // Si llega por la izquierda
                animals.insert(animals.begin(), Node(name)); // Insertar al principio de la lista
            } else { // Si llega por la derecha
                animals.push_back(Node(name)); // Insertar al final de la lista
            }
        } else { // Si es un evento de salida
            if (L == 'I') { // Si sale por la izquierda
                removeFront(animals); // Eliminar el primer nodo de la lista
            } else { // Si sale por la derecha
                removeBack(animals); // Eliminar el último nodo de la lista
            }
        }
    }

    return 0; 
}

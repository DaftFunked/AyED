#include <iostream>
#include <vector>

using namespace std;

// Implementación de una cola utilizando una estructura de nodo
struct Nodo {
    int valor;          // Valor del nodo (en este caso, el número del invitado)
    Nodo* siguiente;    // Puntero al siguiente nodo en la cola
};

class Cola {
private:
    Nodo* frente; // Puntero al frente de la cola
    Nodo* final;  // Puntero al final de la cola

public:
    // Constructor
    Cola() {
        frente = nullptr;  // Inicializar el frente de la cola como nullptr (cola vacía)
        final = nullptr;   // Inicializar el final de la cola como nullptr (cola vacía)
    }

    // Método para verificar si la cola está vacía
    bool vacia() {
        return frente == nullptr;  // La cola está vacía si el frente es nullptr
    }

    // Método para insertar un elemento en la cola
    void insertar(int invitado) {
        Nodo* nuevoNodo = new Nodo;  // Crear un nuevo nodo
        nuevoNodo->valor = invitado; // Asignar el valor del invitado al nuevo nodo
        nuevoNodo->siguiente = nullptr; // El siguiente del nuevo nodo es nullptr

        // Si la cola está vacía, el nuevo nodo será tanto el frente como el final de la cola
        if (vacia()) {
            frente = nuevoNodo;
            final = nuevoNodo;
        } else {
            // Si la cola no está vacía, agregar el nuevo nodo al final de la cola
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
    }

    // Método para obtener el elemento del frente de la cola
    int frenteCola() {
        // Verificar si la cola está vacía
        if (vacia()) {
            return -1; // La cola está vacía, no hay elemento en el frente
        }
        // Devolver el valor del frente de la cola
        return frente->valor;
    }

    // Método para eliminar el elemento del frente de la cola
    void eliminar() {
        // Verificar si la cola está vacía
        if (vacia()) {
            return; // No se puede eliminar, la cola está vacía
        }
        // Si solo hay un elemento en la cola, actualizar tanto el frente como el final
        if (frente == final) {
            delete frente; // Liberar la memoria del nodo
            frente = nullptr;
            final = nullptr;
        } else {
            // Si hay más de un elemento en la cola, eliminar el frente y actualizar el frente
            Nodo* temp = frente;
            frente = frente->siguiente;
            delete temp; // Liberar la memoria del nodo
        }
    }
};

// Función principal
int main() {
    int N;
    cin >> N; // Leer el número de eventos

    // Declaración de objeto de Cola
    Cola cola;

    // Vector para almacenar los mensajes de salida
    vector<string> salida;

    // Vector para mantener un registro de los invitados atendidos
    vector<bool> atendidos(1000, false); // Vector de tamaño 1000 inicializado con valores falsos

    // Procesar cada evento
    for (int i = 0; i < N; ++i) {
        string evento;
        cin >> evento; // Leer el tipo de evento

        if (evento == "FORMA") {
            int invitado;
            cin >> invitado; // Leer el número del invitado
            cola.insertar(invitado); // Insertar al invitado en la cola

        } else if (evento == "ATIENDE") {
            if (!cola.vacia()) {
                int invitado = cola.frenteCola(); // Obtener el invitado del frente de la cola
                cola.eliminar(); // Eliminar al invitado del frente de la cola
                if (atendidos[invitado]) {
                    salida.push_back("NO TAMAL " + to_string(invitado)); // Agregar mensaje de "NO TAMAL" al vector de salida
                } else {
                    salida.push_back("SI TAMAL " + to_string(invitado)); // Agregar mensaje de "SI TAMAL" al vector de salida
                    atendidos[invitado] = true; // Marcar al invitado como atendido
                }
            } else {
                salida.push_back("NO TAMAL"); // Agregar mensaje de "NO TAMAL" si la cola está vacía
            }
        }
    }

    // Imprimir los mensajes de salida
    for (const auto& mensaje : salida) {
        cout << mensaje << endl;
    }

    return 0;
}
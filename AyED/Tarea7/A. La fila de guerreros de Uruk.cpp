#include <iostream>
#include <unordered_map>

using namespace std;

// Definición de la estructura de un nodo de la lista enlazada
struct Node {
    int id;
    Node* next;
    Node(int _id) : id(_id), next(nullptr) {} // Constructor para inicializar el nodo con un id dado
};

// Función para insertar un nodo después de otro nodo dado
void insertAfter(Node* prev, int new_id) {
    if (prev == nullptr) { // Verifica si el nodo previo es nulo
        return;
    }
    Node* new_node = new Node(new_id); // Crea un nuevo nodo con el nuevo id
    new_node->next = prev->next; // Establece el siguiente del nuevo nodo como el siguiente del nodo previo
    prev->next = new_node; // Establece el siguiente del nodo previo como el nuevo nodo
}

// Función para imprimir la lista enlazada
void printList(Node* head) {
    while (head != nullptr) { // Recorre la lista hasta llegar al final
        cout << head->id << " "; // Imprime el id del nodo actual
        head = head->next; // Avanza al siguiente nodo
    }
    cout << endl;
}

// Función para resolver el problema
void reorder(int G, int* original_ids, int R, pair<int, int>* reserve_pairs) {
    // Crear un mapa para mantener el puntero al nodo correspondiente a cada id
    unordered_map<int, Node*> id_to_node;

    // Crear la lista enlazada inicial con los soldados originales
    Node* head = new Node(original_ids[0]); // Crea el primer nodo con el primer id
    id_to_node[original_ids[0]] = head; // Agrega el nodo al mapa con su id correspondiente
    Node* current = head; // Inicializa un puntero para recorrer la lista
    for (int i = 1; i < G; ++i) { // Itera sobre los demás ids
        current->next = new Node(original_ids[i]); // Crea un nuevo nodo con el id actual y lo enlaza al nodo actual
        current = current->next; // Avanza al siguiente nodo
        id_to_node[original_ids[i]] = current; // Agrega el nuevo nodo al mapa con su id correspondiente
    }

    // Insertar los soldados de reserva en la fila original
    for (int i = 0; i < R; ++i) { // Itera sobre las parejas de soldados de reserva
        insertAfter(id_to_node[reserve_pairs[i].second], reserve_pairs[i].first); // Inserta el soldado de reserva después del soldado indicado
        id_to_node[reserve_pairs[i].first] = id_to_node[reserve_pairs[i].second]->next; // Actualiza el puntero al nodo correspondiente al nuevo soldado
    }

    // Imprimir la fila final
    printList(head);

    // Liberar memoria
    current = head;
    while (current != nullptr) { // Itera sobre todos los nodos de la lista
        Node* temp = current; // Guarda el puntero al nodo actual
        current = current->next; // Avanza al siguiente nodo
        delete temp; // Libera la memoria del nodo actual
    }
}

int main() {
    int G, R;
    cin >> G; // Lee el número de soldados originales
    int* original_ids = new int[G]; // Crea un arreglo para almacenar los ids de los soldados originales
    for (int i = 0; i < G; ++i) { // Lee los ids de los soldados originales
        cin >> original_ids[i];
    }
    cin >> R; // Lee el número de soldados de reserva
    pair<int, int>* reserve_pairs = new pair<int, int>[R]; // Crea un arreglo para almacenar las parejas de soldados de reserva
    for (int i = 0; i < R; ++i) { // Lee las parejas de soldados de reserva
        cin >> reserve_pairs[i].first >> reserve_pairs[i].second;
    }

    reorder(G, original_ids, R, reserve_pairs); // Llama a la función para resolver el problema

    // Liberar memoria
    delete[] original_ids;
    delete[] reserve_pairs;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

// Definición de la estructura de un nodo del árbol binario de búsqueda
struct Node {
    char data; // Valor del nodo (letra)
    Node* left; // Puntero al hijo izquierdo
    Node* right; // Puntero al hijo derecho
    Node(char _data) : data(_data), left(nullptr), right(nullptr) {} // Constructor para inicializar el nodo con un valor dado
};

// Función para insertar un valor en el árbol binario de búsqueda
void insert(Node*& root, char value) {
    if (root == nullptr) { // Si el árbol está vacío, crea un nuevo nodo
        root = new Node(value);
    } else if (value < root->data) { // Si el valor es menor que el valor del nodo actual, inserta en el subárbol izquierdo
        insert(root->left, value);
    } else { // Si el valor es mayor o igual que el valor del nodo actual, inserta en el subárbol derecho
        insert(root->right, value);
    }
}


string search(Node* root, char current_node, char target_node) {
    string path = "";

    // Llegar hasta el nodo de bifurcación
    while (true) {
        if (current_node > root->data && target_node > root->data) {
            root = root->right;
        } else if (current_node < root->data && target_node < root->data) {
            root = root->left;
        } else {
            break;
        }
    }
    
    Node* aux = root;
    // Bajadas necesarias desde el nodo actual al de bifurcación
    while (current_node != root->data) {
        root = current_node < root->data ? root->left : root->right;
        path += "B";
    }
    
    // Subidas desde el nodo de bifurcación al nodo de destino
    while (target_node != aux->data) {
        if (target_node > aux->data) {
            aux = aux->right;
            path += "D";
        } else {
            aux = aux->left;
            path += "I";
        }
    }
    
    return path;
}


int main() {
    string A, G;
    cin >> A >> G; // Leer las cadenas A y G

    Node* root = nullptr; // Inicializar el puntero a la raíz del árbol como nulo

    // Construir el árbol binario de búsqueda a partir de la cadena A
    for (char c : A) {
        insert(root, c);
    }

    // Recorrer la cadena G pronunciada por el gato y obtener los movimientos
    char current_node_c = root->data;
    for (char next_node_c : G) {
        cout << search(root, current_node_c, next_node_c); // Obtener los movimientos de búsqueda de la letra en el árbol
        current_node_c = next_node_c;
    }

    return 0;
}
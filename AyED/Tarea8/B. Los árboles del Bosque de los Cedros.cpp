#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definición de la estructura del nodo del árbol
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Función para insertar un nodo en el árbol
void insertNode(Node*& root, char data) {
    if (root == nullptr) {
        root = new Node;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    } else if (data < root->data) {
        insertNode(root->left, data);
    } else {
        insertNode(root->right, data);
    }
}

// Función para buscar un nodo en el árbol
Node* search(Node* root, char data) {
    if (root == nullptr || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Función para encontrar el camino desde la raíz hasta un nodo dado
void findPath(Node* root, char data, vector<char>& path) {
    if (root == nullptr) {
        return;
    }
    path.push_back(root->data);
    if (root->data == data) {
        return;
    }
    if (data < root->data) {
        findPath(root->left, data, path);
    } else {
        findPath(root->right, data, path);
    }
}

// Función para obtener la secuencia de movimientos del gato en el árbol
string getMovementsSequence(Node* root, const string& spokenLetters) {
    string movements;
    Node* currentNode = root;
    for (char letter : spokenLetters) {
        vector<char> path;
        findPath(root, letter, path);
        for (char nodeLetter : path) {
            if (nodeLetter < currentNode->data) {
                movements += 'I'; // Subir a la izquierda
                currentNode = currentNode->left;
            } else if (nodeLetter > currentNode->data) {
                movements += 'D'; // Subir a la derecha
                currentNode = currentNode->right;
            } else {
                movements += 'B'; // Bajar
            }
        }
    }
    return movements;
}

int main() {
    string alphabet, spokenLetters;
    cin >> alphabet >> spokenLetters;

    // Construir el árbol
    Node* root = nullptr;
    for (char letter : alphabet) {
        insertNode(root, letter);
    }

    // Obtener la secuencia de movimientos del gato
    string movements = getMovementsSequence(root, spokenLetters);
    cout << movements << endl;

    return 0;
}
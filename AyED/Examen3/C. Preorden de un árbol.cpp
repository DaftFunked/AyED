#include <iostream>
#include <vector>

using namespace std;

// Definición de la estructura del nodo del árbol
struct Nodo {
    int valor; // Valor almacenado en el nodo
    Nodo* izquierdo; // Puntero al hijo izquierdo del nodo
    Nodo* derecho; // Puntero al hijo derecho del nodo

    // Constructor para inicializar un nodo con un valor dado
    Nodo(int val) : valor(val), izquierdo(nullptr), derecho(nullptr) {}
};

// Función para insertar un nuevo nodo en el árbol binario de búsqueda
void insertar(Nodo*& raiz, int valor) {
    if (raiz == nullptr) { // Si la raíz es nula, crea un nuevo nodo con el valor dado
        raiz = new Nodo(valor);
    } else if (valor < raiz->valor) { // Si el valor es menor que el valor de la raíz, inserta en el subárbol izquierdo
        insertar(raiz->izquierdo, valor);
    } else { // Si el valor es mayor o igual que el valor de la raíz, inserta en el subárbol derecho
        insertar(raiz->derecho, valor);
    }
}

// Función auxiliar para realizar el recorrido en preorden del árbol
void preordenAux(Nodo* raiz, vector<int>& resultado) {
    if (raiz != nullptr) { // Si la raíz no es nula
        resultado.push_back(raiz->valor); // Agrega el valor de la raíz al resultado
        preordenAux(raiz->izquierdo, resultado); // Realiza el recorrido en preorden del subárbol izquierdo
        preordenAux(raiz->derecho, resultado); // Realiza el recorrido en preorden del subárbol derecho
    }
}

// Función para realizar el recorrido en preorden del árbol y almacenar el resultado en un vector
vector<int> preorden(Nodo* raiz) {
    vector<int> resultado; // Vector para almacenar el resultado del recorrido en preorden
    preordenAux(raiz, resultado); // Llama a la función auxiliar para realizar el recorrido en preorden
    return resultado; // Devuelve el resultado del recorrido en preorden
}

int main() {
    int N;
    cin >> N; // Lee el número de elementos

    Nodo* raiz = nullptr; // Inicializa la raíz del árbol como nulo

    // Leer la secuencia de N enteros y construir el árbol binario de búsqueda
    for (int i = 0; i < N; ++i) {
        int valor;
        cin >> valor;
        insertar(raiz, valor); // Inserta el valor en el árbol binario de búsqueda
    }

    // Realizar el recorrido en preorden del árbol y almacenar el resultado en un vector
    vector<int> recorrido = preorden(raiz);

    int M;
    cin >> M; // Lee el número de consultas

    // Responder a las consultas
    for (int i = 0; i < M; ++i) {
        int indice;
        cin >> indice;
        
        // Imprimir el i-ésimo elemento del recorrido en preorden
        cout << recorrido[indice - 1] << endl;
    }

    return 0; 
}

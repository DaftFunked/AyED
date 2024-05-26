#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

// Declaración de la clase abstracta DataStructure
class DataStructure {
public:
    // Métodos virtuales puros que deben ser implementados por las clases derivadas
    virtual void push(int value) = 0;
    virtual int pop() = 0;
};

// Definición de la clase Stack que hereda de DataStructure
class Stack : public DataStructure {
private:
    stack<int> stk; // Estructura de datos de tipo pila (stack) para almacenar enteros

public:
    // Implementación del método push para agregar un elemento a la pila
    void push(int value) override {
        stk.push(value);
    }

    // Implementación del método pop para eliminar y devolver el elemento superior de la pila
    int pop() override {
        int value = stk.top(); // Obtener el valor del elemento superior
        stk.pop(); // Eliminar el elemento superior
        return value; // Devolver el valor del elemento eliminado
    }
};

// Definición de la clase Queue que hereda de DataStructure
class Queue : public DataStructure {
private:
    queue<int> q; // Estructura de datos de tipo cola (queue) para almacenar enteros

public:
    // Implementación del método push para agregar un elemento a la cola
    void push(int value) override {
        q.push(value);
    }

    // Implementación del método pop para eliminar y devolver el elemento frontal de la cola
    int pop() override {
        int value = q.front(); // Obtener el valor del elemento frontal
        q.pop(); // Eliminar el elemento frontal
        return value; // Devolver el valor del elemento eliminado
    }
};

// Función principal
int main() {
    int N; // Variable para almacenar el número de eventos
    char C; // Variable para almacenar el tipo de estructura de datos (Pila o Cola)
    cin >> N >> C; // Leer el número de eventos y el tipo de estructura de datos desde la entrada estándar

    DataStructure* ds; // Puntero a la clase base DataStructure

    // Crear una instancia de la clase derivada correspondiente según el tipo de estructura de datos especificado
    if (C == 'P') {
        ds = new Stack(); // Crear una pila si C es 'P'
    } else if (C == 'C') {
        ds = new Queue(); // Crear una cola si C es 'C'
    } else {
        cerr << "Tipo de estructura desconocido\n"; // Imprimir un mensaje de error si el tipo de estructura es desconocido
        return 1; // Salir del programa con un código de error
    }

    // Procesar los eventos
    for (int i = 0; i < N; ++i) {
        string event; // Variable para almacenar el tipo de evento (PUSH o POP)
        cin >> event; // Leer el tipo de evento desde la entrada estándar

        // Procesar el evento según su tipo
        if (event == "PUSH") { // Si el evento es PUSH
            int value; // Variable para almacenar el valor a agregar
            cin >> value; // Leer el valor desde la entrada estándar
            ds->push(value); // Agregar el valor a la estructura de datos correspondiente
        } else if (event == "POP") { // Si el evento es POP
            cout << ds->pop() << endl; // Imprimir y eliminar el elemento superior de la estructura de datos, luego pasar a la siguiente línea
        }
    }

    delete ds; // Liberar la memoria asignada dinámicamente para la estructura de datos

    return 0; // Salir del programa con éxito
}

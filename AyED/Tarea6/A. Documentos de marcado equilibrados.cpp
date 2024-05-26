#include <algorithm> // Biblioteca para algoritmos de C++
#include <iostream>  // Biblioteca para entrada y salida estándar
#include <sstream>   // Biblioteca para operaciones de flujo de cadena
#include <stack>     // Biblioteca para la estructura de datos de pila
#include <string>    // Biblioteca para el manejo de cadenas de texto

using namespace std; // Permite el uso de elementos de la biblioteca estándar sin calificarlos

// Función para verificar si una etiqueta es válida
bool esEtiquetaValida(const string& etiqueta) {
    // Verifica si el primer carácter es una letra o un guion bajo
    if (!isalpha(etiqueta[0]) && etiqueta[0] != '_')
        return false;
    // Verifica si todos los caracteres son alfanuméricos o guiones bajos
    for (char c: etiqueta) {
        if (!isalnum(c) && c != '_')
            return false;
    }
    return true; // La etiqueta es válida
}

int main() {
    stack<string> tags; // Pila para almacenar las etiquetas abiertas
    string texto;       // Variable para almacenar la entrada de texto
    getline(cin, texto); // Lee una línea de texto desde la entrada estándar (consola)

    istringstream iss(texto); // Objeto para convertir la cadena de texto en un flujo de entrada
    string tag;               // Variable para almacenar cada etiqueta procesada
    size_t profundidad_max = 0; // Variable para almacenar la profundidad máxima de anidamiento
    int posicion_error = 0;      // Variable para almacenar la posición del posible error

    // Itera sobre cada palabra en la línea de texto
    while (iss >> tag) {
        ++posicion_error; // Incrementa la posición del posible error

        // Si la etiqueta no comienza con '/', es una etiqueta de apertura
        if (tag[0] != '/') {
            // Si la etiqueta no es válida, muestra un mensaje de error
            if (!esEtiquetaValida(tag)) {
                cout << "I " << posicion_error << endl; // Indica un error de etiqueta inválida
                return 0; // Sale del programa con código de error
            }
            tags.push(tag); // Agrega la etiqueta a la pila
            profundidad_max = max(profundidad_max, tags.size()); // Actualiza la profundidad máxima

        } else { // Si la etiqueta comienza con '/', es una etiqueta de cierre
            // Si la pila está vacía o la etiqueta de cierre no coincide con la última etiqueta abierta
            if (tags.empty() || tag.substr(1) != tags.top()) {
                cout << "I " << posicion_error << endl; // Indica un error de etiqueta de cierre incorrecta
                return 0; // Sale del programa con código de error
            }
            tags.pop(); // Elimina la etiqueta abierta de la pila
        }
    }

    // Si la pila está vacía, todas las etiquetas están correctamente cerradas
    if (tags.empty()) {
        cout << "V " << profundidad_max << endl; // Indica que el documento es válido
    } else { // Si la pila no está vacía, hay etiquetas sin cerrar
        cout << "I " << posicion_error + 1 << endl; // Indica la posición del error
    }

    return 0; // Termina el programa con éxito
}
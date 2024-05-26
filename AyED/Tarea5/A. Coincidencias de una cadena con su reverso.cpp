#include <iostream>     // Librería estándar de entrada y salida de C++
#include <string>       // Librería estándar para manipulación de cadenas de C++
#include <algorithm>   // Para la función transform
#include <cctype>      // Para las funciones tolower y toupper

using namespace std;  // Espacio de nombres estándar de C++

// Función para contar coincidencias entre una cadena y su reverso
int countCoincidences(const string& str) {
    string reversed = str;                  // Crear una copia de la cadena original
    reverse(reversed.begin(), reversed.end());  // Invertir la cadena copiada

    int count = 0;                          // Inicializar un contador para las coincidencias
    size_t len = str.length();              // Obtener la longitud de la cadena original

    for (size_t i = 0; i < len; ++i) {     // Iterar a través de cada caracter de la cadena
        // Comparamos los caracteres, teniendo en cuenta la posibilidad de mayúsculas o minúsculas
        if (tolower(str[i]) == tolower(reversed[i])) {
            count++;                        // Incrementar el contador si los caracteres coinciden
        }
    }

    return count;                           // Devolver el número total de coincidencias
}

int main() {
    string R;                               // Declarar una variable para almacenar la cadena
    cin >> R;                               // Leer la cadena desde la entrada estándar

    int S = countCoincidences(R);           // Llamar a la función para contar coincidencias

    cout << S << endl;                      // Imprimir el número de coincidencias

    return 0;                               // Indicar que el programa finalizó con éxito
}


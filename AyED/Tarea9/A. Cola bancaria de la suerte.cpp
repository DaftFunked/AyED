#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar a un cuentahabiente
struct Cuentahabiente {
    string nombre;
    int prioridad;
    int ordenDeLlegada; // Usado para desempatar en caso de igual prioridad
    // Constructor
    Cuentahabiente(string nombre, int prioridad, int ordenDeLlegada) : nombre(nombre), prioridad(prioridad), ordenDeLlegada(ordenDeLlegada) {}
    // Sobrecarga del operador < para comparar cuentahabientes por prioridad y orden de llegada
    bool operator<(const Cuentahabiente& otro) const {
        if (prioridad != otro.prioridad) {
            return prioridad < otro.prioridad; // Prioridad más alta tiene mayor prioridad en el montículo
        } else {
            return ordenDeLlegada > otro.ordenDeLlegada; // En caso de igual prioridad, el que llegó primero tiene prioridad
        }
    }
};

int main() {
    int E;
    cin >> E; // Lee el número de eventos

    priority_queue<Cuentahabiente> cola; // Montículo para mantener a los cuentahabientes ordenados por prioridad
    vector<string> atendidos; // Vector para almacenar los nombres de los cuentahabientes atendidos

    int ordenDeLlegada = 0; // Variable para llevar la cuenta del orden de llegada de los cuentahabientes

    // Bucle para procesar cada evento
    for (int i = 0; i < E; ++i) {
        char evento;
        cin >> evento; // Lee el tipo de evento

        if (evento == 'C') { // Si llega un cuentahabiente
            string nombre;
            int prioridad;
            cin >> nombre >> prioridad; // Lee el nombre y la prioridad del cuentahabiente
            cola.push(Cuentahabiente(nombre, prioridad, ordenDeLlegada++)); // Agrega el cuentahabiente al montículo con su orden de llegada
        } else if (evento == 'S') { // Si se realiza un sorteo
            char letra;
            int incremento;
            cin >> letra >> incremento; // Lee la letra y el incremento de prioridad
            // Itera sobre todos los cuentahabientes en la cola y les suma el incremento si su nombre empieza con la letra del sorteo
            priority_queue<Cuentahabiente> nuevaCola;
            while (!cola.empty()) {
                Cuentahabiente actual = cola.top();
                cola.pop();
                if (actual.nombre[0] == letra) {
                    actual.prioridad += incremento;
                }
                nuevaCola.push(actual);
            }
            cola = nuevaCola; // Actualiza la cola con los cambios realizados
        } else if (evento == 'A') { // Si se atiende a un cuentahabiente
            if (!cola.empty()) {
                atendidos.push_back(cola.top().nombre); // Añade el nombre del cuentahabiente atendido al vector de atendidos
                cola.pop(); // Remueve al cuentahabiente atendido del montículo
            }
        }
    }

    // Imprime los nombres de los cuentahabientes atendidos en el orden en que fueron atendidos
    for (const string& nombre : atendidos) {
        cout << nombre << endl;
    }

    return 0;
}

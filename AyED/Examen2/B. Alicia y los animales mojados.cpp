#include <iostream>
#include <unordered_set> // Incluye la libreria para utilizar conjuntos no ordenados

using namespace std;

int main(){
    int N;
    cin >> N; // Lee el número de animales en la carrera

    unordered_set<int> especies; // Crea un conjunto para almacenar las especies

    // Lectura de secuencia de especies agregando al conjunto 
    
    for (int i = 0; i < N; i++){
        int especie;
        cin >> especie;
        especies.insert(especie);
    }

    
    cout << especies.size() << endl;


    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int juegos, personas;
    cin >> juegos >> personas; // Se lee la cantidad de juegos y de personas

    int estatura_menor = 0; // Se inicializa la estatura mínima con 0
    int estatura_mayor = 0;
    int juegos_subirse = 0;
    int arr[100000];

    // Leer estatura de cada persona y encontrar la estatura mínima
    for (int i = 0; i < juegos; ++i) {
        cin >> arr[i]; // Se lee la estatura de la persona actual
    }

    // Verificar si cada juego cumple con la estatura mínima
    for (int i = 0; i < personas; ++i) {
        int estatura = 0;
        cin >> estatura;
        if (estatura < estatura_menor || i == 0) // Si la estatura del juego es menor o igual a la estatura mínima
            estatura_menor = estatura; // Se incrementa el contador de juegos a los que todos pueden subirse
        if (estatura > estatura_mayor || i == 0)
            estatura_mayor = estatura;
    }

    for (int i = 0; i < juegos; ++i){
        if (arr[i] <= estatura_menor && arr[i] <= estatura_mayor){
            juegos_subirse++;
        }
    }
    cout << juegos_subirse << endl; // Se imprime la cantidad de juegos a los que todos pueden subirse

    return 0;
}
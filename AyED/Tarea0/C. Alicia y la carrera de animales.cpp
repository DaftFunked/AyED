#include <iostream>

using namespace std;

int main() {
    // Variables para almacenar los tiempos del rat�n y del pato
    int R, P;

    // Leer los tiempos del rat�n y del pato
    cin >>R>> P;

    // Calcular el tiempo que le tomar� al rat�n alcanzar al pato sac�ndole una vuelta de ventaja
    // Dado que la distancia recorrida por el rat�n es igual a la longitud de la pista,
    // podemos usar la misma f�rmula de distancia = velocidad x tiempo
    // La distancia recorrida por el pato es 0, ya que el pato no se ha movido
    // Por lo tanto, podemos usar la ecuaci�n (distancia del rat�n) - (distancia del pato) = velocidad del rat�n x tiempo
    // Lo que nos da: L - 0 = velocidad del rat�n x tiempo
    // Simplificando, obtenemos: tiempo = L / velocidad del rat�n
    // Donde L es la longitud de la pista, que es igual al tiempo del pato * velocidad del rat�n menos la velocidad del pato
    // Imprimir el resultado
    cout << static_cast<double>(P * R) / (P - R) << endl;;

    return 0;
}

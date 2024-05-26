#include <iostream>

using namespace std;

int main(){

    char texto[51]; // Almacenamiento de línea de texto

    cin.getline(texto, 51); // Lectura de texto, limitado a 50 caracteres

    int longitud = 0;

    int espacios = 0;

    // Calcular la longitud y cuenta espacios

    for (int i = 0; texto[i] != '\0'; i++){
        longitud++;
        if (texto[i] == ' '){
            espacios++;
        }

        if (texto[i] >= 'A' && texto[i] <= 'Z'){  // Si es una letra mayúscula, se convierte a minúscula
            texto[i] = texto[i] + ('a' - 'A');
        }else if (texto[i] >= 'a' && texto[i] <= 'z'){  // Si es minúscula, se convierte en mayúscula
            texto[i] = texto[i] - ('a' - 'A');
        }else if (texto[i] >= '0' && texto[i] <= '8'){  // Si es un dígito, incrementa en 1
            texto[i] = texto[i] + 1;
        } // Si el dígito es 9, no hay cambios

    }

    cout << longitud << " " << espacios << endl;

    cout << texto << endl;


    return 0;

}
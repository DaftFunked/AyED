#include <iostream>
#include <vector>

using namespace std;

// Función para mezclar los dos arreglos ordenados
vector<int> mergeArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> result; // Vector para almacenar la mezcla de los dos arreglos
    int i = 0, j = 0; // Índices para recorrer los arreglos arr1 y arr2
    
    // Combinar los dos arreglos mientras haya elementos en ambos
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) { // Si el elemento de arr1 es menor, agregarlo a result
            result.push_back(arr1[i]);
            i++;
        } else { // Si el elemento de arr2 es menor o igual, agregarlo a result
            result.push_back(arr2[j]);
            j++;
        }
    }
    
    // Agregar los elementos restantes de arr1, si los hay
    while (i < arr1.size()) {
        result.push_back(arr1[i]);
        i++;
    }
    
    // Agregar los elementos restantes de arr2, si los hay
    while (j < arr2.size()) {
        result.push_back(arr2[j]);
        j++;
    }
    
    return result; // Devolver el arreglo combinado
}

int main() {
    int N, M;
    cin >> N >> M; // Leer la cantidad de números en cada lista
    
    vector<int> arr1(N), arr2(M); // Vectores para almacenar los números de cada lista
    
    // Leer los elementos de la primera lista
    for (int i = 0; i < N; i++) {
        cin >> arr1[i];
    }
    
    // Leer los elementos de la segunda lista
    for (int i = 0; i < M; i++) {
        cin >> arr2[i];
    }
    
    // Mezclar los dos arreglos
    vector<int> merged = mergeArrays(arr1, arr2);
    
    // Imprimir los elementos mezclados
    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0; // Indicar que el programa terminó exitosamente
}
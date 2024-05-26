#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Lectura de la altura del túnel
    int N;
    cin >> N;

    // Creación de una matriz para almacenar las cantidades de mermelada en las botellas
    vector<vector<int> > mermelada(N, vector<int>(2));

    // Lectura de las cantidades de mermelada en las botellas
    for (int i = 0; i < N; ++i) {
        cin >> mermelada[i][0] >> mermelada[i][1];
    }

    // Algoritmo de programación dinámica para encontrar la cantidad máxima de mermelada que puede comer Alicia
    vector<vector<int> > dp(N, vector<int>(2, 0));
    dp[0][0] = mermelada[0][0]; // La cantidad máxima de mermelada que puede comer si empieza en la botella 0
    dp[0][1] = mermelada[0][1]; // La cantidad máxima de mermelada que puede comer si empieza en la botella 1
    for (int i = 1; i < N; ++i) {
        // La cantidad máxima de mermelada que puede comer si toma la botella i y empieza en la botella 0
        dp[i][0] = mermelada[i][0] + max(dp[i - 1][0], dp[i - 1][1]);
        // La cantidad máxima de mermelada que puede comer si toma la botella i y empieza en la botella 1
        dp[i][1] = mermelada[i][1] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    // La cantidad máxima de mermelada que puede comer Alicia será el máximo entre dp[N-1][0] y dp[N-1][1]
    int maxMermelada = max(dp[N - 1][0], dp[N - 1][1]);

    // Imprimir la cantidad máxima de mermelada que puede comer Alicia
    cout << maxMermelada << endl;

    return 0;
}
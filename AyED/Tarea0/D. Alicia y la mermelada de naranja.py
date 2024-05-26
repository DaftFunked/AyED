def main():
    # Lectura de la altura del túnel
    N = int(input())

    # Creación de una lista de listas para almacenar las cantidades de mermelada en las botellas
    mermelada = []
    for _ in range(N):
        mermelada.append(list(map(int, input().split())))

    # Algoritmo de programación dinámica para encontrar la cantidad máxima de mermelada que puede comer Alicia
    dp = [[0, 0] for _ in range(N)]
    dp[0][0] = mermelada[0][0]
    dp[0][1] = mermelada[0][1]
    for i in range(1, N):
        dp[i][0] = mermelada[i][0] + max(dp[i - 1][0], dp[i - 1][1])
        dp[i][1] = mermelada[i][1] + max(dp[i - 1][0], dp[i - 1][1])

    # La cantidad máxima de mermelada que puede comer Alicia será el máximo entre dp[N-1][0] y dp[N-1][1]
    maxMermelada = max(dp[N - 1][0], dp[N - 1][1])

    # Imprimir la cantidad máxima de mermelada que puede comer Alicia
    print(maxMermelada)

if __name__ == "__main__":
    main()

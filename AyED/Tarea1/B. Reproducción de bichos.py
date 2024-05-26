def calcular_bichos(N, D):
    tipoA = N
    tipoB = 0
    tipoC = 0

    for _ in range(D):
        nuevos_tipoA = tipoA
        nuevos_tipoB = tipoA * 3 + tipoB
        nuevos_tipoC = tipoA + tipoB * 2 + tipoC
        nuevos_tipoC += nuevos_tipoA

        tipoA = nuevos_tipoA
        tipoB = nuevos_tipoB
        tipoC = nuevos_tipoC

    return tipoA + tipoB + tipoC

def main():
    # Leer la entrada del usuario
    N, D = map(int, input().split())

    # Calcular el número total de bichos después de D días
    total_bichos = calcular_bichos(N, D)

    # Imprimir el resultado
    print(total_bichos)

if __name__ == "__main__":
    main()
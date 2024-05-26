def aplicar_eventos(arreglo, eventos):
    for tipo, valor in eventos:
        if tipo == 0:
            arreglo = [0] * len(arreglo)
        else:
            arreglo = [x + valor for x in arreglo]
    return arreglo

def main():
    # Leer la entrada del usuario
    N = int(input())  # Tamaño del arreglo
    arreglo = list(map(int, input().split()))  # Valores iniciales del arreglo
    M = int(input())  # Número de eventos
    eventos = [list(map(int, input().split())) for _ in range(M)]  # Detalles de los eventos

    # Aplicar los eventos al arreglo
    arreglo_final = aplicar_eventos(arreglo, eventos)

    # Imprimir el estado final del arreglo
    print(*arreglo_final)

if __name__ == "__main__":
    main()

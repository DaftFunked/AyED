def main():
    # Variables para almacenar los tiempos del ratón y del pato
    R, P = map(int, input().split())

    # Calcular el tiempo que le tomará al ratón alcanzar al pato sacándole una vuelta de ventaja
    # Dado que la distancia recorrida por el ratón es igual a la longitud de la pista,
    # podemos usar la misma fórmula de distancia = velocidad x tiempo
    # La distancia recorrida por el pato es 0, ya que el pato no se ha movido
    # Por lo tanto, podemos usar la ecuación (distancia del ratón) - (distancia del pato) = velocidad del ratón x tiempo
    # Lo que nos da: L - 0 = velocidad del ratón x tiempo
    # Simplificando, obtenemos: tiempo = L / velocidad del ratón
    # Donde L es la longitud de la pista, que es igual al tiempo del pato * velocidad del ratón menos la velocidad del pato
    # Imprimir el resultado
    print(P * R / (P - R))

if __name__ == "__main__":
    main()
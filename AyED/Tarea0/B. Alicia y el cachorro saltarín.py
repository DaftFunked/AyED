def contar_caidas_cachorro(saltos_cachorro, posicion_alicia):
    caidas = 0
    posicion_cachorro = 0

    for salto in saltos_cachorro:
        posicion_cachorro += salto
        if posicion_cachorro == posicion_alicia:
            caidas += 1

    return caidas

def main():
    N = int(input())
    saltos_cachorro = [int(x) for x in input().split()]

    A = int(input())

    caidas = contar_caidas_cachorro(saltos_cachorro, A)
    print(caidas)

if __name__ == "__main__":
    main()

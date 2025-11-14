// Washington Morocho Lema
// FAL-E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <climits>

using namespace std;

/*

    pred codificar(n) : int  -> para cada d_i, d_j : d_i = todos los digitos de n tal que ^ d_j el siguiente digito a d_i tal que d_i > d_j 
    
    P: n ≥ 0
    func codigo(n: int): int
    Q: resultado = codificar(n)

    Función de Cota: t(n) = n

    Ecuacion de recurrencia:
      - Caso base: T(n) = O(1) si n ≤ 10
      - Caso recursivo: T(n) = O(1) + T(n/10) si n > 10

    Coste: O(log10 n) -> logaritmico en base 10 (porque multiplicamos y dividimos por 10 en cada iteracion recursiva)

    En este caso vamos iterando recurivamente de derecha a izquierad y aprovechamos cada iteracion para quedarnos con el mayor digito de la derecha y compararlo
    con el digito actual. Esto es posible, porque el digito menos significativo (el que esta mas a la derecha) al no tener con quien compararlo, siempre se va 
    a mostrar. Entonces en el caso mejor si el digito menos significativo es el mayor digito, solo se mostrara ese.
*/

//funcion recursiva FINAL
int decreciente_final(int n, int acumulado, int mult, int der) {
    if (n < 10) {
        if (n >= der) {
            return acumulado + mult * n;
        }
        else {
            return acumulado;
        }
    }

    int digito = n % 10;

    if (digito >= der) {
        return decreciente_final(n / 10, acumulado + mult * digito, mult * 10, max(digito, der));
    }
    else {
        return decreciente_final(n / 10, acumulado, mult, max(digito, der));
    }
}

//funcion recursiva NO FINAL
int decreciente_no_final(int n, int der) {
    if (n < 10) {
        if (n >= der) {
            return n;
        }
        else {
            return 0;
        }
    }
    int digito = n % 10;
    int decreciente = decreciente_no_final(n / 10, max(digito, der));

    if (digito >= der) {
        decreciente = decreciente * 10 + digito;
    }
    return decreciente;
}

bool resuelveCaso() {
    int n = 0; cin >> n;
    // leer los datos de la entrada

    //resolver el problema

    int final = decreciente_final(n, 0, 1, 0);
    int no_final = decreciente_no_final(n,0);

    // escribir sol
    cout << final << " " << no_final << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_11.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
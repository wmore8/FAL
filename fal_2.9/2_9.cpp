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

    pred mayorIzquierda(n) : int -> para cada d_i : d_i = todos los digitos de n  tal que max(d_i)
    pred menorDerecha(n) : int -> para cada d_i : d_i = todos los digitos de n  tal que min(d_i)
    pred codificar(n) : int  -> para cada d_i : d_i = todos los digitos de n tal que 
    ( d_i % 2 == 0 : d_i * 2 + mayorIzquierda(d_i)) o (d_i % 2 == 1 : d_i * 3 + menorDerecha(d_i))

    P: n ≥ 0
    func codigo(n: int): int
    Q: resultado = codificar(n)

    Función de Cota: t(n) = n

    Ecuacion de recurrencia:
      - Caso base: T(n) = O(1) si n ≤ 10
      - Caso recursivo: T(n) = O(1) + T(n/10) si n > 10

    Coste: O(log10 n) -> logaritmico en base 10 (porque multiplicamos y dividimos por 10 en cada iteracion recursiva)

*/

struct tSol {
    int suma;
    int mayorIz;
};

//funcion recursiva final


tSol codificar(int n, int posicion, int minDr) {
    if (n < 10) {
        //primera posicion
        //cout << "Pos_inversa(" << posicion << "): digito = " << n <<" : Suma actual (0) -> a sumar: " << n << " * 3 + (el menor a su dr: " << minDr << " ) -> 0 + " << (n * 3) + minDr << " = " << n * 3 + minDr << "\n";
        return { n * 3 + minDr, n};

    }
    int digito = n % 10;
    int der = min(digito, minDr);

    tSol codigo = codificar(n / 10, posicion + 1, min(digito, minDr));
    int izq = codigo.mayorIz;

    if (posicion % 2 == 0) {
        //cout << "Pos_inversa(" << posicion << "): digito = " << digito << " : Suma actual (" << codigo.suma << ") -> a sumar: " << digito << " * 2 + (el mayor a la iz: "<< codigo.mayorIz << " ) -> " << codigo.suma << " + " << (digito * 2) + codigo.mayorIz << " = " << codigo.suma + (digito * 2) + codigo.mayorIz << "\n";
        return { codigo.suma + (digito * 2) + codigo.mayorIz, max(digito, codigo.mayorIz) };
    }
    else {
        //cout << "Pos_inversa(" << posicion  << "): digito = " << digito << " : Suma actual (" << codigo.suma << ") -> a sumar: " << digito << " * 3 + (el menor a su dr: " << minDr << " ) -> " << codigo.suma << " + " << (digito * 3) + minDr << " = " << codigo.suma + (digito * 3) + minDr << "\n";
        return { codigo.suma + (digito * 3) + minDr ,max(digito, codigo.mayorIz) };
    }
}

bool resuelveCaso() {
    int n = 0; cin >> n;
    // leer los datos de la entrada

    //resolver el problema

    tSol sol = codificar(n, 0, INT_MAX);

    // escribir sol
    cout << sol.suma << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_9.in");
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
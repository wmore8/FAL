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

pred esPar(n) -> { para todo n 0 <= n tal que n % 2 = 0 }

P: 0 <= n 
Fun jugarDigitos(n :int) return int sol
Q: { sol = d_i : d_i + 1 si esPar(d_i)  } \/ {sol = d_i : d_i - 1 si !esPar(d_i)} siendo d_i cada digito de n

Funcion de Cota: t(n) = n

Ecuacion de recurrencia:
    - Caso base: T(n) = O(1) si n < 10
    - Caso recursivo: T(n) = O(1) + t(n/10) si n > 10

Coste: O(log10 n) logaritmico en base 10

*/

//funcion recursiva no final
int jugarDigitos(int n) {

    if (n == 0) {
        return 1;
    }
    if (n < 10) {
        if (n % 2 == 0) {
            return n + 1;
        }
        else {
            return n - 1;
        }
    }

    int digito = 0;
    if (n % 2 == 0) {
        digito = n % 10 + 1;
    }
    else {
        digito = n % 10 - 1;
    }

    int num = jugarDigitos(n / 10);

    return num * 10 + digito;
}

bool resuelveCaso() {
    int n = 0; cin >> n;

    // leer los datos de la entrada
    int digito = jugarDigitos(n);
    //resolver el problema
    // escribir sol
    cout << digito << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_7.in");
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
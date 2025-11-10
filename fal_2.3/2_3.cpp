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

    pred invertido(n): int = numero formado por los dígitos de n en orden inverso

    P: n ≥ 0
    func invertir(n: int): int
    Q: resultado = invertido(n)

    Función de Cota: t(n) = n

    Ecuacion de recurrencia:
      - Caso base: T(n) = O(1) si n = 0
      - Caso recursivo: T(n) = O(1) + T(n/10) si n > 0

    Coste: O(log10 n) -> logaritmico en base 10

*/

    
int invertir(int x, int acumulado) {

    if (x == 0) {
        return acumulado;
    }

    return invertir(x / 10, acumulado * 10 + (x % 10));
}

bool resuelveCaso() {
    int n = 0; cin >> n;
    // leer los datos de la entrada
    if (n == 0)
        return false;

    //resolver el problema
    int invertido = invertir(n, 0);

    // escribir sol
    cout << invertido << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_3.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
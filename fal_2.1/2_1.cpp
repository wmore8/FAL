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

pred MCD(a,b) -> para todo d perteneciente a N (entertos) tal que max{ d/a ^ d/b} 

P: a > 0 ^ b > 0 
func euclides( a: int, b : int ) : int
Q: mcd = MCD(a,b)

Funcion de Cota: t(b) = b;

Ecuacion de recurrencia : 
- CASO BASE:      T(a, b) = O(1) si b = 0
- CASO RECURSIVO: T(a, b) = O(1) + T(b, a % b) si b > 0


COSTE:
  - Caso base: O(1) - operaciones constantes
  - Caso recursivo: O(1) + T(b, a % b)
  - Numero de llamadas: O(log(min(a,b)))
  - Coste total: O(log(min(a,b))) × O(1) = O(log(min(a,b)))

*/

int euclides(int a, int b) {
    int mcd = 0;

    if (b == 0) {
        mcd = a;
    }
    else if (b > 0) {
        mcd = euclides(b, a % b);
    }

    return mcd;
}
    

bool resuelveCaso() {
    int a = 0, b = 0; cin >> a >> b;
    // leer los datos de la entrada

    if (a == 0 && b == 0)
        return false;

    //resolver el problema
    int mcd = euclides(a, b);

    // escribir sol
    cout << mcd  << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_1.in");
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
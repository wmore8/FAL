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

P: v.size() > 0 ^ para todo i,j: 0 <= i < j < v.size(): v[i] != v[j] ^ v[i] > 0
fun paresImpares(in v: vector<int>) dev sol: int
Q: sol = #{(i,j) | 0 <= i < j < v.size() ^ v[i] % 2 = 1 ^ v[j] % 2 = 0}

Funcion de Cota: t(i) = v.size() - i;

Invariante : I -> 0 <= i < |v| ^
  numImpares = #{j | 0 <= j < i ^ v[j] % 2 = 1} ^
  sol = #{(x,y) | 0 <= x < y < i ^ v[x] % 2 = 1 ^ v[y] % 2 = 0}

COSTE: El coste de la funcion es lineal respecto al numero de elementos del vector v. Cada acceso al vector es constante por lo tanto el coste es O(N)
*/

int paresImpares(const vector<int> v) {
    int sol = 0;
    int numImpares = 0;

    for (int i = 0; i < v.size(); i++) {

        if (v[i] % 2 == 1) {
            numImpares++;
        }
        else {
            sol += numImpares;
        }
    }

    return sol;
}

bool resuelveCaso() {
    int N; cin >> N;

    // leer los datos de la entrada

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
   
    //resolver el problema
    int sol = paresImpares(v);

    // escribir sol
    cout << sol << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_21.in");
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
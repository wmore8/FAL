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
pred cerosUnos(v,p,q) -> para todo i, j : p <= i <= j <= q : true si { v[i] = 0 ^ v[j] = 1 ^  #v[i] = #v[j] }

P: 1 >= l >= n
func segmentos( vector<int> : v, int : l  ) : int 
Q: sol = # {cerosUnos(v, i, i + l) } tal que { l <= i < v.size() }

Funcion de Cota: t(i) = v.size() - i;

Invariante : I -> 0 <= i < |v| ^
 sol = #{j | 0 <= j <= i-l ^ cerosUnos(v, j, j+l)} ^
 numCeros = #{k | i-l <= k < i ^ v[k] = 0} ^
 numUnos = #{k | i-l <= k < i ^ v[k] = 1}

COSTE: El coste de la funcion es lineal respecto al numero de elementos del vector v. Cada acceso al vector es constante por lo tanto el coste es O(N)
*/

int segmentos(const vector<int> v, int l) {
    int longitud = 0, sol = 0;
    int numCeros = 0, numUnos = 0;

    for (int i = 0; i < v.size(); i++) {

        if (v[i] == 0) {
            ++numCeros;
        }
        else if (v[i] == 1) {
            ++numUnos;
        }
        ++longitud;

        if (longitud == l) {
            if (numCeros == numUnos) {
                ++sol;
            }

            if (v[i - l + 1] == 0) {
                --numCeros;
            }
            else if (v[i - l + 1] == 1) {
                --numUnos;
            }
            --longitud;
        }

    }
    return sol;
}

bool resuelveCaso() {
    int l, N; cin >> l >> N;

    // leer los datos de la entrada

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
   
    //resolver el problema
    int sol = segmentos(v, l);

    // escribir sol
    cout << sol << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_20.in");
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
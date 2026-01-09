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

1.Predicado
    equilibrado(w,p,q) -> #i == #j para todo i,j : p <= i <= j < q tal (que v[i]%2 == 0 ^ v[j]%2 == 1)

2.Especificacion
P: 1 <= l <= v.size() <= w.size()
func: maxSuma(vector<int> : v, vector<int> : w, int : l) : return int
Q: res = max( SUM(v[i]) : 0 <= i < v.size() ^ para todo k : i <= k < v.size() ^ equilibrado(w,i,k) tal que k - i = l)

4.Invariante:
    I = 0 <= i < v.size() ^
    actual = SUM(v[k]) : i - l <= k <= i < v.size() ^
    numPares = #k : i - l <= k <= i: v[k]%2 = 0 ^
    numImpares = #k : i - l <= k <= i : v[k]%2 = 1 ^
    sol = max(actual) ^ equilibrado(w,k, k + l)

5.Coste asintótico: El coste es lineal debido a que accedemos una unica vez a todos los elementos de ambos vectores de manera constante -> O(N)

*/

int maxSuma(const vector<int>& v, const vector<int>& w, int l) {
    int sol = 0, actual = 0,numPares = 0, numImpares = 0, longitud = 0;

    for (int i = 0; i < v.size(); i++) {
        if (w[i] % 2 == 0) {
            numPares++;
        }
        else {
            numImpares++;
        }

        actual += v[i];

        longitud++;

        if (longitud >= l) {
            if (numPares == numImpares && actual > sol) {
                sol = actual;
            }
            //deslizamos
            int posComienzo = i - l + 1;

            actual -= v[posComienzo];

            if (w[posComienzo] % 2 == 0) {
                numPares--;
            }
            else {
                numImpares--;
            }
        }
    }

    return sol;
}

bool resuelveCaso() {
    int N, l; cin >> N >> l;
    // leer los datos de la entrada

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> w(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
   
    //resolver el problema
    int sol = maxSuma(v, w, l);

    // escribir sol
    cout << sol << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("4_5.in");
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
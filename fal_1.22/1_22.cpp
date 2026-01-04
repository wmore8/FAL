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

P: v.size() > L > 0 ^ para todo i: 0 <= i < v.size(): 0 <= v[i] <= 10
fun lectura(in v: vector<int>, in L: int) dev inicio: int
Q: inicio = max i: 0 <= i <= v.size()-L:
     { suma(v, i, i+L) = max_{j: 0 <= j <= v.size()-L} suma(v, j, j+L) ^
      para todo k: i < k ≤ v.size()-L: suma(v, k, k+L) < suma(v, i, i+L) ó (suma(v, k, k+L) = suma(v, i, i+L) ^ k > i)}

donde suma(v, p, q) = SUM_{j=p}^{q-1} v[j]

Funcion de Cota: t(i) = v.size() - i;

Invariante : I -> 0 <= i < |v| ^
  sumaActual = SUM_{j=i-L}^{i-1} v[j] ^
  sumaMax = max_{k: 0 <= k <= i-L} SUM_{j=k}^{k+L-1} v[j] ^
  inicio = max k: 0 <= k <= i-L: (SUM_{j=k}^{k+L-1} v[j] = sumaMax ^
  para todo m: k < m <= i-L: SUM_{j=m}^{m+L-1} v[j] < sumaMax ó m > k)

COSTE: El coste de la funcion es lineal respecto al numero de elementos del vector v. Cada acceso al vector es constante por lo tanto el coste es O(N)
*/

int lectura(const vector<int>& v, int l) {
    int sol = 0, maxValor = 0;
    int paginas = 0, actual = 0;


    for (int i = 0; i < v.size(); i++) {
        actual += v[i];

        paginas++;

        if (paginas == l) {

            if (actual >= maxValor) {
                maxValor = actual;
                sol = i - l + 1;
            }
            actual -= v[i - l + 1];

            paginas--;
        }
    }

    return sol;
}

bool resuelveCaso() {
    int N, l; cin >> N >> l;
    if (N == 0 && l == 0) return false;

    // leer los datos de la entrada

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
   
    //resolver el problema
    int sol = lectura(v, l);

    // escribir sol
    cout << sol << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_22.in");
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
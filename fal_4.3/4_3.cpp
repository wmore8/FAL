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
 
1- Define un predicado:
    
    pred todosIguales(v, p, q) ->  v[i] = v[i + 1] para todo i : p <= i < q - 1 :

2- Especificacion de funcion: 
    P: 1 <= l <= n
    func segmentos(int : l, vector<int> : v) : int
    Q: sol = #{(i,j) : todosIguales(v, i, j) para todo i, j : 0 <= i < j < v.size() tal que (j - i >= l)}
    
4- Invariante:
    Funcion de cota : t(i) = v.size() - i
    
   I = 0 <= i < v.size() ^
   valor = v[i] ^ 
   longitud = # v[k] para todo k : i <= k < v.size() - 1 tal que v[k] = v[k+1] ^
   numSeg = # k para todo k : i <= k < v.size() tal que k - i >= l ^ 
   sol = 

5- Coste asintótico: 
    El coste en el caso peor es lineal O(N), debido a que accedemos a todos los valores del vector de forma constante O(1) 

*/

int segmentos(const vector<int>& v, int l) {
    int sol = 0,valor = v[0], longitud = 0, numSeg = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == valor) {
            longitud++;
        }
        else {
            valor = v[i];
            longitud = 1;
            numSeg = 0;
        }

        if (longitud >= l) {
            numSeg++;
            sol += numSeg;
        }
    }

    return sol;
}


bool resuelveCaso() {
    int N, l; cin >> l >> N;
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
    std::ifstream in("4_3.in");
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
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
    
    pred paresMayorImpares(v, p, q) -> para todo i : p <= i <= j < q tal que SUM(v[i]) > SUM(v[j]) ^  v[i]%2 = 0 ^ v[j]%2 = 1

2- Especificacion de funcion: 
    P: l >= 1 ^ n >= 1 ^ n = v.size()
    func segmentos(vector<int> : v, int : l) : int
    Q: res = #(paresMayorImpares(v, i, i + l)) tal que i : 0 <= i + l < n 
    
4- Invariante:
    Funcion de cota : t(i) = v.size() - i 
    
    I = 0 <= i < v.size() ^
    sol = #k : l-1 <= k < i : paresMayorImpares(v, k - l + 1, k + 1) ^
    sumPares = SUM(v[k]) : i - l + 1 <= k < i ^ v[k]%2 == 0  ^
    sumImpares = SUM(v[k]) : i - l + 1 <= k < i ^ v[k]%2 == 1  

5- Coste asintótico: 
    El coste en el caso peor es lineal O(N), debido a que accedemos a todos los valores del vector de forma constante O(1) 

*/

int segmentos(const vector<int>& v, int l) {
    int sol = 0, sumPares = 0, sumImpares = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 0) {
            sumPares += v[i];
        }
        else {
            sumImpares += v[i];
        }


        if (i >= l - 1) {

            if (sumPares > sumImpares) {
                sol++;
            }

            //damos pie al siguiente valor
            int posComienzo = i - l + 1;

            if (v[posComienzo] % 2 == 0) {
                sumPares -= v[posComienzo];
            }
            else {
                sumImpares -= v[posComienzo];
            }

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
    int sol = segmentos(v,l);

    // escribir sol
    cout << sol << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("4_1.in");
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
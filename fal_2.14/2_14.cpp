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

pred minElem(v) -> para todo i  tal que min(v[i]) ^ 0 <= i < |v|

P: 0 <= v.size()
func minElemento(v vector<int>) : return int minimo
Q: minimo = minElem(v)

Funcion de Cota : t(n) = n

Ecuacion de recursion
siendo n = la distancia entre fin - ini
Caso base: T(n) = c1 si n < 2
Caso recursivo: T(n) = (n/2) + c2 si n > 2

COSTE : c1 y c2 son tiempos constantes distintos, pero pertenecen al orden de magnitud constante -> O(1). El caso recursivo de n/2 pertenece al orden de O(log n)
Coste total: O(log n) + O(1) = O(log n) 
*/

int minimo(vector<int> const& v, int ini, int fin) {

    if (ini == fin) {
        return v[ini]; // Caso base: solo hay un elemento
    }
    else if (fin - ini == 1) {
        return min(v[ini], v[fin]); // Caso base: solo hay 2 elementos
    }
    else {
        if (v[ini] > v[fin]) {
            return v[fin];
        }
        else {
            --fin;
            int m = (fin + ini) / 2;

            int minIz = minimo(v, ini, m);
            int minDr = minimo(v, m, fin);

            return min(minIz, minDr);
        }
    }
}

bool resuelveCaso() {
    int N = 0; cin >> N;
    // leer los datos de la entrada
    if (!std::cin) return false;

    vector<int> numeros(N);

    int valor = 0;

    for (int i = 0; i < N; i++) {
        cin >> valor;
        numeros[i] = valor;
    }

    //resolver el problema
    int minElem = minimo(numeros, 0, N - 1);

    // escribir sol
    cout << minElem << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_14.in");
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
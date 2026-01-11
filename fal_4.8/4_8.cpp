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

funcion de cota: t(ini,fin) = fin - ini = v.size()

Ecuacion de recurrencia
    - Caso base: t(n) = c1 si n < 1
    - Caso recursivo: t(n) = t(n/2) + c2 si n > 1

Coste asintotico: En el caso peor no recorremos del todo el vector, vamos buscando por mitades como en la busqueda binaria. Por el teorema de la division 
con a = 1, b = 2 y k = 0, obtenemos 1 = 2^0 -> por lo tanto la funcion entra dentro del orden(N^k*log N) y como en este caso la k = 0, el coste quedaria 
en O(1 * log N) = O(log N).

*/


int ahorro(const vector<int>& v, int ini, int fin, int p, int a, int n) {
    if (ini >= fin) {
        return ini;
    }
    else {
        int m = (ini + fin) / 2;
        int dineroDisponible = p - v[m];
        int dineroNecesario = (n - m) * a;

        if (dineroDisponible < dineroNecesario) { //miramos por la izquierda por que nos hemos pasado de presupuesto
            return ahorro(v, ini, m, p, a, n);
        }
        else{ //miramos por la derecha por que aun nos queda presupuesto
            return ahorro(v, m + 1, fin, p, a, n);
        }

    }
}

bool resuelveCaso() {
    int P, a, n; cin >> P >> a >> n;

    // leer los datos de la entrada
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    //resolver el problema
    int sol = ahorro(v, 0, n , P, a, n);

    // escribir sol
    if (sol < n) {
        cout << sol;
    }
    else {
        cout << "NO NECESARIO";
    }

    cout  << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("4_8.in");
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
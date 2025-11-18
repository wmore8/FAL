// Washington Morocho Lema
// FAL-E51

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <climits>
#include <string>

using namespace std;

/*
funcion de cota: t(ini,fin) = ini - fin = v.size()

Ecuacion de recurrencia:

Siendo n = fin - ini

    - Caso base: t(n) = C1 si n = 0 pertenece al orden O(1)
    - Caso recursivo: t(n) = O(n/2) + C2 si n > 0 -> pertenece al orden O(log N)

Coste: siendo C1 y C2 tiempos constantes diferentes, ambos entran en el orden O(1). Finalmente el coste esta delimitado por la recursion  que se da en el resto 
de casos, del orden O(log N) -> TOTAL = O(log N) + O(1) = O(log N)
*/

int bongo(const vector<int>& v, int ini, int fin, int e) {

    if (ini == fin) { 
        return -1; // Caso base: si no hay ningun numero que coincida devolvemos -1
    }
    else {
        int m = (fin + ini) / 2; // posicion del elemento del medio

        if (v[m] > e + m) { // Caso recursivo: si el numero actual es mayor que el cantado, buscamos por la izquierda
            return bongo(v, ini, m, e);
        }
        else if (v[m] < e + m) { // Caso recursivo: si el numero actual es menor que el cantado, buscamos por la derecha
            return bongo(v, m + 1, fin, e);
        }
        else { // Caso base: si el numero actual es el cantado, lo devolvemos
            return v[m];
        }
    }
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int N, e; cin >> N >> e;

    vector<int> carton(N);
    int aux;

    for (int i = 0; i < N; i++) {
        cin >> aux;
        carton[i] = aux;
    }

    //resolver el problema
    int sol = bongo(carton, 0, N, e);

    // escribir sol
    if (sol == -1) {
        cout << "NO\n";
    }
    else {
        cout << sol << "\n";
    }

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_16.in");
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
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

1.Especificacion
    
    P: 0 <= S && 0 <= v.size()
    Func: maxGanancia(vector<int> : v, int: v) return tuple<int, int, int>
    Q: sol = max(SUM(v[i]): para todo i : 0 <= i < v.size() ^ p,q : 0 <= p <= i <= q < v.size() : sol.ini = p, sol.fin = q ) : sol.valor > 0 
    
3:invariante
    Funcion de cota: t(i) = v.size() - i

    I = 0 <= i < v.size() ^ S >= 0 ^


4.Coste asintotico: El coste es lineal debido a que recorremos todos las variables del vector con acceso constante O(1) -> O(N) lineal en funcion del tamaño del vector

*/

struct tSol {
    int ganancia;
    int ini;
    int fin;
};

tSol maxGanancia(const vector<int>& v, int s) {
    tSol sol = { 0,0,0 };
    int ganancia_actual = 0, ganancia_max = 0, longitud = 0, ini = 0;

    for (int i = 0; i < v.size(); i++) {
        ganancia_actual += v[i];
        longitud++;

        if (ganancia_actual > ganancia_max) {
            ganancia_max = ganancia_actual;
            sol.ganancia = ganancia_max;
            sol.fin = i;
            sol.ini = ini;
        }

        if (ganancia_actual < 0) {
            ganancia_actual = 0;
            ini = i + 1;
        }
    }

    return sol;
}


bool resuelveCaso() {
    int N, S; cin >> N >> S;

    // leer los datos de la entrada
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    //resolver el problema
    
    tSol sol = maxGanancia(v, S);

    // escribir sol

    if (sol.ganancia >= S) {
        cout << sol.ganancia << " " << sol.ini << " " << sol.fin;
    }
    else {
        cout << "NO COMPENSA";
    }

    cout  << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("4_7.in");
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
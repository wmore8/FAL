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

using tMatriz = vector<vector<int>>;

/*
2. (0,5 puntos) Escribe la recurrencia que corresponde al coste de la función recursiva e indica a qué
orden de complejidad asintótica pertenece dicho coste.

Funcion de cota : t(ini,fin) = fin - ini = v.size()

Ecuacion de recurrencia:

    - Caso base:        T(n) = C1               si n <= 1 
    - Caso recursivo:   T(n) = 2T(n/2) + C2     si n > 1 

Siendo C1 y C2 valores constntes O(1) distintos.
Por el teorema de la division con a = 2, b = 2, k = 0, obtenemos que la complejidad del algoritmo se encuentra en el orden O(N^(log_b(a))) por a > b^k.ç
Susutituyendo los valores obtenemos que log_b(a) = 1 y por lo tanto el orden es O(N) lineal (siendo N el numero de elementos del vector).

Tiene sentido porque al final recorremos ambas mitades del vector para verficar que se cumpla la distribucion solicitada.

1. (2,5 puntos) Diseña un algoritmo recursivo e!ciente que permita resolver el problema.

*/

struct tSol {
    bool cumpleDistribucion;
    int positivos;
    int negativos;
};

tSol distribucion_rec(const vector<int>& v, int ini, int fin, int k) {
    if (ini == fin) {// Caso base: solo hay un elemento
        if (v[ini] > 0) {
            return { true, 1, 0 }; //si es positivo 
        }
        else if(v[ini] < 0){
            return { true, 0, 1 }; //si es negativo
        }
        else {//si es cero 
            return { true, 0, 0 };
        }
    }
    else {
        int m = (ini + fin) / 2;
        tSol iz = distribucion_rec(v, ini, m, k);
        tSol dr = distribucion_rec(v, m + 1, fin, k);

        int positivosTotal = iz.positivos + dr.positivos;
        int negativosTotal = iz.negativos + dr.negativos;

        bool esSeti = positivosTotal - negativosTotal >= k;

        return { esSeti && (iz.cumpleDistribucion || dr.cumpleDistribucion), positivosTotal, negativosTotal };
    }

}

pair<bool, int> cumpleDistribucion(const vector<int>& v, int k) {
    tSol sol = distribucion_rec(v,0, v.size() - 1, k);

    return { sol.cumpleDistribucion, sol.positivos - sol.negativos };
}

bool resuelveCaso() {
    int N, k; cin >> N >> k;
    if (!cin) return false;

    // leer los datos de la entrada
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    //resolver el problema
    pair<bool, int> sol = cumpleDistribucion(v, k);
  
    // escribir sol
    if (sol.first) {
        cout << sol.second << "\n";
    }
    else {
        cout << "NO\n";
    }

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("ENE_2.in");
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
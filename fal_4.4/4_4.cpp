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
 Funcion de cota: t(i) = v.size() - i

 Ecuacion de recurrencia:
    Caso base: T(n) = C1 si n < 2 
    Caso recursivo: T(n) = C2 + T(N/2)  si n > 2
    
Coste : O(log N) porque no recorremos el vector por completo, como mucho recorremos la mitad de este. Cada acceso es constante
*/

int picudo(const vector<int>& v, int ini, int fin) {

    if (ini == fin - 1) {//caso base: solo 2 elementos
        return v[fin] - v[ini];
    }
    else {
        int m = (ini + fin) / 2;
        int dr = v[m + 1] - v[m];
        int iz = v[m] - v[m - 1];
        if (dr > iz) {
            return picudo(v, m, fin);
        }
        else {
            return picudo(v, ini, m);
        }
    }

}


bool resuelveCaso() {
    int N; cin >> N;
    // leer los datos de la entrada

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
   
    //resolver el problema
    int sol = picudo(v,0, N - 1);

    // escribir sol
    cout << sol << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("4_4.in");
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
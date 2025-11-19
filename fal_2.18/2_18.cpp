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

Funcion de cota: t(ini,fin) = fin - ini == v.size()

Ecuacion de recurrencia
    - Caso base: t(n) = C1 si n = 0
    - Caso recursivo: t(n) = 2T(n/2) + C2 si n > 0

Coste: Siendo C1 y C2 costes constantes diferentes, pero que pertenecen al orden de O(1), el coste de recorrer una mitad(n/2) es O(log n) porque no siempre recorremos
todos los elementos. Debido a que realizamos el recorrido por ambas mitades, y que cada acceso es constante, el coste seria lineal en funcion del tamaño del vector:
Total = 2 * O(log n) + O(1) = O(n)

*/

struct tSol {
    int numPares;
    bool caucasico;
};

tSol caucasico(const vector<int>& v, int ini, int fin) {
    //Caso base: si v contiene 1 elemento entonces es caucasico
    if (ini == fin) { 
        if (v[ini] % 2 == 0) return { 1, true }; // si es par, se cuenta
        else return { 0, true };// si NO es par, no se cuenta
    }
    else {
        int m = (ini + fin) / 2;

        tSol iz = caucasico(v, ini, m);
        tSol dr = caucasico(v, m+1, fin);

        tSol sol = { 0,false };

        if (iz.caucasico && dr.caucasico && abs(iz.numPares - dr.numPares) <= 2) {
            sol.numPares = iz.numPares + dr.numPares;
            sol.caucasico = true;
        }

        return sol;
    }
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int N; cin >> N;

    if (N == 0) return false;

    vector<int> lista(N);

    for (int i = 0; i < N; i++) {
        cin >> lista[i];
    }

    //resolver el problema
    tSol sol = caucasico(lista, 0, N - 1);

    // escribir sol
    if (sol.caucasico) {
        cout << "SI\n";
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
    std::ifstream in("2_18.in");
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
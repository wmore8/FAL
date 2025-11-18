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

Funcion de cota: t(ini,fin) = fin - ini = v.size()

Ecuacion de recurrencia: Siendo n = fin - ini ->
    - Caso base: t(n) = C1 si n = 0 
    - Caso recursivo: t(n) = 2T(n/2) +  C2 si n > 0

Coste: siendo C1 y C2 tiempos constantes distintos que pertencen al orden de O(1), el coste por recorrer la mitad del vector (n/2) es de O(log n),
como lo recorremos 2 veces (una por la izqierad y otra por la derecha) -> Coste = 2* O(n/2) = O(n)

*/

struct tSol {
    int min;
    int max;
    bool parcial;
};

tSol esParcial(const vector<int>& v, int ini, int fin) {

    if (ini == fin) {
        return { v[ini], v[fin], true }; // Caso base de 1 elemento : devolvemos ese valor como max, min y ademas es SI parcial
    }
    int m = (fin + ini) / 2;

    tSol iz = esParcial(v, ini, m); // Caso recursivo: recorremos el vector por la izquierda
    tSol dr = esParcial(v, m + 1, fin); // Caso recursivo: recorremos el vector por la derecha

    tSol sol = {0, 0, false};

    if (iz.parcial && dr.parcial && iz.min <= dr.min && dr.max >= iz.max) {
        sol.min = iz.min;
        sol.max = dr.max;
        sol.parcial = true;
    }

    return sol;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int valor = 0; cin >> valor;

    if (valor == 0) return false;

    vector<int> lista;

    while (valor != 0) {
        lista.push_back(valor);
        cin >> valor;
    } 
    //resolver el problema
    tSol sol = esParcial(lista, 0, lista.size() - 1);

    // escribir sol
    if (sol.parcial) {
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
    std::ifstream in("2_17.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while ( resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
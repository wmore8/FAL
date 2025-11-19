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

Ecuacion de recurrencia :
    - Caso base: t(n) = C0 si n = 1
    - Caso recursivo: t(n) = 2T(n/2) + C1*n si n > 1

Coste: Siendo C0 y C1 tiempos constantes diferentes que entran dentro del orden O(1), recorrer la mitad del vector(n/2) entra en el orden O(log n),
como recorremos ambas mitades, acabamos recorriendo todo el vector -> O(n). Con la ayuda de la funcion comprobar recorremos un subvector del vector original
que como no esta completo, el coste es O(log n). El coste total seria : O(n) + O(log n) * O(1) = O(n log n)

*/

struct tSol {
    int num;
    bool mayoritario;
};

bool comprobar(const vector<int>& v, int ini, int fin, int x) {
    int n = 0;

    for (int i = ini; i <= fin; i++) {
        if (v[i] == x) {
            n++;
        }
    }

    return n > (fin - ini + 1) / 2;
}

tSol mayoritario(const vector<int>& v, int ini, int fin) {
    
    if (ini == fin) {
        return { v[ini], true};
    }
    else {
        int m = (ini + fin) / 2;

        tSol iz = mayoritario(v, ini, m);
        tSol dr = mayoritario(v, m + 1, fin);

        tSol sol = { iz.num, false};

        if (iz.mayoritario) {
            sol.mayoritario = comprobar(v, ini, fin, iz.num);
        }
        else if (!sol.mayoritario && dr.mayoritario) {
            sol.mayoritario = comprobar(v, ini, fin, dr.num);
            sol.num = dr.num;
        }

        return sol;
    }
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int valor = 0;
    vector<int> v;

    cin >> valor;

    while (valor != 0) {
        v.push_back(valor);
        cin >> valor;
    }

    //resolver el problema
    tSol sol = {0,0};

    if (v.size() > 0) {
        sol = mayoritario(v, 0, v.size() - 1);
    }

    // escribir sol

    if (!sol.mayoritario) {
        cout << "NO\n";
    }else{
        cout << sol.num << "\n";
    }

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_21.in");
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
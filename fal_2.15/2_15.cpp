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

Ecuacion de recurrencia:
    - Caso base: t(n) = C1 si n + 1 == fin pertenece al orden O(1)
    - Caso recursivo: t(n) = O(n/2) + C2 si n + 1 != fin -> pertenece al orden O(log N)

Coste: siendo C1 y C2 tiempos constantes diferentes, ambos entran en el orden O(1). Finalmente el coste esta delimitado por la recursion  que se da en el resto 
de casos, del orden O(log N) -> TOTAL = O(log N) + O(1) = O(log N)
*/




char fuga(const vector<char>& v, int ini, int fin) {

    if (ini + 1 == fin) { // Caso base: hemos recorrido toda la lista y hemos encontrado la que falta
        return v[ini] + 1;
    }
    else {
        int m = (ini + fin) / 2;
        if (v[ini] - ini != v[m] - m) { // si no hemos explorado la izquierda
            return fuga(v, ini, m);
        }
        else { // si no hemos explorado la derecha
            return fuga(v, m, fin);
        }
    }
}

bool resuelveCaso() {
    // leer los datos de la entrada
    char ini, fin; cin >> ini >> fin;

    char aux;
    vector<char> presos(fin - ini);

    for (int i = 0; i < fin - ini; i++) {
        cin >> aux;
        presos[i] = aux;
    }

    //resolver el problema
    char fugitivo;

    if (presos[0] != ini) { //Caso base: el primer elemento de la lista no coincide con la primera letra del rango de busqueda
        fugitivo = ini;
    }
    else if (presos[presos.size()-1] != fin){ //Caso base: el primer elemento de la lista no coincide con la primera letra del rango de busqueda
        fugitivo = fin;
    }else{
        fugitivo = fuga(presos, 0, presos.size() - 1);
    }

    // escribir sol
    cout << fugitivo << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_15.in");
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
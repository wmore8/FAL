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

    pred buscarIz(v, a) -> min { i : 0 <= i < |v| ^ v[i] = a }
    pred buscarDr(v, a) -> max { i : 0 <= i < |v| ^ v[i] = a }

    P: n ≥ 0
    func busqueda(v:vector<int>, altura: int): pair<int,int>
    Q: resultado = { buscarIz(v,altura), buscarDr(v,altura) }

    Función de Cota: t(ini, fin) = fin - ini

    Ecuacion de recurrencia:

     busquedaIz:
    - Caso base: T(n) = O(1) si i = |v|
    - Caso recursivo: T(n) = O(1) + T(n-1) si i < |v|

    busquedaDr:
    - Caso base: T(n) = O(1) si i = -1
    - Caso recursivo: T(n) = O(1) + T(n-1) si i ≥ 0

    Coste: O(n) -> lineal porue en el caso peor se resuelve todo el vector (hasta 2 veces)

*/

int busquedaIz(vector<int> const& v, int i ,int altura) {

    if (i == v.size()) {
        return -1;
    }
    else if (v[i] == altura) {
        return i;
    }

    int posicion = busquedaIz(v, ++i, altura);

    return posicion;
}

int busquedaDr(vector<int> const& v, int i , int altura) {

    if (i == -1) {
        return -1;
    }
    else if (v[i] == altura) {
        return i;
    }

    int posicion = busquedaDr(v, --i, altura);

    return posicion;
}

bool resuelveCaso() {
    int n = 0, altura = 0; cin >> n >> altura;
    if (!std::cin) return false;

    // leer los datos de la entrada
    vector<int> sospechosos(n);
    int valor = 0;
    for (int i = 0; i < n; i++) {
        cin >> valor;
        sospechosos[i] = valor;
    }

    //resolver el problema
    int alturaIz = busquedaIz(sospechosos, 0, altura);
    int alturaDr = busquedaDr(sospechosos, n - 1, altura);

    // escribir sol

    if (alturaIz == -1 && alturaDr == -1) {
        cout << "NO EXISTE";
    }
    else {
        if (alturaIz == alturaDr) {
            cout << alturaIz;
        }
        else {
            cout << alturaIz << " " << alturaDr;
        }
    }

    cout << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_4.in");
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
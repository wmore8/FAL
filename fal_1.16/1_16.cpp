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
pred division (v, p) -> para todo i, j tal que { (max_izq = max (v[i]) : 0 <= i <= p) ^ (min_der = min (v[j]) : p < j < |v|) ^ max_izq < min_der }

P: 0 <= p < v.size()
func bienDividido( v:vector<int>, p:int ) : bool
Q: solucion = division (v,p)  

Funcion de Cota: t(i) = v.size() - i;

Invariante : I -> 0 <= i < |v| ^
max_izq = max { v[k] | 0 <= k < i ^ k <= p } ^ 
min_der = min { v[k] | 0 <= k < i ^ k > p } ^

COSTE: El coste de la funcion es lineal respecto al numero de elementos del vector v. Cada acceso al vector es constante por lo tanto el coste es O(N)
*/



bool bienDividido(vector<int> const& v, int p) {
    int max_izq = v[0], min_der = INT_MAX;

    for (int i = 0; i < v.size(); i++) {
        if (i <= p && v[i] > max_izq) {
            max_izq = v[i];
        }
        else if(i > p && v[i] < min_der){
            min_der = v[i];
        }
    }

    return max_izq < min_der;
}
    

bool resuelveCaso() {
    int N = 0, p = 0; cin >> N >> p;

    // leer los datos de la entrada
    vector<int> temperaturas(N);
    int valor = 0;

    for (int i = 0; i < N; i++) {
        cin >> valor ;
        temperaturas[i] = valor;
    }

    //resolver el problema

    // escribir sol

    if (bienDividido(temperaturas, p)) {
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
    std::ifstream in("1_16.in");
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
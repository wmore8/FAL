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
pred ordenar (a, b) -> para todo i, j tal que { 0 <= i < a ^ 0 <= j < b ^ 0 <= k < i + j: sol[k] = min{ a[i], b[j]} }

P: 0 <= n < |a| + |b|
func ordenarLista( vector<int> : a, vector<int> : b  ) : vector<int>
Q: solucion = ordenar(a,b)  

Funcion de Cota: t(i) = v.size() - i;

Invariante : I -> 0 <= i < |v| ^
max_izq = max { v[k] | 0 <= k < i ^ k <= p } ^ 
min_der = min { v[k] | 0 <= k < i ^ k > p } ^

COSTE: El coste de la funcion es lineal respecto al numero de elementos del vector v. Cada acceso al vector es constante por lo tanto el coste es O(N)
*/

struct Persona {
    string nombre;
    int altura;
};

const bool operator < (const Persona& a, const Persona& b) {
    return a.nombre < b.nombre;
}

pair<vector<Persona>, vector<Persona>> ordenarPasajeros(const vector<Persona>& pasajeros, int altura) {
    vector<Persona> bajos;
    vector<Persona> altos;

    for (int i = 0; i < pasajeros.size(); i++) {
        if (pasajeros[i].altura <= altura) {
            bajos.push_back(pasajeros[i]);
        }
        else {
            altos.push_back(pasajeros[i]);
        }
    }

    return { bajos,altos };
}


bool resuelveCaso() {
    int N, altura; cin >> N >> altura;

    if (!std::cin) return false;
    // leer los datos de la entrada
    vector<Persona> pasajeros(N);

    for (int i = 0; i < N; i++) {
        cin >> pasajeros[i].nombre >> pasajeros[i].altura;
    }

    //resolver el problema
    auto lista  = ordenarPasajeros(pasajeros, altura);
    //ordenamos alfabeticamente por nombre en ambas listas
    sort(lista.first.begin(), lista.first.end());
    sort(lista.second.begin(), lista.second.end());

    // escribir sol
    cout << "Bajos: ";
    for (int i = 0; i < lista.first.size(); i++) {
        cout << lista.first[i].nombre << " ";

    }
    cout << "\n";

    cout << "Altos: ";
    for (int i = 0; i < lista.second.size(); i++) {
        cout << lista.second[i].nombre << " ";

    }
    cout << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_19.in");
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
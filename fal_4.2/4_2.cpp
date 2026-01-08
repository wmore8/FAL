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
 
Funcion de cota: t(n) = n == v.size()

Ecuacion de recurrencia
    - Caso base: t(n) = C1 si n <= 2 pertenece a O(1)
    - Caso recursivo: t(n) = T(n/2) + C2 si n > 2  pertenece a O(log n)

Coste: Siendo C1 y C2 costes constantes diferentes, pero que pertenecen al orden de O(1), el coste de recorrer una mitad(n/2) es O(log n) porque no siempre recorremos
todos los elementos -> Total = O(log n) + O(1) = O(log n)


*/

int datacion(const vector<int> v, int ini, int fin, int f) {
    if (ini == fin) { // Caso base: solo tenemos 1 elemento 
        return v[ini];
    }
    else if (ini == fin - 1) { // Caso base: comparamos 2 elementos
        int d1 = abs(f - v[ini]);
        int d2 = abs(f - v[fin]);

        if (d2 < d1) { // si el valor de la derecha es mas cercano a f, lo devolvemos
            return v[fin];
        }
        else { // si el valor de la izquierda es mas cercano a f, o tiene la misma distancia, devolvemos el valor mas reciente (ini por estar ordenado de mayor a menor)
            return v[ini];
        }
    }
    else {
        int m = (ini + fin) / 2;

        if (v[m] < f) {
            return datacion(v, ini, m, f);
        }
        else if (v[m] > f) { //si el valor de en medio es mayor que el que buscamos, probamos por la derecha
            return datacion(v, m, fin, f);
        }

        else {
            return v[m];
        }

    }
}


bool resuelveCaso() {
    int N, f; cin >> N >> f;
    if (N == 0 && f == 0) return false;
    // leer los datos de la entrada

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
   
    //resolver el problema
    int sol = datacion(v, 0, N-1, f);

    // escribir sol
    cout << sol << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("4_2.in");
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
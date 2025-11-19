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

funcion de cota: t(ini, fin, drones) = fin - ini == v.size() && drones > 0

Ecuacion de recurrencia:
    - Caso base: t(n) = C0 si n = 1
    - Caso recursivo: t(n) = 2T(n/2) + n * C0 si n > 1

Coste: mientras tengamos mas de un dron 
*/


bool comprobar(const vector<int>& v, int ini, int fin, int d, int capacidad) {
    int cargaActual = 0;
    int dronesUsados = 1;

    for (int i = ini; i <= fin; i++) {
        if (cargaActual + v[i] <= capacidad) {
            cargaActual += v[i];
        }
        else {
            cargaActual = v[i];
            dronesUsados++;
        }
    }
    return dronesUsados <= d;
}

int reparto(const vector<int>& v, int ini, int fin, int d, int minimo, int maximo) {

    if (minimo == maximo) { // caso base: solo hay una entrega
        return minimo * 2 ;
    }
    else {
        int m = (minimo + maximo) / 2;
        
        if (comprobar(v, ini, fin, d, m)) {
            return reparto(v, ini, fin, d, minimo, m);
        }
        else {
            return reparto(v, ini, fin, d, m + 1, maximo);
        }
    }

}

bool resuelveCaso() {
    // leer los datos de la entrada
    int N, d; cin >> N >> d;

    if (N == 0 && d == 0) return false;

    vector<int> drones(N);
    int capacidad = 0;
    int maximo = 0;

    //Aprovechamos y calculamos la capacidad y el peso maximo 
    for (int i = 0; i < N; i++) {
        cin >> drones[i];
        maximo = max(maximo, drones[i]);
        capacidad += drones[i];
    }

    //resolver el problema
    

    int sol;

    if (d == 1) { // caso base: SOLO hay un dron para TODOS los repartos
        sol = capacidad * 2;
    }
    else if (N == d) { // caso base: hay un dron para cada reparto
        sol = maximo * 2;

    }
    else { 
        sol = reparto(drones, 0, N - 1, d, maximo, capacidad);
    }
    
    // escribir sol
    cout << sol << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_22.in");
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
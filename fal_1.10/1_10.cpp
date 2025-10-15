// Washington Morocho Lema
// FAL-E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta
/*
P = { (0 <= x <= N /\ p[x]) \/ (x=N) } 
racha (vector<int> const& partidos) -> con racha siendo : int max, veces, jugados; 
Q = { 0 <= x <= N /\ (Aj: 0<=j<x:¬p[j]) /\ P(x)}

Invariante = 0 <= x < N /\ (Aj: 0 <= j < x : ¬p[j])
Bucle = ¬P(x) <-> x != N /\ ¬p[x]
*/

struct racha {
    int max;
    int veces;
    int jugados;
};

racha partidosGanados(vector<int> const & partidos) {
    int maximo = 0, veces = 0, jugados = 0, ganados = 0;

    for (int i = 0; i < partidos.size(); i++) {
        int goles = partidos[i];

        if (goles > 0) {
            ganados++;
            jugados++;
            if (ganados > maximo) {
                maximo = ganados;
                veces = 1;
                jugados = 0;
            }
            else if (ganados == maximo) {
                veces++;
                jugados = 0;
            }
        }
        else {
            ganados = 0;
            jugados++;
        }
    }

    return { maximo, veces, jugados };
}

bool resuelveCaso() {
    int N = 0; cin >> N;

    if (!std::cin)
        return false;
    // leer los datos de la entrada
    vector<int> partidos(N);
    int valor = 0;

    for (int i = 0; i < N; i++) {
        cin >> valor;
        partidos[i] = valor;
    }
    
    //resolver el problema
    racha sol = partidosGanados(partidos);

    // escribir sol
    cout  << sol.max << " " << sol.veces << " " << sol.jugados << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_10.in");
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
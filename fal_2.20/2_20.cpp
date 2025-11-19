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

Funcion de cota: t(ini, fin) = fin - ini == v.size()

Ecuacion de recurrencia
    - Caso base: t(n) = C1 si n = 0 pertenece a O(1)
    - Caso recursivo: t(n) = 2T(n/2) + C2 si n > 0 pertenece a O(log n)

Coste: Siendo C1 y C2 costes constantes diferentes, pero que pertenecen al orden de O(1), el coste de recorrer una mitad(n/2) es O(log n) porque no siempre recorremos
todos los elementos. Como recorremos ambos lados del vector -> Total = 2 * O(log n) + O(1) = O(n)

*/

const string NP = "NP";

struct tSol {
    int partidos;
    bool presentado;
    int ronda;
};

tSol partido(const vector<string>& v, int ini, int fin, int rondas) {
    //cuando quedan 2 jugadores
    if (ini == fin - 2) {
        if (v[ini] == NP && v[ini + 1] == NP) { //Caso base: ningun jugador presentado, NO hay partido, pero pasa la ronda
            return {0,false,1};
        }
        else if(v[ini] == NP || v[ini + 1] == NP) { //Caso base: algun jugador presentado, NO hay partido, pero pasa la ronda
            return { 0,true,1 };
        }
        else {
            return{ 1,true,1 }; //Caso base: ambos jugadores presentados, SI hay partido y pasa la ronda
        }
    }
    else { // mas de 4 jugadores
        int m = (ini + fin) / 2;

        tSol iz = partido(v, ini, m, rondas);
        tSol dr = partido(v, m , fin, rondas);

        int rondaActual = iz.ronda + 1;
        tSol sol = { iz.partidos + dr.partidos, false, rondaActual };


        if (rondaActual <= rondas) {
            if (iz.presentado && dr.presentado) {  // los 2 jugadores se presentan
                sol.partidos = iz.partidos + dr.partidos + 1;
                sol.presentado = true;
                sol.ronda = rondaActual;
            }
            else if (iz.presentado || dr.presentado) { // alguien se presenta
                sol.partidos = iz.partidos + dr.partidos;
                sol.presentado = true;
                sol.ronda = rondaActual;
            }
            else { // nadie se presenta
                sol.partidos = iz.partidos + dr.partidos;
                sol.presentado = false;
                sol.ronda = rondaActual;
            }
        }

        return sol;
    }
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int N , r; cin >> N >> r;

    if (!std::cin) return false;

    vector<string> jugadores(N);

    for (int i = 0; i < N; i++) {
        cin >> jugadores[i];
    }

    //resolver el problema
    tSol sol = partido(jugadores, 0, N, r);

    // escribir sol
    cout << sol.partidos << "\n";
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_20.in");
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
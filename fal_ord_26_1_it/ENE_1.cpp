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

using tMatriz = vector<vector<int>>;

/*

1. (0,25 puntos) De&ne un predicado auxiliar numSubidas(d, a, b,V) que se evalúe a cierto si, y solo si,
entre las posiciones a y b (ambas incluidas) hay a lo sumo V subidas de valores.

pred  numSubidas(d, a, b,V) <-> # i: a <= i < b : d[i] < d[i+1] <= V 

2. (0,5 puntos) Utilizando el predicado auxiliar numSubidas, especi&ca una función que dados dos
vectores t y d de enteros no negativos (>= 0) del mismo tamaño, un valor T y otro V, devuelva
dos valores, un booleano que indique si existe un tramo de tensión sin demasiadas subidas de
volumen y un entero que, en caso de existir el tramo, sea la primera posición del mismo

pred tensionMin(v, a, b,T) -> sumT = { \Sum i : a <= i <= b : v[i] } && sumT >= T 

P: t.size() = N && d.size() = N && N > 0 && (\forall k : 0<= k < N : d[k] >= 0 && t[k] >= 0) && T >= 0 && V >= 0

func tramoValido(vector<int> : d, vector<int> : t, int : T, int V) return pair<bool,int> res

Q: res.first = { i,j: 0 <= i <= j < t.size() : numSubidas(d,i,j,V) && tensionMin(t,i,j,T) } &&
   res.second = { min i : 0 <= i < N : numSubidas(d,i,d.size() - 1,V) && tensionMin(t,i,t.size() - 1,T) && res.first } 
   // o bueno, el minimo indice i que cumple el primer booleano

4. (0,5 puntos) Escribe el invariante que permita demostrar la corrección de tu algoritmo y proporciona 
una función de cota.

Funcion de cota: t(i,comienzo) = 2*t.size() - i - comienzo // es el doble de t.size() porque comienzo e i pueden tomar como maximo ese valor

Invariante: I = 0 <= comienzo <= i <= t.size() &&
tensionTotal = ( \sum k : 0 <= k <= i : t[k]) &&
numSubidas = (#k : comienzo <= k < i : d[k] < d[k+1]))
posible = (tensionTotal >= T && numSubidas <= V)

5. (0,25 puntos) Indica el coste asintótico del algoritmo en el caso peor y justi&ca adecuadamente
tu respuesta.

El coste es lineal O(n), siendo n el numero de elementos de ambos vectores, debido a que tenemos que recorrer ambos vectores, con acceso constante O(1).

*/

pair<bool, int> tramoValido(const vector<int>& t, const vector<int>& d, int T, int V) {
    bool posible = false;
    int comienzo = 0, tensionTotal = 0, numSubidas = 0;

    for (int i = 0; i < t.size() && !posible; i++) {
        tensionTotal += t[i]; //sumamos la tension actual

        if (i > 0 && d[i - 1] < d[i]) {
            numSubidas++;
        }
        //deslizamos la ventana
        while (numSubidas > V && comienzo < i) {
            tensionTotal -= t[comienzo];
            if (d[comienzo] < d[comienzo + 1]) {//si era una subida la restamoas
                numSubidas--;
            }
            comienzo++;
        }

        if (numSubidas <= V && tensionTotal >= T) {
            posible = true;
        }
    }

    return { posible,comienzo };
}


bool resuelveCaso() {
    int n, T, V; cin >> n >> T >> V;

    if (!cin) return false;

    // leer los datos de la entrada

    vector<int> t(n), d(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    //resolver el problema
    pair<bool, int> sol = tramoValido(t, d, T, V);
  
    // escribir sol
    if (sol.first) {
        cout << "SI " << sol.second << "\n";
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
    std::ifstream in("ENE_1.in");
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
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

1. Define los siguientes predicados:

pred subida(v,p,q) -> { para todo i : p <= i < q - 1 : v[i] < v[i+1] }

pred valido(v,p,q,d) -> { para todo i,j : p <= i < j <= q : subida(v,i,j) -> (j - i <= d) }

2. Especifica una funcion:

P: v.size() > 0 && d > 0
func maxRecorrido(vector<int> : v, int : d) : int
Q: s = max i,j : 0 <= i < j < v.size() && valido(v,i,j,d) : j - i 

4. Coste: El coste en el caso peor es lineal O(N) debido a que tednriamos que recorrer todos los elementos del vector con acceso constante O(1)

5. Funcion de cota :  t(i) = v.size() - i

Invariante: I = 0 <= i < v.size() ^
maxRecorrido = (max p,q : 0 <= p < q <= i && valido(v,p,q,d) : q - p) ^
rec_actual = (max p : 0 <= p < i && valido(v, p, i, d) : i - p) ^
num_subidas = (max p : 0 <= p < i && subida(v, p, i) : i - p)

*/

int max_recorrido(const vector<int>& v, int d) {
    int maxRecorrido = 1, rec_actual = 1, num_subidas = 0;

    for (int i = 1; i < v.size(); i++) {
        if (v[i-1] < v[i]) { //si es una subida
            num_subidas++;
        }
        else {
            num_subidas = 0;
        }

        rec_actual++;

        if (num_subidas >= d) {
            num_subidas--;
            rec_actual = d; //quitamos algunos valores hasta quedarnos con d, porque ya es una subida que hace que superemos este limite
        }
        maxRecorrido = max(maxRecorrido, rec_actual);//nos quedamos con tramo maximo actual
    }

    return maxRecorrido;
}

bool resuelveCaso() {
    int n, d; cin >> n >> d;

    // leer los datos de la entrada

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
   
    //resolver el problema
    int sol = max_recorrido(v, d);

    // escribir sol
    cout << sol << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("EC_1.in");
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
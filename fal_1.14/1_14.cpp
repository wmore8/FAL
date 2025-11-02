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
pred atipico(v,dato) -> para todo i : 0 <= i < v.size() tal que  v[i] < dato;

P: v.size() > 0
func res_encuesta( v:vector<int> ) : pair<int,int>
Q: solucion = {(suma_datos = Sumatorio(v[i]) tal que 0 <= i < v.size() ^ !atipico( v, v[i]) ), (num_datos = #(!atipico( v, v[i])) tal que 0 <= i < v.size())}

Funcion de Cota: t(i) = v.size() - i;

Invariante : I -> 0 <= i < v.size() ^  No se que mas :( 

COSTE: El coste de la funcion es lineal respecto al numero de elementos del vector v. Cada acceso al vector es constante por lo tanto el coste es O(N)
*/

//funcion con constante para calcular cuantos elefantes han nacido -> O(1)


pair<long long int, int> res_encuesta(vector<int> const& v) {
    long long  int suma = 0, num_datos = v.size();
    long long int atipico = v[0]; int num_atipicos = 0;

    for (int i = 0; i < v.size(); i++) {
        suma += v[i];
        if (v[i] < atipico) { //primer caso de un dato atipico
            atipico = v[i];
            num_atipicos = 1;
        }
        else if (v[i] == atipico) {
            num_atipicos++;
        }
    }

    suma = suma - (atipico * num_atipicos);
    num_datos -= num_atipicos;

    return { suma, num_datos };
}

bool resuelveCaso() {
    int N = 0; cin >> N;

    // leer los datos de la entrada
    vector<int> encuesta(N);
    int dato = 0;

    for (int i = 0; i < N; i++) {
        cin >> dato;
        encuesta[i] = dato;
    }

    //resolver el problema
    pair<long long int, int> solucion = res_encuesta(encuesta);

    // escribir sol
    cout <<solucion.first << " " << solucion.second << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_14.in");
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
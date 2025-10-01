// Washington Morocho Lema
// FAL-E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
P: N >= 1
func cuantosMax(vector<int>: v) return pair<int,int> res
Q: res.first = {max i : 0 <= i < N : v[i]} &&
   res.second = {#i : 0 <= i < N : v[i] == res.first}

I = 0 <= i <= v.size() &&
mayor_puntuacion.first = (max k: 0<= k < i : v[k]) &&
mayor_puntuacion.second = (# k : 0 <= k < i : v[k] == mayor_puntuacion.first)

Coste: O(N) lineal, siendo N los elementos del vector. Es lineal debido a que leemos todos los valores del vector con acceso constante O(1)
*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num = 0; cin >> num;
    pair<int, int> mayor_puntuacion;
    //caso base, si solo hay 1 elemento entonces es la mayor puntuacion
    mayor_puntuacion = { num, 1 };

    while (num != 0) {
        cin >> num;
        if (num != 0) {
            if (num > mayor_puntuacion.first) {
                mayor_puntuacion = { num, 1 };
            }
            else if (num == mayor_puntuacion.first) {
                mayor_puntuacion.second++;
            }
        }
    }

    cout << mayor_puntuacion.first << " " << mayor_puntuacion.second << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_1.in");
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
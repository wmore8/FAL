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

pred torreValida (colores, altura) : return bool = colores.size() == N ^ para todo i : 0 <= i < N : colores[i] € {0, 1, 2}

P: N>= 1
func construir (colores : vector<int>, N : int, k : int): void 
Q: torreValida(colores, N)

Funcion de cota: t(N, k) = N - k

Ecuacion de recurrencia:
    - Caso base: t(k) = O(N) si k = N
    - Caso recursivo: t(k) = 3 * T(k + 1) + C0 si k < N
    Dentro del orden O(3^N) 

Coste: Debido a que tenemos 3 colores, y una altura determinada, el coste de la funcion seran todas las posibles combinaciones con los colores que tenemos
y la altura dada, dando un total de 3^N posibles combinaciones. Necesitamos comprobar todas las posibles combinaciones con accesos constantes O(1) asi que
el coste quedaria en -> O(3^N)

*/

string color(int color) {
    switch (color) {
    case 0: { return "azul "; } break;
    case 1: { return "rojo "; } break;
    case 2: { return "verde "; } break;
    default: { return ""; } break;
    }
}

bool esValida(vector<int>& colores, int N, int k) {

    if (k == 0 && colores[k] != 1) { //la primera pieza tiene que ser roja
        return false;
    }

    if (k > 0 && colores[k] == colores[k - 1] && colores[k] == 2) { // que no se repitan 2 piezas verdes seguidas
        return false;
    }

    return true;
}

void mostrar(const vector<int> & colores, int n) {
    for (int i = 0; i < n; i++) {
        cout << color(colores[i]);
    }
    cout << "\n";
}

void construir(vector<int> & colores ,int N, int k) {
    for (int i = 0; i < 3; i++) {
        colores.push_back(i);
        if (esValida(colores, N, k)) {
            if (k == N - 1) {
                mostrar(colores, N);
            }
            else {
                construir(colores, N, k + 1);
            }
        }
        colores.pop_back();
    }
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int N; cin >> N;

    if (N == 0) return false;

    //resolver el problema
    vector<int> colores;
    colores.push_back(1);

    if (N == 1) {
        mostrar(colores, N);
    }else{
        construir(colores, N, 1);
    }
    // escribir sol
    cout  << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("3_2.in");
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
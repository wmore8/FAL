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

void mostrar(const vector<int> & colores, int n) {
    for (int i = 0; i < n; i++) {
        cout << color(colores[i]);
    }
    cout << "\n";
}

bool esValida(const vector<int>& torre, const vector<int>& numColores, const vector<int>& colores, int N, int k) {

    if (colores[torre[k]] < 0) { // si nos quedamos sin piezas de un color -> es igual que decir azul, rojo o verde < 0 
        return false;
    }
    else if (numColores[2] > numColores[0]) {// si las piezas verdes superan no a las azules (verde > azul )
        return false;
    }
    else if (k == 0 && torre[k] != 1) { //la primera pieza tiene que ser roja
        return false;
    }
    else if (numColores[1] + N - (k+1) <= numColores[0] + numColores[2]) { //si podemos poner mas piezas rojas, y ademas no superamos la suma de azules y verdes
        return false;
    }
    else if (k > 0 && torre[k] == torre[k - 1] && torre[k] == 2) { // que no se repitan 2 piezas verdes seguidas
        return false;
    }

    return true;
}

void construir(vector<int> & torre, vector<int>& numColores, vector<int>& colores, bool &posible, int N, int k) {
    for (int i = 0; i < 3; i++) {
        torre.push_back(i);//probamos a usar un color
        --colores[i]; // lo cogemos y restamos la cantidad 
        ++numColores[i]; // añadimos uno para probar
        if (esValida(torre, numColores, colores, N, k)) {
            if (k == N - 1) {
                mostrar(torre, N);
                posible = true;
            }
            else {
                construir(torre, numColores, colores, posible, N, k + 1);
            }
        }
        //desmarcamos tras la llamda recursiva
        ++colores[i]; 
        --numColores[i];
        torre.pop_back();
    }
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int N; cin >> N;

    if (N == 0) return false;

    //resolver el problema
    vector<int> torre, colores(3), numColores(3);
    bool posible = false;

    cin >> colores[0] >> colores[1] >> colores[2];

    construir(torre, numColores, colores, posible, N, 0);

    // escribir sol
    if (!posible) { cout << "SIN SOLUCION\n"; }
    cout  << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("3_3.in");
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
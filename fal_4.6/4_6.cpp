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

Funcion de cota: t(n) = fin - ini + 1

Ecuacion de recurrencia:
    Caso base:          T(n) = C1 si n < 1
    Caso recursivo:     T(n) = 2* T(n/2) + C2 si n > 1

    Siendo C1 y C2 tiempos constantes distintos

Coste asintotico: Para resolver el problema necesitamos buscar por las 2 mitades del vector, haciendo que lo recorramos entero una unica vez con accesos constantes a cada
valor. El coste seria de : 2* O(N/2) + O(1) = O(N) lineal 

*/

struct tSol {
    bool correcto;
    int valor;
    int menores;
    int mayores;
};

tSol experimento(const vector<int>& v, int ini, int fin, int k) {

    if (ini == fin) { // caso base: solo hay 1 elemento
        if (v[ini] < k) {
            return { true, v[fin], v[ini], 0};
        }
        else {
            return { true, -v[fin], 0, v[ini]};
        }
    }
    /*
    else if (ini == fin - 1) {// caso base: solo hay 2 elementos
        if (v[ini] < k && v[fin] >= k) { 
            bool correcto = v[ini] % k > v[fin] % k;
            return { correcto, v[ini] - v[fin], v[ini], v[fin] };
        }
        else if (v[ini] < k &&  v[fin] < k) { // en estos 2 casos no cumple la condicion
            return { false, v[fin] + v[ini], v[ini] + v[fin], 0 };
        }
        else if (v[ini] >= k && v[fin] >= k) {
            return { false, v[fin] + v[ini], 0,  v[ini] + v[fin] };
        }
        else {
            int max_valor = max(v[ini], v[fin]);
            int min_valor = min(v[ini], v[fin]);
            return { false, min_valor - max_valor, min_valor, max(v[ini] ,v[fin]) };
        }
    }
    */
    else {
        int m = (ini + fin) / 2;
        tSol iz = experimento(v, ini, m, k);
        tSol dr = experimento(v, m + 1, fin, k);

        int menores = iz.menores + dr.menores;
        int mayores = dr.mayores + iz.mayores;

        bool correcto = (iz.menores % k > dr.mayores % k) && (iz.correcto || dr.correcto);

        return { correcto, menores - mayores, menores, mayores };
    }

}

bool resuelveCaso() {
    int N, k; cin >> N >> k;

    if (!cin) return false;
    // leer los datos de la entrada
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    //resolver el problema
    
    tSol sol = experimento(v, 0, N - 1, k);

    // escribir sol
    if (sol.correcto) {
        cout << sol.valor;
    }
    else {
        cout << "ERROR";

    }
    cout  << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("4_6.in");
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
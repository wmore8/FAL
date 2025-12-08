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

pred variacionValida(palabra, letras, n): bool = |palabra| = n ^ para todo i € [0, n-1] : palabra[i] € letras

pred letrasConjunto(m): vector<char> = {'a', 'b', ..., 'a'+m-1}  // las m primeras letras del alfabeto

pred esValido(p) = no contiene ninguna letra repetida -> #l_i = 1 : para todo li : cada letra de la palabra p

P: 1 <= n <= m ^ m <= 26
func maneras(palabra: vector<char>, letras: vector<char>, m: int, n: int, k: int): void
Q: torreValida(colores, N)

Funcion de cota: t(N, k) = N - k

Ecuacion de recurrencia:
    - Caso base: t(k,N) = O(N) si k = N
    - Caso recursivo: t(k,N) = m * T(k + 1) + C0 si k < N
    Dentro del orden O(3^N) 

Coste: Debido a que tenemos m letras, y una longitud n determinada, el coste de la funcion seran todas las posibles combinaciones con las letras que tenemos
y la longitud dada, dando un total de M^N posibles combinaciones. Necesitamos comprobar todas las posibles combinaciones con accesos constantes O(1) asi que
el coste quedaria en -> O(M^N)

*/

using Juguetes = vector<int>;

bool esValido(int n,int m, int k, vector<bool>& asignados, const vector<Juguetes>& grado, int maxS) {
    return true;
}

void maneras(int n, int m, int k, vector<bool>& asignados, const vector<Juguetes>& grado,int actual, int& maxS) {
    for (int j = 0; j < m; j++) {
        if (!asignados[j]) {
            asignados[j] = true;
            actual += grado[k][j];

            if (k == n - 1) {
                if (actual > maxS) {
                    maxS = actual;
                }
            }
            else {
                maneras(n, m, k + 1, asignados, grado, actual, maxS);
            }
            //desmarcamos
            asignados[j] = false;
            actual -= grado[k][j];
        }
    }
}



bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n; cin >> m >> n;

    if (!std::cin) return false;

    //resolver el problema
    vector<bool> asignados(m,false);
    vector<Juguetes> grado(n, (Juguetes(m, 0)));
    int actual = 0, maxSatisfaccion = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grado[i][j];
        }
    }

    maneras(n, m, 0 ,asignados, grado,actual, maxSatisfaccion);

    // escribir sol
    cout << maxSatisfaccion << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("3_10.in");
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
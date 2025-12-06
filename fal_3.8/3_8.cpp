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

bool esValido(const vector<string>& juguetes, int n, int k, vector<int>& reparto, bool posible) {

    if (k % 2 == 1) {//si es el segundo juguete
        if (reparto[k - 1] >= reparto[k]) {
            return false;
        }

        if (juguetes[reparto[k - 1]] == juguetes[reparto[k]]) {
            return false;
        }
    }
  
    return true;
}

void mostrar(vector<int>& reparto, int n) {
    for (int i = 0; i < 2 * n; i++) {
        cout << reparto[i] << " ";
    }
    cout << "\n";
}


void maneras(const vector<string>& juguetes, int n, int k, vector<int>& reparto, bool &posible) {
    for (int j = 0; j < juguetes.size(); j++) {

        reparto.push_back(j);

        if (k == 2 * n - 1) {
            if (esValido(juguetes, n, k, reparto, posible)) {
                mostrar(reparto, n);
                posible = true;
            }
        }
        else {
            if (esValido(juguetes, n, k, reparto, posible)) {
                maneras(juguetes, n, k + 1, reparto, posible);
            }
        }

        //desmarcamos
        reparto.pop_back();
    }
}



bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n; cin >> m >> n;

    if (!std::cin) return false;

    //resolver el problema
    vector<string> jueguetes(m);
    vector<int> reparto;
    bool posible = false;

    for (int i = 0; i < m; i++) {
        cin >> jueguetes[i];
    }

    maneras(jueguetes, n, 0, reparto, posible);

    // escribir sol
    if (!posible) {
        cout << "SIN SOLUCION\n";
    }

    cout  << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("3_8.in");
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
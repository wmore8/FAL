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

variacionValida(palabra, letras, n): bool = |palabra| = n ^ para todo i € [0, n-1] : palabra[i] € letras

letrasConjunto(m): vector<char> = {'a', 'b', ..., 'a'+m-1}  // las m primeras letras del alfabeto

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

void mostrar(const vector<char>& palabra, int n) {
    for (int i = 0; i < n; i++) {
        cout << palabra[i];
    }
    cout << "\n";
}


void maneras(vector<char> &palabra, const vector<char>& letras,int m, int n, int k) {
    for (int i = 0; i < m; i++) {
        palabra.push_back(letras[i]);
        if (k == n - 1) {
            mostrar(palabra, n);
        }
        else {
            maneras(palabra, letras, m, n, k + 1);
        }

        //desmarcamos
        palabra.pop_back();
    }
}


bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n; cin >> m >> n;

    if (!std::cin) return false;

    //resolver el problema
    vector<char> palabras,letras(m);
    char aux = 'a';

    for (int i = 0; i < m; i++) {
        letras[i] = aux;
        aux++;
    }

    maneras(palabras, letras, m, n, 0);

    // escribir sol

    cout  << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("3_4.in");
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
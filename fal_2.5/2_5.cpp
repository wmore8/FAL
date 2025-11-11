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

pred sumaDigitos(int n) -> { (n : 0 <= n <  2^32 - 1) tal que (cont : 0 <= cont <= longitud(n) : SUMATORIO (n % (10 * cont) )) }

P: { 0 <= |v| < 10000 ^ x : 0 <= x < 2^32 - 1}
fun sumaCifras( v: vector<int>, x : int) return int suma
Q: { suma para todo x == sumaDigitos(v[i]) ^ 0 <= i < |v| }

Funcion de Cota: t(n) = n

Ecuacion de recurrencia:
    - Caso base: T(n) = O(1) si n < 10
    - Caso recursivo: T(n) = O(1) + t(n/10) si n > 10

Coste: O(log10 n) logaritmico en base 10

*/

//recursion final: la suma se calcula antes de la llamada recursiva
int sumaDigitos_final(int n, int suma) {
    if (n == 0) {
        return suma;
    }

    return sumaDigitos_final(n/10, suma + (n%10));
}

//recursion no final: la suma se calcula despues de la llamada recursiva
int sumaDigitos_no_final(int n) {
    if (n%10 == n) {
        return n;
    }

    int suma = (n % 10) + sumaDigitos_no_final(n / 10);

    return suma;
}

bool resuelveCaso() {
    int N = 0, x = 0; cin >> N >> x;

    // leer los datos de la entrada
    vector<int> digitos(N);
    int valor = 0;
    for (int i = 0; i < N; i++) {
        cin >> valor;
        digitos[i] = valor;
        //se podria hacer sin vector, aprovechando tambien este bucle para calcular la solucion e imprimirla directamente
    }

    //resolver el problema
    int suma = sumaDigitos_final(x, 0);

    // escribir sol
    for (int i = 0; i < N; i++) {
        int aux = sumaDigitos_no_final(digitos[i]);

        if (aux == suma) {
            cout << digitos[i] << " ";
        }
    }

    cout << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_5.in");
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
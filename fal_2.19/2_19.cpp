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

Funcion de cota: t(n) = n == v.size()

Ecuacion de recurrencia
    - Caso base: t(n) = C1 si n % 2 == 1 pertenece a O(1)
    - Caso recursivo: t(n) = T(n/2) + C2 si n % 2 == 0 pertenece a O(log n)

Coste: Siendo C1 y C2 costes constantes diferentes, pero que pertenecen al orden de O(1), el coste de recorrer una mitad(n/2) es O(log n) porque no siempre recorremos
todos los elementos -> Total = O(log n) + O(1) = O(log n)

*/

int buscarImpar(const vector<int>& v, int ini, int fin) {

    if (ini == fin) { 
        return v[ini]; //recorrido el vector o subvector por completo
    }
    else {
        int m = (ini + fin) / 2;
        
        if (v[m] % 2 == 1) {
            return v[m];
        }
        else {
            int parEsperado = v[ini] + 2 * (m - ini);
            if (v[m] != parEsperado) { 
                return buscarImpar(v, ini, m); //si el par esperado no coincide con la mitad, exploramos por la izquierda
            }
            else {
                return buscarImpar(v, m + 1, fin);//si el par esperado coincide con la mitad, exploramos por la derecha
            }
        }
    }
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int N; cin >> N;

    if (N == 0) return false;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
  
    //resolver el problema
    int impar = buscarImpar(v, 0, N - 1);

    // escribir sol
    cout << impar << "\n";
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_19.in");
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
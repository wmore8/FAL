// Washington Morocho Lema
// FAL-E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int D=0, N = 0; cin >> D >> N;

    if (!std::cin)
        return false;

    vector<int> alturas(N); //inicializamos el vector de los valores

    for (int i = 0; i < N; i++) {
        int valor; cin >> valor;
        alturas[i] = valor;
    }

    // escribir sol
    bool apto = true;

    int altura_anterior = alturas[0], desnivel = 0;

    for (int i = 1; i < N && apto; i++) {
        if (altura_anterior < alturas[i]) { // si el desnivel es creciente
            desnivel += alturas[i] - altura_anterior;
        }
        else { // si el desnivel es decreciente o se mantiene igual
            desnivel = 0;
        }


        if (desnivel > D) {
            apto = false;
        }

        altura_anterior = alturas[i];
    }
   
    if (apto) {
        cout << "APTA\n";
    }
    else {
        cout << "NO APTA\n";
    }


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_5.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
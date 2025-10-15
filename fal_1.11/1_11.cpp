// Washington Morocho Lema
// FAL-E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta

int descenso(vector<int> const& alturas) {
    int distancia = 1 , descenso = 0;

    if (!alturas.empty()) {
        int comienzo = alturas[0];

        for (int i = 1; i < alturas.size(); i++) {

            if (comienzo >= alturas[i]) {
                distancia++;

                if (distancia > descenso) {
                    descenso = distancia;
                }
                if (comienzo == alturas[i]) {
                    distancia = 1;
                }
            }
            else {
                comienzo = alturas[i];
                distancia = 1;
            }

        }

        if (distancia > descenso) {
            descenso = distancia;
        }
    }

    return descenso;
}

void resuelveCaso() {
    // leer los datos de la entrada
    int N = 0; cin >> N;

    vector<int> alturas(N);
    int altura = 0;

    for (int i = 0; i < N; i++) {
        cin >> altura;
        alturas[i] = altura;
    }

    cout << descenso(alturas) << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_11.in");
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
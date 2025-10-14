// Washington Morocho Lema
// FAL-E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta

pair<int, int> rescate(vector<int> const& edificios, int t) {
    int comienzo = 0, final = 0, maxDistancia = 0, contador = 0;

    for (int i = 0; i < edificios.size(); i++) {
        if (edificios[i] > t) {
            contador++;
        }
        else {
            if (contador > maxDistancia) {
                maxDistancia = contador;
                comienzo = i - maxDistancia;
                final = i - 1;
            }
            contador = 0;
        }
    }

    if (contador > maxDistancia){
        maxDistancia = contador;
        comienzo = edificios.size() - maxDistancia;
        final = edificios.size() - 1;
    }

   
    return { comienzo, final };
}

void resuelveCaso() {
    // leer los datos de la entrada
    int N = 0, t = 0; cin >> N >> t;

    vector<int> edificios(N);
    int altura = 0;

    for (int i = 0; i < N; i++) {
        cin >> altura;
        edificios[i] = altura;
    }

    auto sol = rescate(edificios, t);


    cout << sol.first << " " << sol.second << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_8.in");
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
// Washington Morocho Lema
// FAL-E51

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N = 0; cin >> N;

    if (N != 0) {
        vector<int> valores; //inicializamos el vector de los valores
        int valor = 0;
        for (int i = 0; i < N; i++) {
            cin >> valor;
            valores.push_back(valor*2);
        }

        for (int i = 0; i < N; i++) {
            cout << valores[i] << " ";
        }

    }
    cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("0_2.in");
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

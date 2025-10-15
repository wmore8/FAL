// Washington Morocho Lema
// FAL-E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta


vector<long long int> eliminarErrores(vector< long long int> sensores, long long int error) {
    int posicion = 0;
    for (int i = 0; i < sensores.size(); i++) {
        if (sensores[i] != error) {
            sensores[posicion] = sensores[i];
            posicion++;
        }
    }

    sensores.resize(posicion);
    return sensores;
}

void resuelveCaso() {
    // leer los datos de la entrada
    int N = 0;
    long long int error = 0;
    cin >> N >> error;

    vector< long long int> sensores(N);
    long long int valor = 0;

    for (int i = 0; i < N; i++) {
        cin >> valor;
        sensores[i] = valor;
    }

    sensores = eliminarErrores(sensores, error);

    cout << sensores.size() << "\n";

    for (int i = 0; i < sensores.size(); i++) {
        cout << sensores[i] << " ";

    }
    cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_12.in");
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
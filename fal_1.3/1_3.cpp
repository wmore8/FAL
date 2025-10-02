// Washington Morocho Lema
// FAL-E51

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

string primera_palabra(const vector<string>& lista) {
    string palabra = lista[0];

    for (int i = 0; i < lista.size(); i++) {
        if (palabra > lista[i]) {
            palabra = lista[i];
        }
    }
    return palabra;
}

// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N = 0; cin >> N;

    vector<string> palabras;
    string palabra;

    for (int i = 0; i < N; i++) {
        cin >> palabra;
        palabras.push_back(palabra);
    }
   
    cout << primera_palabra(palabras) << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_3.in");
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
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
    int N = 0, C = 0; cin >> N >> C;

    if (N == 0 && C == 0)
        return false;
    // leer los datos de la entrada
    vector<int> terreno(N);

    for (int i = 0; i < N; i++) {
        int valor; cin >> valor;
        terreno[i] = valor;
    }
    //resolver el problema
    bool construir = false;
    int llano = 0, ultimo_valor = terreno[0];
  
    for (int i = 0; i < N && !construir; i++) {
        if (ultimo_valor == terreno[i]) {
            llano++;
        }
        else if (ultimo_valor < terreno[i] && llano >= C) {
            llano = 0;
            construir = true;
        }
        else {
            llano = 1;
        }

        ultimo_valor = terreno[i];
    }

    // escribir sol
    if (construir) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_4.in");
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
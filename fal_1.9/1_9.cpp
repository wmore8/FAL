// Washington Morocho Lema
// FAL-E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta

int accidentes(vector<int> const& carretera) {
    auto ordenado = carretera;
    sort(ordenado.begin(), ordenado.end()); //lo ordenamos de menor a mayor
    int contador = 1, maxDistancia = 0;
    int km_anterior = ordenado[0];
    int kilometros = km_anterior;

    for (int i = 1; i < carretera.size(); i++) {
        int km_actual = ordenado[i];

        if (km_actual == km_anterior) {
            contador++;
            
        }
        else {
            if (contador > maxDistancia) {
                maxDistancia = contador;
                kilometros = km_anterior;
            }
            contador = 1;
        }
        km_anterior = km_actual;
    }

    if (contador > maxDistancia) {
        kilometros = km_anterior;
    }

    return kilometros;
}

bool resuelveCaso() {
    int N = 0; cin >> N;

    if (N == -1)
        return false;
    // leer los datos de la entrada
    vector<int> carretera(N);

    for (int i = 0; i < N; i++) {
        int valor; cin >> valor;
        carretera[i] = valor;
    }
    //resolver el problema


    // escribir sol
    cout << accidentes(carretera) << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_9.in");
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
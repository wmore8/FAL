// Washington Morocho Lema
// FAL-E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta

vector<int> beneficios(vector<long int>  const& ventas, int primero) {

    vector<int> benef;
    long int maxVenta = ventas[0];
    for (int i = 1; i < ventas.size(); i++) {
        if (maxVenta < ventas[i]) {
            maxVenta = ventas[i];
            benef.push_back(primero + i);
        }
    }

    return benef;
}

void resuelveCaso() {
    // leer los datos de la entrada
    int primero = 0, ultimo = 0; cin >> primero >> ultimo;
    
    int N = ultimo - primero + 1;
    long int venta = 0;
    vector<long int> ventas(N);

    for (int i = 0; i < N; i++) {
        cin >> venta;
        ventas[i] = venta;
    }

    auto sol = beneficios(ventas, primero);

    for (int fecha : sol) {
        cout << fecha << " ";
    }

    cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_6.in");
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
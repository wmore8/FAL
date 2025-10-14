// Washington Morocho Lema
// FAL-E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta

bool zona_peligro(vector<int> datos, int t) {
    bool peligro = true;
    int dato_anterior = datos[0];
    int longitud = 1;

    for (int i = 1; i < datos.size() && peligro; i++) {
        if (dato_anterior == datos[i]) {
            longitud++;
        }
        else if(dato_anterior > datos[i] && longitud >= t) {
            longitud = 0;
            peligro = false;
        }
        else {
            longitud = 1;
        }
        dato_anterior = datos[i];
    }

    return peligro;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int N = 0, t = 0; cin >> N >> t;

    if (N == 0 && t == 0)
        return false;

    vector<int> datos(N); //inicializamos el vector de los valores

    for (int i = 0; i < N; i++) {
        int valor; cin >> valor;
        datos[i] = valor;
    }

    // escribir sol
    if (zona_peligro(datos, t)) {
        cout << "NO\n";
    }
    else {
        cout << "SI\n";
    }

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_7.in");
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
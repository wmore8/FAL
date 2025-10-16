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

/*


El coste de leer los datos es lineal en funcion del tamaño de los elementos (N) y el coste de resolver el problema tambien es lineal en funcion de las M 
consultas que se realicen, ya que primero iteramos N veces para tener listas todas las sumas posibles y luego las podemos consultar de forma constante
COSTE: O(N + M)
*/

//funcion con constante para calcular cuantos elefantes han nacido -> O(1)
long long int naciemientos(vector<long long int> const& sumas, int P, int a, int b) {
    int indiceA = a - P;
    int indiceB = b - P + 1;

    long long int total = sumas[indiceB] - sumas[indiceA];

    return total;
}

bool resuelveCaso() {
    int P = 0, U = 0; cin >> P >> U;

    if (P == 0 && U == 0)
        return false;
    // leer los datos de la entrada
    int N = U - P + 1;
    vector<int> reserva(N);
    int valor = 0;

    for (int i = 0; i < N; i++) {
        cin >> valor;
        reserva[i] = valor;
    }

    //resolver el problema
    vector <long long int> sumas(N + 1, 0); 
    for (int i = 0; i < N; i++) {
        sumas[i + 1] = sumas[i] + reserva[i];
    }

    int m = 0, a = 0, b = 0;

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        
        cout << naciemientos(sumas, P, a, b) << "\n";
    }

    // escribir sol
    cout  << "---\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_13.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
// Washington Morocho Lema
// FAL-E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <climits>

using namespace std;

/*

    pred binario(n): string = representacion en base 2 de n

    P: n ≥ 0
    func conversor(n: int): string
    Q: resultado = binario(n)

    Función de Cota: t(n) = n

    Ecuacion de recurrencia:
      - Caso base: T(n) = O(1) si n ≤ 1
      - Caso recursivo: T(n) = O(1) + T(n/2) si n > 1

    Coste: O(log n) -> logaritmico

*/

string conversor(int x) {

    if (x == 0) {
        return "0";
    }
    else if(x == 1){
        return "1";
    }

    string binario = conversor(x / 2);

    binario.push_back((x % 2 == 0 ? '0' : '1'));
    
    return binario;
}
    

bool resuelveCaso() {
    int n = 0; cin >> n;
    // leer los datos de la entrada

    if (!std::cin)
        return false;

    //resolver el problema
    string binario = conversor(n);

    // escribir sol
    cout << binario  << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_2.in");
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
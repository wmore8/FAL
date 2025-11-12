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

    pred sumDivisible(n): bool = d_i: d_i = todos los digitos de n tal que SUMATORIO(d_i) % longitud(n) = 0

    P: n ≥ 0
    func esSumDivisible(n: int): bool
    Q: resultado = true si sumDivisible(n)

    Función de Cota: t(n) = n

    Ecuacion de recurrencia:
      - Caso base: T(n) = O(1) si n ≤ 10
      - Caso recursivo: T(n) = O(1) + T(n/10) si n > 10

    Coste: O(log10 n) -> logaritmico en base 10 (porque multiplicamos y dividimos por 10 en cada iteracion recursiva)

*/

struct tSol {
    int cont;
    int suma;
    bool esSumD;
};

//funcion recursiva final
tSol sumDivisible(int n){
    if (n < 10) {
        return { 1, n, (n % 1 == 0)};
    }

    int digito_actual = n % 10;
   tSol sumD = sumDivisible(n / 10);
   
    return { sumD.cont + 1,  sumD.suma + digito_actual, ((sumD.suma + digito_actual) % (sumD.cont + 1) == 0) && sumD.esSumD};
}

bool resuelveCaso() {
    int n = 0; cin >> n;
    // leer los datos de la entrada

    if (n == 0) return false;

    //resolver el problema
    tSol sol = sumDivisible(n);

    // escribir sol
    if (sol.esSumD) {
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
    std::ifstream in("2_8.in");
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
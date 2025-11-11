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

pred complementario(n) -> { comp : comp = | 9 - d_i| tal que d_i : cada digito de n } 
pred inverso(n) -> {numero formado por los digitos de n en orden inverso}

P: 0 <= n < 1.000.000.000
Fun calculo(n :int) return int comp
Q: { comp = complementario(n) ^ inverso(comp) }

Funcion de Cota: t(n) = n

Ecuacion de recurrencia:
    - Caso base: T(n) = O(1) si n < 10
    - Caso recursivo: T(n) = O(1) + t(n/10) si n > 10

Coste: O(log10 n) logaritmico en base 10

*/
/*
//CODIGO FUNCIONAL QUE DA WRONG ANSWER


int complementario(int n) {
    if (n < 10) {
        return 9 - n;
    }

    int digito_comp = 9 - (n % 10);
    int comp = complementario(n / 10);

    return comp * 10 + digito_comp;
}

int complementarioInverso(int n, int mult) {
    if (n < 10) {
        return 9 - n; // creo que tengo que multiplicar por mult y ya
    }

    int digito_comp = 9 - (n % 10);
    int comp = complementarioInverso(n / 10, mult * 10);

    return comp + digito_comp * mult;
}

bool resuelveCaso() {
    int n = 0; cin >> n;

    // leer los datos de la entrada

    //resolver el problema
    int compInverso = complementarioInverso(n, 10);
    int comp = complementario(n);

    // escribir sol
    cout << comp << " " << compInverso << "\n";

    return true;
}
*/
int complementario(int n) {
    //Caso Base
    if (n < 10) {
        return 9 - n;
    }
    else {
        int c = n % 10;
        int r = complementario(n / 10);
        return r * 10 + 9 - c;
    }
}
struct tsolI {
    int s, d;
};
tsolI complemnetarioInverso(int n) {
    //Caso Base
    if (n < 10) {
        return { 9 - n, 10 };
    }
    else {
        int c = 9 - n % 10;
        tsolI r = complemnetarioInverso(n / 10);
        return { c * r.d + r.s, r.d * 10 };
    }
}
void resuelveCaso() {
    int n, d = 1;
    cin >> n;
    cout << complementario(n) << " " << complemnetarioInverso(n).s << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_6.in");
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
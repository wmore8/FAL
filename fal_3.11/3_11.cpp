// Washington Morocho Lema
// FAL-E51

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <climits>
#include <string>

using namespace std;

/*

pred costeMinimo(m,p,k,super,actual,nunmProd, costeMin,posible) = min(costeMin) tal que  i: 0 <= i <= 3*m ^ #numprod[i] <= 3 ^ costeMin = SUM(super[i][k])

P: 0 < m <= 20 ^ 0 < p <= 3*m
func maneras(m: int, p : int, k:int, costeActual : int, costeMin: int, posible: bool ): void
Q: costeMinimo(m,p,k,super,actual,nunmProd, costeMin,posible)

Funcion de cota: t(p, k) = p - k -> siendo k el producto asignado actual

Ecuacion de recurrencia:
    - Caso base: t(k,p) = O(1) si k = p
    - Caso recursivo: t(k, p) = m * T(k + 1, p) + C0 si k < p

Coste:  En el peor caso, el algoritmo explora todas las posibles asignaciones de p productos a m supermercados con la restricción de que cada supermercado 
tiene como máximo 3 productos. Esto da una complejidad de O(m^p) en el peor caso. Sin embargo, debido a la restricción p ≤ 3*m, en la práctica el coste está 
acotado.


*/

using Productos = vector<int>;

void maneras(int m, int p, int k ,Productos & numProd, const vector<Productos>& super,int actual, int& minC, bool & posible) {
     
    for (int i = 0; i < m; i++) {
        numProd[i]++;
        actual += super[i][k];

        if (numProd[i] <= 3) {

            if (k == p - 1) {
                if (actual < minC) {
                    minC = actual;
                    posible = true;
                }
            }
            else {
                maneras(m, p, k + 1, numProd, super, actual, minC, posible);
            }
        }
        //desmarcamos
        numProd[i]--;
        actual -= super[i][k];
           
    }
    
}



bool resuelveCaso() {
    // leer los datos de la entrada
    int m, p; cin >> m >> p;

    //resolver el problema
    vector<Productos> super(m, (Productos(p, 0)));
    Productos numProd(m, 0);
    int actual = 0,cont = 0, minCoste = INT_MAX;
    bool posible = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cin >> super[i][j];
        }
    }

    maneras(m, p, 0, numProd, super, actual, minCoste, posible);

    // escribir sol
    if (posible) {
        cout << minCoste << "\n";
    }
    else {
        cout << "Sin solucion factible\n";
    }

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("3_11.in");
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
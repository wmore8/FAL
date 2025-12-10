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
#include <chrono>

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

Coste: En el peor caso, el algoritmo explora todas las posibles asignaciones de p productos a m supermercados con la restricción de que cada supermercado 
tiene como máximo 3 productos. Esto da una complejidad de O(m^p) en el peor caso. Sin embargo, debido a la restricción p ≤ 3*m, en la práctica el coste está 
acotado.

*/

struct Objeto {
    int precio;
    int superficie;
};

float estimacion(const vector<Objeto>& objetos, int n, int k, int p, int sActual, int pActual) {
    int pRestante = p - pActual, j = k + 1;
    int estimacion = sActual;
    while (j < n && objetos[j].precio <= pRestante) {
        pRestante -= objetos[j].precio;
        estimacion += objetos[j].superficie;
        ++j;
    }

    if (j < n) {
        estimacion = estimacion + ((float) pRestante * objetos[j].superficie / objetos[j].precio);
    }
    return estimacion;
}

void maneras(const vector<Objeto>& objetos, int n, int k, int p, int sActual, int pActual, int &maxSup) {
    // decidimos elegir el objeto
    sActual += objetos[k].superficie;
    pActual += objetos[k].precio;

    if (pActual <= p) { // si no nos excedemos del presupuesto 
        if (k == n - 1) {
            if (sActual > maxSup) {
                maxSup = sActual;
            }
        }
        else {
            maneras(objetos, n, k + 1, p, sActual, pActual, maxSup);
            /*
            float est = estimacion(objetos, n, k, p, sActual, pActual);
            if (est > maxSup) {
                maneras(objetos, n, k + 1, p, sActual, pActual, maxSup);

            }
            */
        }
    }
    //desmarcamos
    sActual -= objetos[k].superficie;
    pActual -= objetos[k].precio;

    // decidimos NO elegir el objeto
    if (k == n - 1) {
        if (sActual > maxSup) {
            maxSup = sActual;
        }
    }
    else { //necesitamos estimar para saber si podamos o no
        float est = estimacion(objetos, n, k, p, sActual, pActual);
        if (est > maxSup) {
            maneras(objetos, n, k + 1, p, sActual, pActual, maxSup);
        }
    }
}

bool const operator <(const Objeto& a, const Objeto& b) {
    return (float) a.superficie / a.precio > (float) b.superficie / b.precio;
}

bool resuelveCaso() {
    // leer los datos de la entrada

    int N, P; cin >> N >> P;

    if (!cin) return false;

    vector<Objeto> objetos(N);

    for (int i = 0; i < N; i++) {
        cin >> objetos[i].precio >> objetos[i].superficie;
    }

    //resolver el problema
    int maxSuperficie = 0;
    //ordenamos los objetos de mayor a menor segun su densidad de superficie/precio
    sort(objetos.begin(), objetos.end());

    maneras(objetos, N, 0, P, 0, 0, maxSuperficie);
    
    // escribir sol
    cout << maxSuperficie << "\n";
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("3_13.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    /*
    auto start = std::chrono::steady_clock::now();

    while (resuelveCaso());

    auto end = std::chrono::steady_clock::now();

    auto diff = end - start;


    Source - https://stackoverflow.com/a
    //Posted by Sajal, modified by community. See post 'Timeline' for change history
    //Retrieved 2025-12-09, License - CC BY-SA 4.0

    std::cout << std::chrono::duration<double, std::milli>(diff).count() << " ms" << std::endl;
    */
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}


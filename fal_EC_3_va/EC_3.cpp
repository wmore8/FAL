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

using tMatriz = vector<vector<int>>;

/*

// 1. Explica claramente los marcadores que has utilizado

Para poder resolver el ejercicio se han utilizado los siguientes marcardores:
    - teclaAnterior: Para saber la tecla anterior pulsada
    - castigo: la suma de los castigos si la tecla T[i][j] es negativa
    - recompensaActual: las recompensas que obtenemos al pulsar las rteclas anteriores hasta la actual
    - maxRecompensa: la maxima recompensa obtenida aplicando las restricciones
    - posible: si es posible resolver el problema
    - maxValor: estimacion del maximo valor posible obtenido por una sola tecla

// 2. Describe el espacio de soluciones

El espacio de soluciones entra dentro de una arbol de anchura n, siendo n el numero de teclas, y altura o profundidad m, siendo m las posibles combinaciones.
Esto nos deja con un espacio de soluciones acotado entre n^m posibles soluciones.

// 3. Explica la poda de optimalidad
    - Una poda de optimalidad sería calcular la mayor recompensa posible que las teclas pueden ofrecer (maxValor), para posteriormente compararla con la solucion 
    maxima obtenida y ver si merece la pena seguir buscando por esa rama, sabiendo cuanto mas podemos obtener como maximo si no podamos.

*/

bool esValido(int castigo, int C) {
    return abs(castigo) <= C;
}

void maneras(const tMatriz& T, int k, int n, int m, int c, int tecla_anterior, int castigo, int recomplensaActual, int& maxRecompensa, bool& posible, int& maxValor) {


    for (int i = 0; i < n; i++) {
        if (k > 0) { // Necesitamos al menos avanzar una tecla
            if (T[tecla_anterior][i] >= 0) { // si es positivo, es un premio
                recomplensaActual += T[tecla_anterior][i];
            }
            else { // si es negativo, es un castig
                castigo += T[tecla_anterior][i];
            }
        }

        //PODA 1: por viabilidad, si la solucion actual es valida
        if (esValido(castigo, c)) {
            if (k == m - 1) {
                if (recomplensaActual > maxRecompensa) {
                    maxRecompensa = recomplensaActual;
                    posible = true;
                }
            }
            else {
                int pasos_restantes = m - 1 - k; // la secuencia actual menos lo que llevamos avanzado
                int estimacion = recomplensaActual + (pasos_restantes * maxValor);
                //PODA 2: por optimalidad, si la solucion actual es mejor a la ya obtenida seguimos iterando, si no, podamos
                if (estimacion > maxRecompensa) {
                    maneras(T, k + 1, n, m, c, i, castigo, recomplensaActual, maxRecompensa, posible, maxValor);
                }
            }
        }

        //desmarcamos
        if (k > 0) { // Necesitamos al menos avanzar una tecla
            if (T[tecla_anterior][i] >= 0) {
                recomplensaActual -= T[tecla_anterior][i];
            }
            else {
                castigo -= T[tecla_anterior][i];
            }
        }
    }

}

void resolver(const tMatriz &M, int n, int m, int c, int &maxRecompensa, bool& posible, int& maxValor) {
    maxRecompensa = -1;
    posible = false;

    maneras(M, 0, n, m, c, 0, 0, 0, maxRecompensa, posible, maxValor);
}

bool resuelveCaso() {
    int n, m, c; cin >> n >> m >> c;

    // leer los datos de la entrada

    tMatriz teclado(n, vector<int>(n));
    int maxvalor = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> teclado[i][j];
            maxvalor = max(maxvalor, teclado[i][j]);
        }
    }
   
    //resolver el problema
    bool posible;
    int maxRecompensa;

    resolver(teclado, n, m, c, maxRecompensa, posible, maxvalor);

    // escribir sol

    if (posible) {
        cout << maxRecompensa << "\n";
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
    std::ifstream in("EC_3.in");
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
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

1. Define el espacio de soluciones e indica cómo es el árbol de exploración.

Teniendo en cuenta que hay m salas y n canciones, y que en cada sala solo se puede reproducir una cancion, el espacio
de soluciones oscila en un arbol de altura m y anchura n -> O(n^m)

3. Explica e implementa al menos una función de poda de optimalidad.

Una poda de optimalidad, seria calcular el mejor coste(minimo) por sala para generar una estimacion de las salas restantes.
Si el coste actual mas esta estimacion supera la mejor solucion que tenemos, podamos la rama

2. Implementa un algoritmo de vuelta atrás que resuelva el problema. Explica claramente los marcadores que has utilizado.

Para resolver el problema se han usado los siguientes marcadores:
    - salas: nos ayuda a saber que cancion esta en cada sala
    - numCanciones: nos ayuda a saber el numero de veces que hemops elegido cada cancion
    - esenciales: un vector booleano que nos permite saber que canciones son esenciales
    - numEsenciales: nos ayuda a contar de manera constante si ya hemos usado una cancion esencial
    - minCoste: vector con los valores optimos precalculados para cada cancion.
    - costeActual: El coste que llevamos actualemente 
    - costeMin: Solucion del problema
    - posible: si es posible resolver el problema con las restricciones dadas

*/


bool esValido(int k, int i, int t, const vector<bool> & esenciales, vector<int>& salas, vector<int>& numCanciones) {

    // verificamos que el numero de canciones no supere t
    if (numCanciones[i] > t) {
        return false;
    }

    // verificamos que la misma cancion no suene en dos salas consecutivas
    // como verificamos conforme vamos añadiendo canciones a la sala, comprobamos que la sala anterior no contenga la misma cancion que la sala actual
    if (k > 0 && salas[k] == salas[k - 1]) {
        return false;
    }

    return true;
}

void maneras(int k, const tMatriz& coste, int n, int m, int t, vector<int>& salas, vector<int>& numCanciones, const vector<bool>& esenciales,
    const vector<int>& minCoste, int& costeMinimo,int costeActual, int esencialesUsadas, bool& posible) {

    for (int i = 0; i < n; i++) {
        salas[k] = i; // elegimos la cancion en la sala actual
        numCanciones[i]++; //aumentamos en uno la cancion k elegida
        costeActual += coste[i][k]; //sumamos el coste de la cancion k en la sala i

        if (esenciales[i]) esencialesUsadas++;

        if (esValido(k, i, t, esenciales, salas, numCanciones)) {
            //si estamos en la ultima etapa
            if (k == m - 1) {
                if (esencialesUsadas > 0) { // verificamos que al menos una sala contenga una de las canciones esenciales
                    if (costeActual < costeMinimo) {// si la solucion actual es mejor que la que ya tenemos
                        posible = true;
                        costeMinimo = costeActual;
                    }
                }
            }
            else {
                //Poda de optimalidad: si el siguiente valor no nos da un mejor resultado, descartamos esa solucion
                if (costeActual + minCoste[k+1] < costeMinimo) {
                    maneras(k + 1, coste, n, m, t, salas,numCanciones,esenciales, minCoste, costeMinimo, costeActual,esencialesUsadas, posible);
                }
            }
        }

        //desmarcamos
        salas[k] = -1;
        numCanciones[i]--;
        costeActual -= coste[i][k];

        if (esenciales[i]) esencialesUsadas--;

    }

}

void resolver(const tMatriz& coste,int n, int m, int t, const vector<bool>& esenciales, const vector<int>& minCoste, int& costeMinimo, bool &posible) {
    costeMinimo = INT_MAX;
    posible = false;
    vector<int> salas(m,-1), numCanciones(n,0);

    maneras(0, coste, n, m, t, salas,numCanciones,esenciales, minCoste, costeMinimo, 0,0, posible);
}


bool resuelveCaso() {
    int n, m, t; cin >> n >> m >> t;
    // leer los datos de la entrada
    tMatriz coste(n, vector<int>(m));
    vector<int> minCoste(m, INT_MAX);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> coste[i][j];
            minCoste[j] = min(minCoste[j], coste[i][j]);
        }
    }

    int numEsenciales = 0; cin >> numEsenciales;
    vector<bool> esenciales(n, false);

    for (int i = 0; i < numEsenciales; i++) {
        int id;  cin >> id;
        esenciales[id] = true;
    }

    //resolver el problema
    int costeMinimo;
    bool posible;

    //calculamos las posibles sumas de los sotes minimos de derecha a izquierda
    for (int i = m - 1; i > 0; i--) {
        minCoste[i - 1] += minCoste[i];
    }

    resolver(coste, n, m, t, esenciales, minCoste, costeMinimo, posible);

    // escribir sol
    if (posible) {
        cout << costeMinimo << "\n";
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
    std::ifstream in("ENE_3.in");
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
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
pred ordenar (a, b) -> para todo i, j tal que { 0 <= i < a ^ 0 <= j < b ^ 0 <= k < i + j: sol[k] = min{ a[i], b[j]} }

P: 0 <= n < |a| + |b|
func ordenarLista( vector<int> : a, vector<int> : b  ) : vector<int>
Q: solucion = ordenar(a,b)  

Funcion de Cota: t(i) = v.size() - i;

Invariante : I -> 0 <= i < |v| ^
max_izq = max { v[k] | 0 <= k < i ^ k <= p } ^ 
min_der = min { v[k] | 0 <= k < i ^ k > p } ^

COSTE: El coste de la funcion es lineal respecto al numero de elementos del vector v. Cada acceso al vector es constante por lo tanto el coste es O(N)
*/

    
vector<int> ordenarListas(const vector<int>& listaA, const vector<int>& listaB) {
    int A = listaA.size() , B = listaB.size();
    int N = A + B;
    vector<int> sol;
    int indiceA = 0, indiceB = 0;

    while (indiceA + indiceB  < A+B) {

        if (indiceA < A && indiceB < B) {
            if (listaA[indiceA] < listaB[indiceB]) { // si el elemento de la listaA es menor que el de la listaB
                sol.push_back(listaA[indiceA]);
                indiceA++;
            }
            else if (listaA[indiceA] > listaB[indiceB]) {  // si el elemento de la listaB es menor que el de la listaA
                sol.push_back(listaB[indiceB]);
                indiceB++;
            }
            else { // si el elemento de la listaA es IGUAL que el de la listaB
                sol.push_back(listaA[indiceA]);
                indiceA++;
                indiceB++;
            }
        }
        else if (indiceA < A) { // si ya hemos acabado la lista B
            sol.push_back(listaA[indiceA]);
            indiceA++;
        }
        else if (indiceB < B) { // si ya hemos acabado la lista A
            sol.push_back(listaB[indiceB]);
            indiceB++;
        }
    }

    return sol;
}


bool resuelveCaso() {
    int A, B; cin >> A >> B;

    // leer los datos de la entrada
    vector<int> listaA(A);
    vector<int> listaB(B);
    int valor = 0;

    for (int i = 0; i < A; i++) {
        cin >> valor ;
        listaA[i] = valor;
    }

    for (int i = 0; i < B; i++) {
        cin >> valor ;
        listaB[i] = valor;
    }

    //resolver el problema
    vector<int> sol = ordenarListas(listaA, listaB);

    // escribir sol
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }

    cout << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_17.in");
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
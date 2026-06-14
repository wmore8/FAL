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

1. Predicados:

todosEntre(v, c, f, a, b) -> { \forall i : c <= i < f : a <= v[i] < b }

todosEntre(v) -> { todosEntre(v,0,v.size(),1,v.size()) }

2.Funcion

P: v.size() >= 2 && todosEntre(v)
func repetido( vector<int> v) : int res
Q: { \exsists i,j : 0 <= i < j < v.size() : v[i] == v[j] && v[i] == res }

4.Coste: En el caso mejor el coste es lineal O(N), siendo N el numeor de elementos en el vector, debido a que recorremos todo el vector para particionarlo y encontramos
el repetido a la primera. En caso de que no sea el pivote, necesitamos seguir iterando entre la izquierda o la derecha segun los valores p y q que obtengamos.

Ecuacion de recurrencia

    - Caso base:        T(n) = n + C1                 si n <= 2 
    - Caso recursivo:   T(n) = T(n/2) + n C2          si n > 2         

    siendo C1 y C2, constantes distintas

Como se observa en la ecuacion de recurrencia, el caso base es lineal O(N) (como habiamos comentado antes), y el caso recursivo por el teorema de la division
con a =1, b = 2, k= 1; a < b^k , por lo tanto el coste del caso promedio esta comprendido en el orden exacto de O(n^k) quedandose en O(n) lineal.

En el caso peor, tenemos que recorrer como maximo la mitad del vector para poder particionarlo. Esto supone un coste de O(logn) por esta recursion ademas del coste
aplicado por la funcion de particion explicada anteriormente -> O(n log n);

*/

// { 0 <= a <= b +1 <= v . size () }
void particion(vector <int> &v, int a, int b, int pivote, int& p, int& q) {
    int k; int aux; p = a; k = a; q = b;
    while (k <= q) {
        // I : a <= p <= k <= q +1 <= b +1 <= v . size () &&
        // menores (v ,a ,p -1) && iguales (v ,p ,k -1) && mayores (v , q +1 , b )
        if (v[k] == pivote) { k = k + 1; }
        else if (v[k] < pivote) {
            aux = v[p]; v[p] = v[k]; v[k] = aux; p = p + 1; k = k + 1;
        }
        else {
            aux = v[q]; v[q] = v[k]; v[k] = aux; q = q - 1;
        }
        
    }
    
} // { a <= p <= q +1 <= b +1 <= v . size () /\
  // menores (v ,a ,p -1) /\ iguales (v ,p , q ) /\ mayores (v , q +1 , b ) }

//hacer mas funciones para la recursion

int repetido_rec(vector<int>& v, int ini, int fin, int a, int b) {
    int p, q;

    int pivote = a + (b - a) / 2;
    //particionamos el vector, los menores a la izquierda [ini, p-1] , los iguales al pivote entre (p,q) , y los mayores a la derecha (q+1,fin]
    particion(v, ini, fin, pivote, p, q); 

    if (q - p >= 1) { 
        return pivote; //CASO BASE: si hay mas de un elemento igual al pivote, hemos encontrado al repetido
    }
    else {
        int elementos_izq = p - ini; //la cantidad de numeros menores a la izquierda que tenemos
        int valores_unicos_izq = pivote - a; //los valores unicos a la izquierda que podemos tomar 

        // Si hay mas elementos que valores unicos posibles, el repetido esta por la izquierda (por narices)
        if (elementos_izq > valores_unicos_izq) {
            return repetido_rec(v, ini, p - 1, a, pivote);
        }
        else { // si no, buscamos por la derecha
            return repetido_rec(v, q + 1, fin, pivote + 1, b);
        }
    }

}

const int repetido(vector<int>& v) {
    return repetido_rec(v, 0, v.size() - 1, 1, v.size());
}

bool resuelveCaso() {
    int n; cin >> n;

    if (n == 0) return false;
    // leer los datos de la entrada

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
   
    //resolver el problema
    int sol = repetido(v);

    // escribir sol
    cout << sol << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("EC_2.in");
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
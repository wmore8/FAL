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
pred vistaMar(v,i) -> para todo i,j : 0 <= i < j < v.size() tal que v[i].piso > v[j].altura) ^ v[i].piso != -1

P: 0 < v.size() 
func contVistas( v:vector<int> ) : vector<string>
Q: solucion = { v[i].id  para todo i : 0 <= i < v.size() ^ vistaMar(v,i) }

Funcion de Cota: t(i) = v.size() - i;

Invariante : I -> 0 <= i < v.size() ^
max_altura = v[j].altura :  <= j < v.size() ^
playa = {v[k].id : i <= k < |v| ^ vistaMar(v,k)}

COSTE: El coste de la funcion es lineal respecto al numero de elementos del vector v. Cada acceso al vector es constante por lo tanto el coste es O(N)
*/

struct Edificio {
    string id;
    int altura;
    int piso;
};

vector<string> vistaMar(vector<Edificio> const& v) {
    vector<string> playa;
    Edificio posterior = v[v.size() - 1];
    int max_altura = posterior.altura;

    //caso base : el primer edificio tiene un piso disponible
    if (posterior.piso != -1)
        playa.push_back(posterior.id);

    for (int i = v.size() - 2; i >= 0; i--){
        
        if (max_altura < v[i].piso) {
            playa.push_back(v[i].id);
        }

        if (max_altura < v[i].altura) {
            max_altura = v[i].altura;
        }

        posterior = v[i];
    }

    return playa;
}
    

bool resuelveCaso() {
    int N = 0; cin >> N;

    if (N == 0)
        return false;

    // leer los datos de la entrada
    vector<Edificio> edificios(N);

    int altura = 0, piso = 0;
    string id;

    for (int i = 0; i < N; i++) {
        cin >> id >> altura >> piso;
        edificios[i] = { id,altura,piso };
    }

    //resolver el problema
    vector<string> playa = vistaMar(edificios);

    // escribir sol

    if (playa.size() > 0) {
        cout << playa.size() << "\n";

        for (int i = 0; i < playa.size(); i++) {
            cout << playa[i] << " ";

        }
    }
    else {
        cout << "Ninguno";
    }
    
    cout << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1_15.in");
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
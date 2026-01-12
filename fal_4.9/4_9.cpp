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

Usaremos como marcadores:
    - contG = numero de integrantes del grupo actual
    - nivelG = nivel total del grupo actual
    - clasesG = vector que contiene las clases actuales
    - ataqueG = numero de daño que hace el grupo actual al que se le sumara el aumento de ataque de 25% por intgrante
    - ataqueMax = maximo daño que hemos podido realizar hasta ahora
    - numC = numero de cristales que hemos utilizado
    - posible = si es posible derrotar al dragon con los cristales dados

Es mejor usar una estructura personalizada tHeros y tCristal, ya que usaremos los cristales como almacenamiento de datos de los 4 heroes que lo pueden usar

Para resolver el problema usaremos un arbos de con altura H y una anchura de N, siendo H el numero de heroes y N el numero de cristales, lo que nos da un total de 
N^H soluciones:

    - vector<tCristal> cristales: Es el marcador principal. Para cada cristal i : 0 <= i < N : mantenemos:
        - numHeroes: Contador para validar que no superamos los 4 heroes por cristal.
        - sumaNiveles: Acumulador para validar que no superamos el nivel M del cristal.
        - vector<int> clases: Historial de clases para validar que no hay más de 2 heroes de la misma clase.
        - sumaAtaqueBase: Para calcular el daño total sin aplicar las mejoras.
    - cristalesUsados: Un entero que indica cuantos cristales hemos abierto hasta el momento.
    - minCristales: el menor numero de cristales encontrado hasta el momento en una solucion valida. Se inicializa a N+1.

*/

struct tHeroe {
    int clase;
    int nivel;
    int ataque;
};

struct tCristal {
    int numHeroes;
    int sumaNiveles;
    int sumaAtaqueBase;
    vector<int> clases;
};

/*
bool grupoValido(const vector<int>& clase, const vector<int>& nivel, const vector<int>& ataque, int H, int N, int M, int PV, int k,
    int contG, int nivelG, vector<int>& clasesG, int ataqueG, int ataqueMax, int& numCristales, bool& posible) {

}

void maneras(const vector<int>& clase, const vector<int>& nivel, const vector<int>& ataque, int H, int N, int M, int PV, int k,
    int contG, int nivelG, vector<int>& clasesG, int ataqueG, int ataqueMax, int& numCristales, bool& posible) {

    for (int i = 0; i < H; i++) {

        if (grupoValido(clase, nivel, ataque, H, N, M, PV, k, contG, nivelG, clasesG, ataqueG, ataqueMax, numCristales, posible)) {
            if (k == H - 1) {

            }
            else {
                maneras(clase, nivel, ataque, H, N, M, PV, k + 1, contG, nivelG, clasesG, ataqueG, ataqueMax, numCristales, posible);
            }
        }

    }
}
*/

// Comprueba si el héroe cabe en el cristal 'id'
bool esValido(const tCristal& cristal, const tHeroe& heroe, int M) {
    int contador = 0;
    for (int c : cristal.clases) {
        if (c == heroe.clase) contador++;
    }
    
    if (contador >= 2) {//comprobamos las clases
        return false;
    }
    if (cristal.numHeroes >= 4) { //comprobamos el numero de heroes
        return false; 
    }
    if (cristal.sumaNiveles + heroe.nivel > M) { //comprobamos el nivel total
        return false;
    }

    return true;
}

bool venceDragon(const vector<tCristal>& cristales, int cristalesUsados, int PV) {
    double total = 0.0;
    for (int i = 0; i < cristalesUsados; i++) {
        if (cristales[i].numHeroes > 0) {
            double bonificador = 1.0 + (0.25 * cristales[i].numHeroes);
            total += cristales[i].sumaAtaqueBase * bonificador;
        }
    }
    return total >= PV;
}

void maneras(const vector<tHeroe>& heroes,int H, int N, int M, int PV, int k, vector<tCristal>& cristales, int cristalesUsados, int& minCristales) {

    // Calculamos hasta qué cristal probar (Simetría: solo los usados + 1 nuevo)
    int limite = min(cristalesUsados + 1, N);

    for (int i = 0; i < limite; i++) {

        if (esValido(cristales[i], heroes[k], M)) {
            // marcamos
            cristales[i].numHeroes++;
            cristales[i].sumaNiveles += heroes[k].nivel;
            cristales[i].sumaAtaqueBase += heroes[k].ataque;
            cristales[i].clases.push_back(heroes[k].clase);

            // Calculamos si hemos usado un cristal nuevo
            int nuevosUsados = cristalesUsados;

            if (i == cristalesUsados) {
                nuevosUsados = cristalesUsados + 1;
            }

            // Poda basica: si ya usamos más cristales que el mejor caso, no seguimos
            if (nuevosUsados < minCristales) {
                if (k == H - 1) { // Si es el ultimo heroe
                    if (venceDragon(cristales, nuevosUsados, PV)) {
                        minCristales = nuevosUsados;
                    }
                }
                else { // Caso recursivo
                    maneras(heroes, H, N, M, PV, k + 1, cristales, nuevosUsados, minCristales);
                }
            }
          
            // desmarcamos
            cristales[i].clases.pop_back();
            cristales[i].sumaAtaqueBase -= heroes[k].ataque;
            cristales[i].sumaNiveles -= heroes[k].nivel;
            cristales[i].numHeroes--;
        }
    }
}

bool resuelveCaso() {
    int H, N, M, PV; cin >> H >> N >> M >> PV;

    // leer los datos de la entrada

    vector<tHeroe> heroes(H);
    vector<int> clase(H);
    vector<int> nivel(H);
    vector<int> ataque(H);

    for (int i = 0; i < H; i++) {
        cin >> heroes[i].clase;
    }
    for (int i = 0; i < H; i++) {
        cin >> heroes[i].nivel;
    }
    for (int i = 0; i < H; i++) {
        cin >> heroes[i].ataque;
    }

    vector<tCristal> cristales(N);
    int minCristales = N + 1;
    int cristalesUsados = 0;

    //resolver el problema

    //maneras(clase, nivel, ataque, H, N, M, PV, 0, contG, nivelG, clasesG, ataqueG, ataqueMax, numCristales, posible); // primera version :'C
    maneras(heroes, H, N, M, PV, 0, cristales, cristalesUsados, minCristales);

    // escribir sol

    if (minCristales > N) {
        cout << "DERROTA\n";
    }
    else {
        cout << minCristales << "\n";
    }

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("4_9.in");
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
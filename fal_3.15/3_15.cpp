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
//#include <chrono>

using namespace std;


/*

pred esValida(canciones, n, k ,d, dActual, pActual, maxP) = max(maxP) tal que  i: 0 <= i <= n ^ maxP = SUM(canciones[i].puntuacion) 
^ ( pActual < d < pActual + canciones[i].duracion ) \/ ( d < pActual + canciones[i].duracion < 2*d)

P: 1 <= n <= 25 
func maneras(m: int, p : int, k:int, pActual: int, dActual: int, maxP: int& ): void
Q: esValida(canciones, n, k ,d, dActual, pActual, maxP)

Funcion de cota: t(n, k) = n - k -> siendo k la cancion actual

Ecuacion de recurrencia:
    - Caso base: t(k,n) = O(1) si k = p
    - Caso recursivo: t(k, p) = n * T(k + 1, n) + C0 si k < n

Coste: En el peor caso, el algoritmo explora todas las posibles asignaciones de n canciones sobre las 2 caras del casete. Esto da una complejidad de O(2^n) en 
el peor caso. Sin embargo, debido a la restricción n ≤ 50, en la práctica el coste está  acotado.

*/

struct Cancion {
    int duracion;
    int puntuacion;
};

float estimacion(const vector<Cancion>& canciones, int n, int k, int d, int puntActual, int caraA, int caraB, int& mejorPuntuacion) {
    int j = k + 1, duracionRestante = (2 * d - caraA - caraB);
    float estimacion = 0;

    while (j < n && canciones[j].duracion <= duracionRestante) {
        duracionRestante -= canciones[j].duracion;
        estimacion += canciones[j].puntuacion;
        j++;
    }

    if (j < n) {
        estimacion = estimacion + ((float)duracionRestante * canciones[j].puntuacion / canciones[j].duracion);
    }

    return estimacion;
}

bool esValida(const vector<Cancion>& canciones, int k, int d, int durActual) {
    
    //Si la cancion actual esta en la parte final de la cara A del casete, si supera la duracion permitida, entonces no es valida
    if (  durActual > d) {
        return false;
    }

    //Si la cancion actual esta en la parte final de la cara B del casete, si supera la duracion permitida, entonces no es valida
    if ( durActual > 2*d) {
        return false;
    }

    return true;
}

/*
void maneras(const vector<Cancion>& canciones, int n, int k, int d, int puntActual, int caraA, int caraB, int& mejorPuntuacion) {
    //3 posibles podas -> Probamos con la cara A, la cara B, o no asignamos la cancion 
    
    //Caso recursivo de la Cara A
    caraA += canciones[k].duracion;
    puntActual += canciones[k].puntuacion;

    if (caraA <= d) { 
        if (k == n - 1) {
            if (puntActual > mejorPuntuacion) {
                mejorPuntuacion = puntActual;
            }
        }
        else {
            maneras(canciones, n, k + 1, d, puntActual, caraA, caraB, mejorPuntuacion);
        }
    }
    //desmarcamos
    caraA -= canciones[k].duracion;
    puntActual -= canciones[k].puntuacion;

    //Caso recursivo de la Cara B
    caraB += canciones[k].duracion;
    puntActual += canciones[k].puntuacion;

    if (caraB <= d) {
        if (k == n - 1) {
            if (puntActual > mejorPuntuacion) {
                mejorPuntuacion = puntActual;
            }
        }
        else {
            maneras(canciones, n, k + 1, d, puntActual, caraA, caraB, mejorPuntuacion);
        }
    }
    //desmarcamos
    caraB -= canciones[k].duracion;
    puntActual -= canciones[k].puntuacion;

    //Caso recursivo : No elegimos la cancion
    if (k == n - 1) {
        if (puntActual > mejorPuntuacion) {
            mejorPuntuacion = puntActual;
        }
    }
    else {
        float est = estimacion(canciones, n, k + 1, d, puntActual, caraA, caraB, mejorPuntuacion);
        if (est > puntActual) {
            maneras(canciones, n, k + 1, d, puntActual, caraA, caraB, mejorPuntuacion);
        }
    }
}
*/

/*
void maneras(const vector<Cancion>& canciones, int n, int k, int d, int puntActual, int caraA, int caraB, int& mejorPuntuacion) {
    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            caraA += canciones[k].duracion;
        }
        else {
            caraB += canciones[k].duracion;
        }
        puntActual += canciones[k].puntuacion;

        if (caraA <= d && caraB <= d) {
            if (k == n - 1) {
                if (puntActual > mejorPuntuacion) {
                    mejorPuntuacion = puntActual;
                }
            }else{
                maneras(canciones, n, k + 1, d, puntActual, caraA, caraB, mejorPuntuacion);
            }
        }
        //desmarcamos
        if (i == 0) {
            caraA -= canciones[k].duracion;
        }
        else {
            caraB -= canciones[k].duracion;
        }
        puntActual -= canciones[k].puntuacion;

        if (k == n - 1) {
            if (puntActual > mejorPuntuacion) {
                mejorPuntuacion = puntActual;
            }
        }
        else {
            maneras(canciones, n, k + 1, d, puntActual, caraA, caraB, mejorPuntuacion);
        }

    }
}
*/

/*
void maneras(const vector<Cancion>& canciones, int n, int k, int d, int puntActual, vector<int> & casete, int& mejorPuntuacion) {
    for (int i = 0; i < 2; i++) {
        casete[i] += canciones[k].duracion;
        puntActual += canciones[k].puntuacion;

        if (casete[0] <= d && casete[1] <= d) {
            if (k == n - 1) {
                if (puntActual > mejorPuntuacion) {
                    mejorPuntuacion = puntActual;
                }
            }else{
                if (puntActual > mejorPuntuacion) {
                    mejorPuntuacion = puntActual;
                }
                maneras(canciones, n, k + 1, d, puntActual, casete, mejorPuntuacion);
            }
        }

        casete[i] -= canciones[k].duracion;
        puntActual -= canciones[k].puntuacion;
    }
}
*/

void maneras(const vector<Cancion>& canciones, int n, int k, int d, int puntActual, int caraA, int caraB, int& mejorPuntuacion, vector<int> &acum) {
    //3 posibles podas -> Probamos con la cara A, la cara B, o no asignamos la cancion 

    //Caso recursivo de la Cara A
    caraA += canciones[k].duracion;
    puntActual += canciones[k].puntuacion;

    if (caraA <= d) {
        if (k == n - 1) {
            if (puntActual > mejorPuntuacion) {
                mejorPuntuacion = puntActual;
            }
        }
        else {
            maneras(canciones, n, k + 1, d, puntActual, caraA, caraB, mejorPuntuacion, acum);
        }
    }
    //desmarcamos
    caraA -= canciones[k].duracion;
    puntActual -= canciones[k].puntuacion;

    //Caso recursivo de la Cara B
    caraB += canciones[k].duracion;
    puntActual += canciones[k].puntuacion;

    if (caraB <= d) {
        if (k == n - 1) {
            if (puntActual > mejorPuntuacion) {
                mejorPuntuacion = puntActual;
            }
        }
        else {
            maneras(canciones, n, k + 1, d, puntActual, caraA, caraB, mejorPuntuacion, acum);
        }
    }
    //desmarcamos
    caraB -= canciones[k].duracion;
    puntActual -= canciones[k].puntuacion;

    //Caso recursivo : No elegimos la cancion
    if (k == n - 1) {
        if (puntActual > mejorPuntuacion) {
            mejorPuntuacion = puntActual;
        }
    }
    else {
        if (puntActual + acum[k + 1] > mejorPuntuacion) {
            maneras(canciones, n, k + 1, d, puntActual, caraA, caraB, mejorPuntuacion, acum);
        }
    }
}

const bool operator <(const Cancion &a, const Cancion &b) {
    return (float) a.puntuacion / a.duracion > (float) b.puntuacion / b.duracion;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int n; cin >> n;

    if (n == 0) return false;

    int d = 0; cin >> d;
    vector<Cancion> canciones(n);
    vector<int> casete(2,0), acum(n,0);

    for (int i = 0; i < n; i++) {
        cin >> canciones[i].duracion >> canciones[i].puntuacion;
        acum[i] = canciones[i].puntuacion;
    }

    //resolver el problema
    int mejorPuntuacion = 0;
    //sort(canciones.begin(), canciones.end());
    for (int i = n - 1; i > 0; i--) {
        acum[i - 1] += acum[i];
    }

    maneras(canciones, n, 0, d, 0, 0,0, mejorPuntuacion, acum);
    
    // escribir sol
    cout << mejorPuntuacion << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("3_15.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    /*
    auto start = std::chrono::steady_clock::now();
    while (resuelveCaso());
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    // Source - https://stackoverflow.com/a
    // Posted by Sajal, modified by community. See post 'Timeline' for change history
    // Retrieved 2025-12-09, License - CC BY-SA 4.0

    std::cout << std::chrono::duration<double, std::milli>(diff).count() << " ms" << std::endl;
    */

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}


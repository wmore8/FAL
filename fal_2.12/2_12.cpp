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

    pred rareza( n , grado) : int -> { para todo d_i, prev : d_i =  todos los digitos de n tal que ^ prev = los digitos mas significativos que d_i
    tal que ( prev <= grado ^ MULTIPLICATORIO Π (prev) % 10 = d_i ) }

    P: n ≥ 0 ^ 1 <= g <= 9
    func mistico(n: int, g: int): int
    Q: resultado = rareza(n, g) ^ resultado >= 0

    Función de Cota: t(n) = n

    Ecuacion de recurrencia:
      - Caso base: T(n) = O(1) si n ≤ 10
      - Caso recursivo: T(n) = O(1) + T(n/10) si n > 10

    Coste: O(log10 n) -> logaritmico en base 10 (porque multiplicamos y dividimos por 10 en cada iteracion recursiva)

    Empezaremos a contar los numeros misticos una vez se haya llamado al caso base, en el cual si es mistico lo añadimos al producto. En caso de que no avanzamos
    por los siguientes digitos en busca de los que si cumplan la condicion : digito == producto_de_anteriores % 10
*/

struct tSol {
    int contador;
    int producto;
};

//funcion recursiva no final
tSol mistico(int n, int g) {
    //CASO BASE
    if (n < 10) {

        if (n == g) {
            return { 1,n }; // el mas significativo es mistico 
        }
        else if(n > g){ 
            return { 0,1 };// el mas significativo NO es mistico y n NO es de grado g
        }
        else {
            return { 0,n };// el mas significativo NO es mistico y n SI es de grado g
        }
    }
    //LLAMADA RECURSIVA
    tSol rareza = mistico(n / 10, g);
    int digito = n % 10, contador = rareza.contador, producto = rareza.producto;
   
    if (digito == producto % 10) { // si el digito es mistico aumentamos el contador
        ++contador;
    }
    if (digito <= g) { // si el digito es menor o igual al grado lo añadimos al producto (porque es mas significativo que el siguiente) 
        producto *= digito;
    }
    
    return{ contador, producto };
}

bool resuelveCaso() {
    int n = 0, g = 0; cin >> n >> g;
    // leer los datos de la entrada

    //resolver el problema
    tSol rareza = mistico(n, g);

    // escribir sol
    cout << rareza.contador << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_12.in");
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
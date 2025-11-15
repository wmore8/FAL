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

    pred obtuso( n ) : int -> { para todo d_i, prev : d_i =  todos los digitos de n tal que ^ prev = los digitos mas significativos que d_i
    tal que ( prev % 2 == 1 ^ MULTIPLICATORIO Π (prev) % 10 = d_i ) }

    P: n ≥ 0
    func resolver(n: int, g: int): return int resolver
    Q: resultado = obtuso(n) ^ resultado >= 0

    Función de Cota: t(n) = n

    Ecuacion de recurrencia:
      - Caso base: T(n) = O(1) si n ≤ 10
      - Caso recursivo: T(n) = O(1) + T(n/10) si n > 10

    Coste: O(log10 n) -> logaritmico en base 10 (porque multiplicamos y dividimos por 10 en cada iteracion recursiva)

    Empezamos a contar los digitos obtusos una vez se haya llamado al caso base, en el que si el digito mas significativo == 1, entonces es obtuso. En otro caso
    si es impar lo añadimos al producto de digitos significativos. Aprovechamos la regresion para contar los numeros obtusos si cumple la condicion :
    digito == producto de anteriores % 10

*/

struct tSol {
    int contador;
    int producto;
};

//funcion recursiva no final
tSol obtuso(int n) {
    //CASO BASE
    if (n < 10) {

        if (n == 1) {
            return { 1,n }; // el mas significativo es obtuso 
        }
        else if(n % 2 == 0){ 
            return { 0,1 };// el mas significativo NO es obtuso y n es PAR
        }
        else {
            return { 0,n };// el mas significativo NO es obtuso y n es IMPAR
        }
    }
    //LLAMADA RECURSIVA
    tSol numero = obtuso(n / 10);
    int digito = n % 10, contador = numero.contador, producto = numero.producto;
   
    if (digito == producto % 10) { // si el digito es obtuso aumentamos el contador
        ++contador;
    }
    if (digito % 2 == 1) { // si el digito es impar lo añadimos al producto (porque es mas significativo que el siguiente) 
        producto *= digito;
    }
    
    return{ contador, producto };
}

bool resuelveCaso() {
    int n = 0; cin >> n;
    // leer los datos de la entrada

    //resolver el problema
    tSol numero = obtuso(n);

    // escribir sol
    cout << numero.contador << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("2_13.in");
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
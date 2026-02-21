#include <stdio.h>
#define N 4

void InicializarMatriz(float matriz[N][N]);
void LeerMatriz(float matriz[N][N]);
void CalcularMatrizTriangularSuperior(float matriz[N][N]);
void PromoverFilaConMaximoAlPivote(float matriz[N][N], int filaPivote, int columnaPivote);
void HacerCerosLosElementosBajoElPivote(float matriz[N][N], int filaPivote, int columnaPivote);
void IntercambiarFilas(float matriz[N][N], int fila1, int fila2);
void MostrarMatriz(float matriz[N][N]);

int main() {
    // variables/declaraciones
    float matrizDeCoeficientes[N][N];

    InicializarMatriz(matrizDeCoeficientes);

    // entradas
    LeerMatriz(matrizDeCoeficientes);

    // proceso
    CalcularMatrizTriangularSuperior(matrizDeCoeficientes);

    // salida
    MostrarMatriz(matrizDeCoeficientes);

    return 0;
}

// SUB-RUTINA
// Inicializa todos los elementos de la matriz con el valor 0.
// Recibe: matriz (matriz que será inicializada)
// Devuelve: Nada (modifica la matriz directamente)
void InicializarMatriz(float matriz[N][N]) {
    // Recorrer cada fila de la matriz
    for (int fila = 0; fila < N; fila++) {
        // Recorrer cada columna de la fila actual
        for (int columna = 0; columna < N; columna++) {
            // Asignar el valor 0 a cada elemento
            matriz[fila][columna] = (float)0.0;
        }
    }
}

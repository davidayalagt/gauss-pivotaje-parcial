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

// SUB-RUTINA
// Lee los elementos de la matriz desde la entrada estándar.
// El usuario ingresa los valores de cada fila separados por espacios,
// y presiona Enter al final de cada fila.
// Recibe: matriz (matriz que será llenada con los datos del usuario)
// Devuelve: Nada (modifica la matriz directamente)

void LeerMatriz(float matriz[N][N]) {
    printf("Ingrese los valores de cada fila para la matriz de 4x4.\n\n");
    // Recorrer cada fila de la matriz
    for (int fila = 0; fila < N; fila++) {
        // Mostrar instrucción al usuario
        printf("Fila %d: ", fila);

        // Recorrer cada columna de la fila actual
        for (int columna = 0; columna < N; columna++) {
            // Leer el valor desde la entrada estándar
            scanf("%f", &matriz[fila][columna]);
        }
    }
    printf("\n");
}

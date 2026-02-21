#include <stdio.h>
#define N 4

void InicializarMatriz(float matriz[N][N]);
void LeerMatriz(float matriz[N][N]);
void CalcularMatrizTriangularSuperior(float matriz[N][N]);
void PromoverFilaConMaximoAlPivote(float matriz[N][N], int filaPivote, int columnaPivote);
void HacerCerosLosElementosBajoElPivote(float matriz[N][N], int filaPivote, int columnaPivote);
void IntercambiarFilas(float matriz[N][N], int fila1, int fila2);
float Absoluto(float valor);
void MostrarMatriz(float matriz[N][N], const char* mensaje);

int main() {
    // variables/declaraciones
    float matrizDeCoeficientes[N][N];

    InicializarMatriz(matrizDeCoeficientes);

    // entradas
    LeerMatriz(matrizDeCoeficientes);

    MostrarMatriz(matrizDeCoeficientes, "\nMatriz Ingresada:\n");

    // proceso
    CalcularMatrizTriangularSuperior(matrizDeCoeficientes);

    // salida
    MostrarMatriz(matrizDeCoeficientes, "\nMatriz Triangular Superior:\n");

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
        printf("Fila %d: ", fila + 1);

        // Recorrer cada columna de la fila actual
        for (int columna = 0; columna < N; columna++) {
            // Leer el valor desde la entrada estándar
            scanf("%f", &matriz[fila][columna]);
        }
    }
    printf("\n");
}

// SUB-RUTINA
// Calcula la matriz triangular superior mediante eliminación Gaussiana con pivotaje parcial.
// Recibe: matriz (matriz que será transformada)
// Devuelve: Nada (modifica la matriz directamente)

void CalcularMatrizTriangularSuperior(float matriz[N][N]) {
    int ultimaColumna = N - 1;

    // Procesar cada columna como pivote
    for (int columnaPivote = 0; columnaPivote < ultimaColumna; columnaPivote++) {
        // En cada iteración, estamos en la posición diagonal de la matriz
        int filaPivote = columnaPivote;

        printf("Pivote actual (%d,%d)\n", filaPivote + 1, columnaPivote + 1);
        printf("Fila original del pivote: %d\n", filaPivote + 1);

        // PASO 1: Promover la fila con el máximo valor absoluto a la posición del pivote
        PromoverFilaConMaximoAlPivote(matriz, filaPivote, columnaPivote);
        MostrarMatriz(matriz, "\nDespués del pivotaje:\n");

        // PASO 2: Hacer ceros en todos los elementos debajo del pivote
        HacerCerosLosElementosBajoElPivote(matriz, filaPivote, columnaPivote);
        MostrarMatriz(matriz, "\nDespués de la eliminación:\n");
    }
}

// SUB-RUTINA
// Busca el elemento con mayor valor absoluto en la columna actual (desde la fila actual hacia abajo)
// y lo coloca en la posición del pivote mediante intercambio de filas.
// Recibe: matriz (matriz que será modificada)
//         filaPivote (fila donde está el pivote)
//         columnaPivote (columna donde está el pivote)
// Devuelve: Nada (modifica la matriz directamente)

void PromoverFilaConMaximoAlPivote(float matriz[N][N], int filaPivote, int columnaPivote) {
    int ultimaFila = N - 1;
    
    // Inicializar la búsqueda del máximo
    int filaDelMaximo = filaPivote;
    float valorMaximo = Absoluto(matriz[filaPivote][columnaPivote]);
    
    // Recorrer todas las filas debajo de la fila del pivote
    for (int fila = filaPivote + 1; fila <= ultimaFila; fila++) {
        
        // Comparar el valor absoluto del elemento en la columna actual
        // con el máximo encontrado hasta ahora
        if (Absoluto(matriz[fila][columnaPivote]) > valorMaximo) {
            valorMaximo = Absoluto(matriz[fila][columnaPivote]);
            filaDelMaximo = fila;
        }
    }

    printf("Valor absoluto máximo para la columna %d: %f\n", columnaPivote + 1, valorMaximo);

    // Si la fila con el valor máximo no es la fila del pivote, intercambiarlas
    // Esto asegura que el elemento de mayor valor absoluto esté en la posición del pivote
    if (filaDelMaximo != filaPivote) {
        printf("Nueva fila pivote %d\n", filaDelMaximo + 1);
        IntercambiarFilas(matriz, filaPivote, filaDelMaximo);
    }
    
    // Validación temprana: verificar que el pivote no sea cero
    // Si después de promover la mejor fila el pivote sigue siendo cero,
    // la matriz es singular y no puede ser reducida
    float elementoPivote = matriz[filaPivote][columnaPivote];
    if (elementoPivote == 0) {
        printf("Error: El pivote es cero. Matriz singular. No se puede continuar.\n");
    }
}

// SUB-RUTINA
// Realiza operaciones de fila para hacer cero todos los elementos debajo del pivote.
// Recibe: matriz (matriz que será modificada)
//         filaPivote (fila donde está el pivote)
//         columnaPivote (columna donde está el pivote)
// Devuelve: Nada (modifica la matriz directamente)

void HacerCerosLosElementosBajoElPivote(float matriz[N][N], int filaPivote, int columnaPivote) {
     int ultimaFila = N - 1;
     int ultimaColumna = N - 1;
    
    // Recorrer todas las filas debajo del pivote
    for (int filaAModificar = filaPivote + 1; filaAModificar <= ultimaFila; filaAModificar++) {

        // Obtener el elemento pivote y el elemento a eliminar
         float elementoPivote = matriz[filaPivote][columnaPivote];
         float elementoBajoPivote = matriz[filaAModificar][columnaPivote];
        
        // Verificar que el pivote no sea cero
        if (elementoPivote == 0) {
            printf("Error: El pivote es cero. Matriz singular.\n");
            return;
        }
        
        // Calcular el factor de multiplicación
         float factorDeMultiplicacion = elementoBajoPivote / elementoPivote;

        printf("Eliminacion en fila: %d\n", filaAModificar + 1);
        printf("Elemento pivote: %10.4f\n", elementoPivote);
        printf("Elemento bajo el pivote: %10.4f\n", elementoBajoPivote);
        printf("Factor de multiplicacion: (%10.4f / %10.4f) = %10.4f\n", elementoBajoPivote, elementoPivote, factorDeMultiplicacion);
        printf("Operación: Fila%d_nueva = Fila%d - (%10.4f * Fila%d)\n", filaAModificar + 1, filaAModificar + 1, factorDeMultiplicacion, filaPivote + 1);


        // Aplicar la operación a toda la fila
        // Fila_Actual = Fila_Actual - (Factor × Fila_Pivote)
        for (int columna = columnaPivote; columna <= ultimaColumna; columna++) {
            
            float valorDeFilaPivote = matriz[filaPivote][columna];
            float valorDeFilaAModificar = matriz[filaAModificar][columna];
            
            matriz[filaAModificar][columna] = 
                valorDeFilaAModificar - (factorDeMultiplicacion * valorDeFilaPivote);
        }
    }
}

// SUB-RUTINA AUXILIAR
// Intercambia dos filas de la matriz.
// Recibe: matriz (matriz)
//         fila1, fila2 (filas a intercambiar)
// Devuelve: Nada (modifica la matriz directamente)

void IntercambiarFilas(float matriz[N][N], int fila1, int fila2) {
    int ultimaColumna = N - 1;

    printf("Intercambiando filas %d <--> %d\n", fila1 + 1, fila2 + 1);

    for (int columna = 0; columna <= ultimaColumna; columna++) {
        // Guardar los valores de ambas filas en la columna actual
        float valorFila1 = matriz[fila1][columna];
        float valorFila2 = matriz[fila2][columna];
        
        // Realizar el intercambio explícito
        matriz[fila1][columna] = valorFila2;
        matriz[fila2][columna] = valorFila1;
    }
}

// SUB-RUTINA AUXILIAR
// Retorna el valor absoluto de un número.
// Recibe: valor (número)
// Devuelve: Valor absoluto

float Absoluto(float valor) {
    if (valor < 0) {
        return -valor;
    } else {
        return valor;
    }
}

// SUB-RUTINA
// Muestra la matriz en la consola.
// Recibe: matriz (matriz a mostrar)
// Devuelve: Nada

void MostrarMatriz(float matriz[N][N], const char* mensaje) {
    printf("%s", mensaje);
    printf("============================\n\n");
    
    for (int fila = 0; fila < N; fila++) {
        for (int columna = 0; columna < N; columna++) {
            printf("%10.4f ", matriz[fila][columna]);
        }
        printf("\n");
    }
    
    printf("\n");
}

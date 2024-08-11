#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define STACK_SIZE 8

double stack[STACK_SIZE];
int top = -1;

void printStack() {
    printf("Pila:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d) %.5f\n", i + 1, stack[i]);
    }
    if (top == -1) {
        printf("(vacía)\n");
    }
}

void push(double value) {
    if (top < STACK_SIZE - 1) {
        stack[++top] = value;
    } else {
        printf("Error: Pila llena\n");
    }
}

double pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Error: Pila vacía\n");
        return NAN;
    }
}

void clearStack() {
    top = -1;
    printf("Pila limpiada\n");
}

void suma() {
    if (top < 1) {
        printf("Error: No hay suficientes operandos\n");
        return;
    }
    double b = pop();
    double a = pop();
    push(a + b);
}

void resta() {
    if (top < 1) {
        printf("Error: No hay suficientes operandos\n");
        return;
    }
    double b = pop();
    double a = pop();
    push(a - b);
}

void multiplicacion() {
    if (top < 1) {
        printf("Error: No hay suficientes operandos\n");
        return;
    }
    double b = pop();
    double a = pop();
    push(a * b);
}

void division() {
    if (top < 1) {
        printf("Error: No hay suficientes operandos\n");
        return;
    }
    double b = pop();
    double a = pop();
    if (b == 0) {
        printf("Error: División por cero\n");
        push(a);
        push(b);
    } else {
        push(a / b);
    }
}

void potencia() {
    if (top < 1) {
        printf("Error: No hay suficientes operandos\n");
        return;
    }
    double b = pop();
    double a = pop();
    push(pow(a, b));
}

void raizCuadrada() {
    if (top < 0) {
        printf("Error: No hay suficientes operandos\n");
        return;
    }
    double a = pop();
    if (a < 0) {
        printf("Error: Raíz cuadrada de número negativo\n");
        push(a);
    } else {
        push(sqrt(a));
    }
}

void tangente() {
    if (top < 0) {
        printf("Error: No hay suficientes operandos\n");
        return;
    }
    double a = pop();
    if (fmod(a, 90.0) == 0 && fmod(a, 180.0) != 0) {
        printf("Error: Tangente indefinida para %f grados\n", a);
        push(a);
    } else {
        push(tan(a * M_PI / 180.0)); 
    }
}


void seno() {
    if (top < 0) {
        printf("Error: No hay suficientes operandos\n");
        return;
    }
    double a = pop();
    push(sin(a * M_PI / 180.0)); 
}

void coseno() {
    if (top < 0) {
        printf("Error: No hay suficientes operandos\n");
        return;
    }
    double a = pop();
    push(cos(a * M_PI / 180.0));
}

int main() {
    char option;
    double num1;

    while (1) {
        printf("\033[2J"); 

        printStack();
        printf("\nMenú:\n");
        printf("1. Agregar número a la pila\n");
        printf("2. Realizar operación (suma, resta, multiplicacion, division, potencia, raíz, tangente, seno, coseno\n");
        printf("3. Limpiar pila\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                printf("Ingrese un número: ");
                scanf("%lf", &num1);
                push(num1);
                break;
            case '2':
                if (top >= 0) {
                    printf("Ingrese operación (+, -, *, /, p, r, t, s, c): ");
                    scanf(" %c", &option);
                    switch (option) {
                        case '+':
                            suma();
                            break;
                        case '-':
                            resta();
                            break;
                        case '*':
                            multiplicacion();
                            break;
                        case '/':
                            division();
                            break;
                        case 'p':
                            potencia();
                            break;
                        case 'r':
                            raizCuadrada();
                            break;
                        case 't':
                            tangente();
                            break;
                        case 's':
                            seno();
                            break;
                        case 'c':
                            coseno();
                            break;
                        default:
                            printf("Operación no válida\n");
                            break;
                    }
                } else {
                    printf("Error: La pila está vacía\n");
                }
                break;
            case '3':
                clearStack();
                break;
            case '0':
                printf("Saliendo del programa...\n");
                return 0;
            default:
                printf("Opción no válida\n");
        }
    }
    return 0;
}

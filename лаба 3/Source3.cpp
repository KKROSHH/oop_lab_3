#include <stdio.h>
#include <math.h>

// Функція для розрахунку математичної формули
double calculateFunction(double x, double a, double b) {
    return ((pow(x, 2) + 1) - (1 / sin(b * x))) / cbrt(x / a - 0.39);
}

// Функція для підрахунку кількості значень > 0.5 та добутку значень > 1
void calculateAdditional(double* values, int size, int* count, double* product) {
    *count = 0;
    *product = 1;
    for (int i = 0; i < size; i++) {
        if (values[i] > 0.5) {
            (*count)++;
        }
        if (values[i] > 1) {
            *product *= values[i];
        }
    }
}

// Головна функція
int main() {
    double a = 1.6, b = 0.36; // Константи задачі
    double xValues[] = { 0.2, 1.6, 0.1, 0.36, 0.74 }; // Вхідні значення x
    int size = sizeof(xValues) / sizeof(xValues[0]);
    double yValues[size];

    // Розрахунок значень функції
    for (int i = 0; i < size; i++) {
        yValues[i] = calculateFunction(xValues[i], a, b);
    }

    // Додаткові обчислення
    int count = 0;
    double product = 1;
    calculateAdditional(yValues, size, &count, &product);

    // Виведення результатів
    printf("x\t\ty\n");
    for (int i = 0; i < size; i++) {
        printf("%.2lf\t\t%.5lf\n", xValues[i], yValues[i]);
    }
    printf("\nКількість y > 0.5: %d\n", count);
    printf("Добуток y > 1: %.5lf\n", product);

    return 0;
}
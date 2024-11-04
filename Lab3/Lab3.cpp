#include <iostream>
#include <math.h> 

using namespace std;

// Функція для обчислення y за формулою
double calculateY(double x, double a, double b) {
    double numerator = pow(log(b * x), 4) + 0.85;
    double denominator = cbrt(a + b * pow(x, 3));
    return numerator / denominator;
}

// Функція для підрахунку суми значень y > 1
double calculateSumGreaterThan1(double y_values[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        if (y_values[i] > 1) {
            sum += y_values[i];
        }
    }
    return sum;
}

// Функція для підрахунку кількості значень y > 1
int countGreaterThan1(double y_values[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (y_values[i] > 1) {
            count++;
        }
    }
    return count;
}

int main() {
    // Вхідні дані
    double a = 46.0;
    double b = 1.85;
    double x_start = 0.4;   // Початкове значення x
    double x_end = 6.8;     // Кінцеве значення x
    double step = 0.4;      // Крок h

    // Визначаємо кількість значень x, які треба обчислити
    int size = (int)((x_end - x_start) / step) + 1;

    // Масиви для зберігання значень x і y
    double x_values[size];
    double y_values[size];

    // Обчислення значень x
    for (int i = 0; i < size; i++) {
        x_values[i] = x_start + (i * step);
    }

    // Обчислення y для кожного x
    cout << "Вхідні дані та результати обчислення:" << "\n";
    for (int i = 0; i < size; i++) {
        y_values[i] = calculateY(x_values[i], a, b);
        cout << "x = " << x_values[i] << ", y = " << y_values[i] << "\n";
    }

    // Обчислення суми значень y > 1
    double sum = calculateSumGreaterThan1(y_values, size);
    int count = countGreaterThan1(y_values, size);

    // Виведення результатів
    cout << "\nКількість значень y > 1: " << count << "\n";
    cout << "Сума значень y > 1: " << sum << "\n";

    return 0;
}

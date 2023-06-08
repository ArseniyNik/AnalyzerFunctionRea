#include <iostream> 
#include <string> 
#include <math.h> 
using namespace std;

bool is_prime(int number) { //проверка на простое число 
    for (int i = 2; i <= (sqrt(abs(number))); i++) {
        if (number % i == 0) {
            return false;
            break;
        }
    }
    return true;
}

bool is_perfect(int num) { //проверка на совершенное число 
    int sum = 0;
    for (int j = 1; j < num; j++) {
        if (num % j == 0)
            sum += j;
    }
    if (sum == num)
        return true;
    return false;
}

int NOD(int num_1, int num_2) { //нахождение наибольшего общего делителя 
        int remainder;
        while (d != 0)
        {
            remainder = n % d;
            n = d;
            d = remainder;
        }
        return n;
    }

int NOK(int num_1, int num_2) { //нахождение наименьшего общего кратного 
    int temp_1, temp_2, result;
    temp_1 = num_1;
    temp_2 = num_2;

    while (temp_1 != temp_2) {
        if (temp_1 > temp_2) {
            temp_1 -= temp_2;
        }
        else {
            temp_2 -= temp_1;
        }
    }

    result = (num_1 * num_2) / temp_1;
    return result;
}

void sum(int num_1, int dom_1, int num_2, int dom_2) //Функция, для сложения одной дроби с другой
{
    int n = num_1 * dom_2 + num_2 * dom_1;
    int d = dom_2 * dom_1;
    show(num_1, dom_1);
    cout << " + ";
    show(num_2, dom_2);
    cout << " = ";
    show(n / NOD(n, d), d / NOD(n, d));
    cout << endl;
}

void difference(int num_1, int dom_1, int num_2, int dom_2) //Функция, для вычитания одной дроби из другой
{
    int n = num_1 * dom_2 - num_2 * dom_1;
    int d = dom_1 * dom_2;
    show(num_1, dom_1);
    cout << " - ";
    show(num_2, dom_2);
    cout << " = ";
    show(n / NOD(n, d), d / NOD(n, d));
    cout << endl;
}

void product(int num_1, int dom_1, int num_2, int dom_2) //Функция, для умножения одной дроби с другой
{
    int n = num_1 * num_2;
    int d = dom_2 * dom_1;
    show(num_1, dom_1);
    cout << " * ";
    show(num_2, dom_2);
    cout << " = ";
    show(n / NOD(n, d), d / NOD(n, d));
    cout << endl;
}

void division(int num_1, int dom_1, int num_2, int dom_2) //Функция, для деления одной дроби с другой
{
    int n = num_1 * dom_2;
    int d = dom_1 * num_2;
    show(num_1, dom_1);
    cout << " : ";
    show(num_2, dom_2);
    cout << " = ";
    show(n / NOD(n, d), d / NOD(n, d));
    cout << endl;
}

void show(numerator, denominator) //функция для вывода дроби
{
    if (denominator == 1)
        cout << numerator;
    else
        cout << numerator << "/" << denominator;
}

bool analyze_function() {
    cout << "=================" << '\n';
    // ввод двух чисел 
    cout << "Введите два числа через пробел:\n";
    int num_1, num_2;
    do
    {
        cin >> num_1 >> num_2;
        if (num_1 < 0 || num_2 < 0) {
            cout << "нельзя отрицательные";
        }
    } while (num_1 < 0 || num_2 < 0);

    // Проверка на простое и совершенное первого числа 
    cout << "Число " << num_1;
    if (is_prime(num_1) == false) {
        cout << " НЕ ";
    }
    cout << " простое" << "\n";
    cout << "Число " << num_1;
    if (is_perfect(num_1) == false) {
        cout << " НЕ";
    }
    cout << " совершенное" << "\n";

    // проверка на простое и совершенное второго числа 
    cout << "Число " << num_2;
    if (is_prime(num_2) == false) {
        cout << " НЕ";
    }
    cout << " простое" << "\n";
    cout << "Число " << num_2;
    if (is_perfect(num_2) == false) {
        cout << " НЕ";
    }
    cout << " совершенное" << "\n";

    // нахождение НОД и НОК двух чисел 
    cout << "Наибольший общий делитель =>" << NOD(num_1, num_2) << "\n";
    cout << "Наименьшее общее кратное =>" << NOK(num_1, num_2) << "\n";

    cout << "=================";
    return true;
}

void calculator() {
    cout << "=================" << '\n';
    // ввод двух чисел 
    int num_1, num_2, dom_1, dom_2;
    cout << "Введите числитель первого числа:\n";
    cin >> num_1;
    cout << "Введите знаменатель первого числа:\n";
    cin >> dom_1;
    cout << "Введите числитель второго числа:\n";
    cin >> num_2;
    cout << "Введите знаменатель второго числа:\n";
    cin >> dom_2;

    bool flag = true;
    while (flag == true) {
        cout << "Какую операцию необходимо провести (- + : *), для выхода из функции введите '0' \n";
        char func;
        cin >> func;
        switch (func) { //Свич-кейс для выбора действия с двумя объектами класса Fraction 
        case '-':
            difference(num_1, dom_1, num_2, dom_2);
            break;
        case '+':
            sum(num_1, dom_1, num_2, dom_2);
            break;
        case '*':
            product(num_1, dom_1, num_2, dom_2);
            break;
        case ':':
            division(num_1, dom_1, num_2, dom_2);
                break;
        case '0':
            flag = false;
            break;
        default:
            cout << "ошибка: неверно введена операция\n";
            break;
        }
    }
    cout << "=================" << '\n';
}

int main() {
    bool flag;
    flag = true;
    while (flag == true) {
        cout << "1 - Функция анализатора\n2 - Функция калькулятора\n3 - Остановка функции" << '\n';
        int which_function;
        cin >> which_function;
        if (which_function == 1) analyze_function();
        else if (which_function == 2) calculator();
        else if (which_function == 3) flag = false;
        else cout << "Введенные данные некоректны, проверьте написание";
    }
    return 0;
}
#include <iostream> 
#include <string> 
#include <math.h> 
using namespace std;

class Fraction
{
private:
    int numerator, denominator;
public:
    Fraction()
    {
        numerator = 1;
        denominator = 1;
    }
    Fraction(int n, int d) //Инициализация объекта класса Fraction с двумя параметрами numerator - числитель, denominator - знаменатель
    {
        numerator = n;
        if (d == 0)
        {
            cout << "ошибка: деление на ноль" << endl;
            exit(0);
        }
        else
            denominator = d;
    }
    Fraction Sum(Fraction otherFraction) //Функция класса Fraction, для сложения одного объекта этого класса с другим
    {
        int n = numerator * otherFraction.denominator + otherFraction.numerator * denominator;
        int d = denominator * otherFraction.denominator;
        return Fraction(n / gcd(n, d), d / gcd(n, d));
    }
    Fraction Difference(Fraction otherFraction) //Функция класса Fraction, для вычитания одного объекта этого класса из другого
    {
        int n = numerator * otherFraction.denominator - otherFraction.numerator * denominator;
        int d = denominator * otherFraction.denominator;
        return Fraction(n / gcd(n, d), d / gcd(n, d));
    }
    Fraction Product(Fraction otherFraction) //Функция класса Fraction, для умножения двух объектов этого класса
    {
        int n = numerator * otherFraction.numerator;
        int d = denominator * otherFraction.denominator;
        return Fraction(n / gcd(n, d), d / gcd(n, d));
    }
    Fraction Division(Fraction otherFraction) //Функция класса Fraction, для деления двух объектов этого класса
    {
        int n = numerator * otherFraction.denominator;
        int d = denominator * otherFraction.numerator;
        return Fraction(n / gcd(n, d), d / gcd(n, d));
    }
    int gcd(int n, int d)
    {
        int remainder;
        while (d != 0)
        {
            remainder = n % d;
            n = d;
            d = remainder;
        }
        return n;
    }
    void show() //функция для вывода объекта, класса Fraction
    {
        if (denominator == 1)
            cout << numerator << endl;
        else
            cout << numerator << "/" << denominator << endl;
    }
};

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
    while (num_1 != num_2)
    {
        if (num_1 > num_2)
            num_1 -= num_2;
        else
            num_2 -= num_1;
    }
    return num_1;
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

    Fraction a(num_1, dom_1);
    Fraction b(num_2, dom_2);
    Fraction c;

    cout << "Какую операцию необходимо провести (- + : *)\n";
    char func;
    cin >> func;
    switch (func) { //Свич-кейс для выбора действия с двумя объектами класса Fraction 
    case '-':
        c = a.Difference(b);
        break;
    case '+':
        c = a.Sum(b);
        break;
    case '*':
        c = a.Product(b);
        break;
    case ':':
        c =
            a.Division(b);
        break;
    default:
        cout << "ошибка: неверно введена операция\n";
        break;
    }

    cout << num_1 << '/' << dom_1 << ' ' << func << ' ' << num_2 << '/' << dom_2 << " = ";
    c.show();
}

int main() {
    bool flag;
    flag = true;
    while (flag == true) {
        cout << "1 - Функция анализатора\n2 - Функция калькулятора\n3 - Стоп" << '\n';
        int which_function;
        cin >> which_function;
        if (which_function == 1) analyze_function();
        else if (which_function == 2) calculator();
        else if (which_function == 3) flag = false;
        else cout << "Введенные данные некоректны, проверьте написание";
    }
    return 0;
}
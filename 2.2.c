#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
/*
*@brief Рассчитывает значение функции по заданным условиям
*@param x входное значение аргумента
*@return возвращает рассчитанное значение выбранной функции
*/
double Func(const double x);
/*
*@brief Считывает значение, введенное с клавиатуру с проверкой ввода
*@return считанное значение
*/
double Value();
/*
*@brief Точка входа в программу
*@param x выбранный пользователем значение аргумента
*@return Возвращает 0, если программа выполнена корректно
*/
int main()
{
    printf("Программа для решения функции y:\n");
    printf("y = a * x^(2*ln(x)), при 1 <= x <= 2\n");
    printf("y = 1, при x < 1\n");
    printf("y = e^(a*x) * cos(x), при x > 2\n");
    printf("Константа a = 2.0\n\n");
    printf("Введите значение:");
    double x = Value();
    double result = Func(x);
    printf("Результат: y(%.2f) = %.2f\n", x, result);
    return 0;
    
}

double Func(const double x)
{
    const double a = 2.0;
    
    if (x < 1.0 - DBL_EPSILON)
    {
        
        return 1.0;
    }
    else if (x >= 1.0 - DBL_EPSILON && x <= 2.0 + DBL_EPSILON)
    {
        
        return a * pow(x, 2.0 * log(x));
    }
    else 
    {
        
        return exp(a * x) * cos(x);
    }
}

double Value()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Ошибка! Введено неверное значение!\n");

        abort();
    }
    return value;
}

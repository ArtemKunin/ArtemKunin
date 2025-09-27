#include <stdio.h>
#include <math.h>
/*
*@brief Рассчитывает значение функции по заданным условиям
*@param x входное значение аргумента
*@return возвращает рассчитанное значение выбранной функции
*/
double func(const double x);
/*
*@brief Точка входа в программу
*@param x выбранный пользователем значение аргумента
*@return Возвращает 0, если программа выполнена корректно
*/
int main()
{
    printf("Программа для решения функции y\n");
    printf("y = a * x^(2*ln(x)), при 1 <= x <= 2\n");
    printf("y = 1, при x < 1\n");
    printf("y = e^(a*x) * cos(x), при x > 2\n");
    printf("Константа a = 2.0\n\n");
    double x;
    printf("Введите значение:");
    if (scanf("%lf",&x) != 1)
    {
        printf("Введено неверное значение!\n");
        return 0;
    }
    if (x >= 1 && x <= 2)
    {
        printf("Использована формула: y = a * x^(2*ln(x))\n");
        printf("Итоговое значение:\n");
        printf("x = %.2f\n",x);
        printf("y = %lf\n",func(x));
    
    }
    else if (x > 2)
    {
        printf("Использована формула: y = e^(a*x) * cos(x)\n");
        printf("Итоговое значение:\n");
        printf("x = %.2f\n",x);
        printf("y = %lf\n",func(x));
    }
    else
    {
        printf("Использована формула: y = 1\n");
        printf("Итоговое значение:\n");
        printf("x = %.2f\n",x);
        printf("y = %lf\n",func(x));
    }
    return 0;
}
double func(const double x)
{
    const double a = 2;
    if (x < 1)
    {
        return 1.0;
    }
    if (x >= 1 && x <= 2)
    {
        return a * pow(x,2*log(x));
    }
    else
    {
        return exp(a*x) * cos(x);
    }
}

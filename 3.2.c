#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief считывает целое значение введенное с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
int Value();

/**
 * @brief считывает вещественное значение введенное с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
double Double();

/**
 * @brief рассчитывает сумму n членов последовательности
 * @param n - заданное число членов
 * @return рассчитанное значение
 */
double SumN(const int n);

/**
 * @brief рассчитывает сумму членов последовательности, с точностью e
 * @param e - заданная точность
 * @return рассчитанное значение
 */
double SumE(const double e);

/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс
 * @return рассчитанное значение коэффициента
 */
double Recurent(const int i);

/** 
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    printf("Введите n:");
    int n = Value();
    checkPositive(n);
    printf("Сумма %d чисел последовательности равна %.4lf\n",n,SumN(n));
    printf("Введите e:");
    double e = Double();
    checkPositive(e);
    printf("Сумма последовательности с точностью %lf равна %.4lf\n", e,SumE(e));

    return 0;
}

int Value()
{
    int value = 0;
    if (!scanf("%d", &value))
    {
        printf("Ошибка! Введено неверное значение.\n");
        exit(1);
    }
    return value;
}

double Double()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Ошибка! Введено неверное значение.\n");
        exit(1);
    }
    return value;
}

double SumN(const int n)
{
    double current = 1.0; 
    double result = current;
    for (int i = 0; i < n-1; i++ )
    {
        current *= Recurent(i);
        result += current;
    }
    return result;
}

double Recurent(const int i)
{
    return -1.0 / ((i + 1) * (i + 2));
}

void checkPositive(const double value)
{
    if (!(value > 0))
    {
        printf("Ошибка, число должно быть положительным!\n");
        exit(1);
    }
}

double SumE(const double e)
{
    double current = 1.0;
    double result = 0;
    for (int i = 0; fabs(current) > e; i++)
    {
        result += current;
        current*=Recurent(i);
    }
    return result;
}

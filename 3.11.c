#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>
/**
*@brief Считывает значение, введенное с клавиатуры с проверкой ввода
*@return считанное значение
*/
double value();
/**
*@brief Рассчитывает значение по заданной функции
*@param x значение
*@return рассчитанное значение
*/
double func(const double x);
/**
 * @brief проверяет, что шаг не нулевой
 * @param step значение шага
 */
void steps(const double step);
/**
 * @brief проверяет, следует ли продолжать табулирование
 * @param x текущее значение x
 * @param end конечное значение
 * @param step шаг табулирования
 * @return true если следует, иначе false
 */
bool cont(const double x,const double end,const double step);
/**
 * @brief Точка входа в программу
 * @param start выбранное пользователем начальное значение функции
 * @param end выбранное пользователем конечное значение функции
 * @param step выбранный пользователем шаг функции
 * @return возвращает 0, если программа выполнена корректно, иначе 0
 */
int main()
{
    printf("Введите начальное значение:");
    double start = value();
    printf("Введите конечное значение:");
    double end = value();
    printf("Введите шаг:");
    double step = value();
    steps(step);
    double x = start;
    while (cont(x,end,step))
    {
        printf("x = %.2lf, y = %.4lf\n",x,func(x));
        x = x + step;
    }
    return 0;
}
double value()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Вы ввели неверное значение!\n");
        abort();
    }
    return value;
}
void steps(const double step)
{
    if (fabs(step) <= DBL_EPSILON)
    {
        printf("Шаг не должен быть нулевым!\n");
        abort();
    }
}
double func(const double x)
{
    return 0.29 * pow(x,3) + x - 1.2502;
}
bool cont(const double x,const double end,const double step) 
{
    if (step > 0) 
    {
        return x < end + DBL_EPSILON;
    } 
    else 
    {
        return x > end - DBL_EPSILON;
    }
}

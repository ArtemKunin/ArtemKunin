#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
/*
*@brief Рассчитывает периметр треугольника
*@param x первый катет треугольника
*@param y второй катет треугольника
*@return возвращает рассчитанный периметр
*/
double getper(const double x, const double y);
/*
*@brief Рассчитывает площадь треугольника
*@param x первый катет треугольника
*@param y второй катет треугольника
*@return возвращает рассчитанную площадь
*/
double getplo(const double x, const double y);
/**
@brief perimetr - периметр треугольника
@brief ploshad - площадь треугольника
*/
enum {perimetr,ploshad};
/*
*@brief Считывает значение, введенное с клавиатуру с проверкой ввода
*@return считанное значение
*/
double value();
/*
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkvalue(const double value);
/*
*@brief Точка входа в программу
*@param x выбранный пользователем первый катет
*@param y выбранный пользователем второй катет
*@return возвращает 0, если программа выполнена корректно
*/
int main()
{
    printf("Введите длину первого катета:");
    double x = value();
    checkvalue(x);
    printf("Введите длину второго катета:");
    double y = value();
    checkvalue(y);
    printf("Выберите, что хотите посчитать: %d - периметр, %d - плоащдь\n",perimetr,ploshad);
    int choice = (int) value();
    switch (choice)
    {
        case perimetr:
            printf("Периметр равен %.2lf\n",getper(x,y));
            break;
        case ploshad:
            printf("Площадь равна %.2lf\n",getplo(x,y));
            break;
        default:
            printf("Вы ввели неверное значение!");
            abort();
    }
    
    return 0;
    
}
double value()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Ошибка! Введено неверное значение!\n");
        abort();
    }
    return value;
}
void checkvalue(const double value)
{
    if (value <= 0 + __DBL_EPSILON__ )
    {
        printf("Число должно быть положительным!\n");
        abort();
    }
}
double getper(const double x, const double y)
{
    return (x + y) + sqrt(pow(x, 2) + pow(y, 2));
}
double getplo(const double x,const double y)
{
    return 1.0 / 2 * x * y;
}

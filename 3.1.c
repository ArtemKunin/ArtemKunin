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
*@param x значение переменной
*@return рассчитанное значение переменной
*/
double func(const double x);
/**
 * @brief проверяет,что переменная положительная
 * @param step значение проверяемой переменной
 */
void steps(const double step);
/**
 * @brief проверяет, принадлежит ли значение аргумента функции
 * её области определения
 * @param x - аргумент функции
 * @return true, если аргумент принадлежит ООФ, иначе false
 */
bool check(const double x);
/**
 * @brief Точка входа в программу
 * @param start начальное значение функции
 * @param end конечное значение функции
 * @param step значение шага функции
 * @return 0, если программа выполнена корректно, иначе 1
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
    while (x < end + DBL_EPSILON)
	{
		if (check(x))
		{
			printf("x = %.2lf, y = %.4lf\n", x, func(x));
		}
		else
		{
			printf("x = %.2lf, не принадлежит области определения функции\n", x);
		}
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
    if (step <= DBL_EPSILON)
	{
		printf("Ошибка! Шаг должен быть положительным!\n");
		abort();
	}
}
double func(const double x)
{
    return 0.29 * pow(x,3) + x - 1.2502;
}
bool check(const double x)
{
	return x >= 0;
}

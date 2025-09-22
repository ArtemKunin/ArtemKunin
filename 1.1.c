#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
/*
* @brief Рассчитывает функцию A по заданной формуле
* @param x значение параметра x
* @param y значение параметра y
* @return рассчитанное значение
*/
double getA(const double x, const double y);
/*
* @brief Рассчитывает функцию B по заданной формуле
* @param x значение параметра z
* @return рассчитанное значение
*/
double getB(const double z);
/*
*  @brief Точка входа в программу
* @return Возвращение в 0, если программа выполнена корректно
*/
int main()
{
	const double x = 1.426;
	const double y = -1.22;
	const double z = 3.5;
	printf("A = %lf\n", getA(x, y));
	printf("B = %lf\n", getB(z));

	return 0;
}
double getA(const double x, const double y)
{
	return 2 * cos(x - M_PI / 6) / ((1.0 / 2) + pow(sin(y), 2));
}
double getB(const double z)
{
	return 1.0 + (pow(z, 2) / (3.0 + pow(z, 2) / 5.0));
}

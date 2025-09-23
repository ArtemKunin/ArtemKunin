#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
/*
*@brief Расссчитывает площадь грани куба
*@param x длина ребра
*@return возвращает рассчитанное значение площади грани куба
*/
double plgr(const double x);
/*
*@brief Расссчитывает площадь полной поверхности куба
*@param x длина ребра
*@return возвращает рассчитанное значение площади полной поверхности куба
*/
double plp(const double x);
/*
*@brief Расссчитывает объём куба
*@param x длина ребра
*@return возвращает рассчитанное значение объема куба
*/
double ob(const double x);
/*
*@brief Точка входа в программу
*@param x выбранный пользователем длина ребра
*@return возвращает 0, если программа выполнена корректно
*/
int main()
{
    double x;
    printf("Введите значение:");
    scanf("%lf",&x);
    printf("Площадь грани равна %.2lf\n",plgr(x));
    printf("Площадь полной поверхости равна %.2lf\n",plp(x));
    printf("Площадь грани равна %.2lf\n",ob(x));
    return 0;
}
double plgr(const double x)
{
    return pow(x,2);
}
double plp(const double x)
{
    double pl;
    pl = pow(x,2);
    return pl * 6;
}
double ob(const double x)
{
    return pow(x,3);
}

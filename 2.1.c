#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
/*
*@brief Рассчитывает периметр треугольника
*@param x первый катет треугольника
*@param y второй катет треугольника
*@return возвращает рассчитанный периметр
*/
double getPer(const double x, const double y);
/*
*@brief Рассчитывает площадь треугольника
*@param x первый катет треугольника
*@param y второй катет треугольника
*@return возвращает рассчитанную площадь
*/
double getPlo(const double x, const double y);
/*
*@brief Точка входа в программу
*@param x выбранный пользователем первый катет
*@param y выбранный пользователем второй катет
*@param choice выбранный пользователем параметр выбора периметра или площади
*@return ввозвращает 0, если программа выполнена корректно
*/
int main()
{
    double x;
    double y;
    int choice;
        printf("Выберите, что хотите посчитать:\nПеример - 1\nПлощадь - 2\n");
    scanf("%d", &choice);
        if (choice == 1)
    {
        printf("Введите данные:\n");
        printf("Первый катет:");
        scanf("%lf", &x);
        printf("Второй катет:");
        scanf("%lf", &y);
        printf("Периметр треугольника равен %.2lf\n", getPer(x, y));
    }
    else if (choice == 2)
    {
        printf("Введите данные:\n");
        printf("Первый катет:");
        scanf("%lf",&x);
        printf("Второй катет:");
        scanf("%lf",&y);
        printf("Площадь треугольника равен %.2lf!\n",getPlo(x,y));
    }
    else
    {
        printf("Неверный выбор!\n");
    }
    return 0;
}
double getPer(const double x, const double y)
{
    return (x + y) + sqrt(pow(x, 2) + pow(y, 2));
}
double getPlo(const double x,const double y)
{
    return 1.0 / 2 * x * y;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define scanf_s scanf

/**
 * @brief Получение целочисленного значения от пользователя
 * @return Введенное значение
 */
int Value();

/**
 * @brief Получение размера массива
 * @return Размер массива
 */
size_t getSize();

/**
 * @brief Заполнение массива с клавиатуры
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillArray(int* arr, size_t size);

/**
 * @brief Заполнение массива случайными числами в диапазоне [-15;15]
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillRandom(int* arr, size_t size);

/**
 * @brief Вывод массива на экран
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void printArray(int* arr, size_t size);

/**
 * @brief Нахождение произведения четных элементов массива
 * @param arr Указатель на массив
 * @param size Размер массива
 * @return Произведение четных элементов
 */
int productEven(int* arr, size_t size);

/**
 * @brief Замена элементов с нечетными индексами на квадраты их индексов
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void replaceOddIndex(int* arr, size_t size);

/**
 * @brief Проверка наличия положительных элементов, делящихся на k с остатком 2
 * @param arr Указатель на массив
 * @param size Размер массива
 * @param k Делитель
 * @return 1 - если есть такие элементы, 0 - если нет
 */
int checkPositiveRemainder(int* arr, size_t size, int k);

enum {RANDOM = 1, MANUAL};
/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    printf("Введите размер массива:  ");
    size_t size = getSize();
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Ошибка!");
        exit(1);
    }
    printf("Выберите способ заполнения массива:\n"
           "%d - случайными числами, %d - вручную: ", RANDOM, MANUAL);
    int choice = Value();
    switch(choice)
    {
        case RANDOM:
            fillRandom(arr, size);
            break;
        case MANUAL:
            fillArray(arr, size);
            break;
        default:
            printf("Ошибка");
            free(arr);
            exit(1);
    }

    printf("Исходный массив: ");
    printArray(arr, size);
    
    int product = productEven(arr, size);
    printf("\n1. Произведение четных элементов: %d", product);
    
    replaceOddIndex(arr, size);
    printf("\n2. Массив после замены элементов с нечетными индексами: ");
    printArray(arr, size);
    
    printf("\n3. Введите число k: ");
    int k = Value();
    int result = checkPositiveRemainder(arr, size, k);
    
    switch(result)
    {
        case 1:
            printf("   Есть положительные элементы, делящиеся на %d с остатком 2", k);
            break;
        case 0:
            printf("   Нет положительных элементов, делящихся на %d с остатком 2", k);
            break;
    }
    
    free(arr);
    return 0;
}

int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("Ошибка!\n");
        abort();
    }
    return value;
}

size_t getSize()
{
    int value = Value();
    if (value <= 0)
    {
        printf("Ошибка!");
        abort();
    }
    return (size_t)value;
}

void fillArray(int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент:");
        arr[i] = Value();
    }
}

void fillRandom(int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % 31) - 15;
    }
}

void printArray(int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int productEven(int* arr, size_t size)
{
    int product = 1;
    int found = 0;
    
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            product = product * arr[i];
            found = 1;
        }
    }
    
    if (found == 1)
    {
        return product;
    }
    else
    {
        return 0;
    }
}

void replaceOddIndex(int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (i % 2 == 1)
        {
            arr[i] = i * i;
        }
    }
}

int checkPositiveRemainder(int* arr, size_t size, int k)
{
    if (k == 0)
    {
        printf("Ошибка: деление на ноль\n");
        return 0;
    }
    
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0 && arr[i] % k == 2)
        {
            return 1;
        }
    }
    
    return 0;
}

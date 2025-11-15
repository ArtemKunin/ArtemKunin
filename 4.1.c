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
 * @param message сообщение пользователю
 * @return Размер массива
 */
size_t getSize(char* message);

/**
 * @brief Заполнение массива с клавиатуры
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillArray(int* arr,const size_t size);

/**
 * @brief Заполнение массива случайными числами в диапазоне [-15;15]
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillRandom(int* arr,const size_t size);

/**
 * @brief Вывод массива на экран
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void printArray(const int* arr,const size_t size);

/**
 * @brief Нахождение произведения четных элементов массива
 * @param arr Указатель на массив
 * @param size Размер массива
 * @return Произведение четных элементов
 */
int PolElements(const int* arr, const size_t size);

/**
 * @brief Замена элементов с нечетными индексами на квадраты их индексов
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void Odd(int* arr,const size_t size);

/**
 * @brief Проверка наличия положительных элементов, делящихся на k с остатком 2
 * @param arr Указатель на массив
 * @param size Размер массива
 * @param k Делитель
 * @return 1 - если есть такие элементы, 0 - если нет
 */
int Positive(const int* arr,const size_t size,const int k);
/**
 * @brief RANDOM - Зполнение рандомными элементами
 * @brief MANUAL - Зполнение вручную
 */
enum {RANDOM = 1, MANUAL};
/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    size_t size = getSize("Введите размер массива:");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Ошибка!");
        exit(1);
    }
    printf("Выберите способ заполнения массива:\n"
           "%d - случайными числами, %d - вручную:", RANDOM, MANUAL);
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
            printf("Ошибка!\n");
            free(arr);
            exit(1);
    }

    printf("Исходный массив: ");
    printArray(arr, size);
    int product = PolElements(arr, size);
    Odd(arr, size);
    printf("\n2. Массив после замены элементов с нечетными индексами: ");
    printArray(arr, size);
    printf("\n3. Введите число k: ");
    int k = Value();
    int result = Positive(arr, size, k);
    if (result == 1)
    {
        printf("Есть положительные элементы, делящиеся на %d с остатком 2\n", k);
    }
    else
    {
        printf("Нет положительных элементов, делящихся на %d с остатком 2\n", k);
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

size_t getSize(char* message)
{
    printf("%s",message);
    int value = Value();
    if (value <= 0)
    {
        printf("Ошибка!\n");
        abort();
    }
    return value;
}

void fillArray(int* arr,const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент:");
        arr[i] = Value();
    }
}

void fillRandom(int* arr,const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % 31) - 15;
    }
}

void printArray(const int* arr,const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int PolElements(const int* arr, const size_t size)
{
    int product = 0;
    int found = 0;
    int i;
    printf("Четные элементы массива: ");
    for (i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0 && arr[i] != 0)
        {
            printf("%d ", arr[i]);
            found = 1;
        }
    }
    
    if (found == 0)
    {
        printf("Нет четных элементов");
        return 0;
    }
    printf("\n");
    printf("1. Произведение четных элементов:");
    found = 0; 
    for (i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            if (found == 0) 
            {
                printf("%d", arr[i]);
                product = arr[i];
                found = 1;
            }
            else 
            {
                printf(" * %d", arr[i]);
                product = product * arr[i];
            }
        }
    }
    
    printf(" = %d\n", product);
    return product;
}

void Odd(int* arr,const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (i % 2 == 1)
        {
            arr[i] = i * i;
        }
    }
}

int Positive(const int* arr,const size_t size,const int k)
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

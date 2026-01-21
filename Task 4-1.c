//Variant 14

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @enum Для выбора типа заполнения
 */
enum {
    fill_random = 1,
    fill_manual = 2,
};

/**
 * @enum Для выбора операции
 */
enum {
    sum_1_dig = 1, 
    reverse_ = 2, 
    find_last_pair_ = 3 
};

/**
 * @brief Считывает введённое значение с клавиатуры
 * @return Считанное значение
 */
int get_val();

/**
 * @brief Проверяет массив на ошибку выделения памяти
 * @param arr Массив, который проверяем
 */
void is_array(const int *arr);

/**
 * @brief Заполняет массив введёнными элементами
 * @param len Длина массива
 * @param arr Массив, который заполняет
 */
void fill_manual(const size_t len, int *array);

/**
 * @brief Заполняет массив случаныйми элементами из заданного промежутка
 * @param len Длина массива
 * @param arr Массив, который заполняет
 */
void fill_random(const size_t len, int *array);

/**
 * @brief Функция вывода массива
 * @param arr Массив
 * @param len Длина массива
 */
void print_arr(const int *arr, const size_t len);

/**
 * @brief Ищет сумму элементов, значения которых состоит из одной цифры
 * @param arr Массив
 * @param len Длина массива
 * @return Возвращает сумму элементов
 */
int sum_1dig(const int *arr, const size_t len);

/**
 * @brief Функция копирует массив
 * @param copied_arr Копия массива pasted_arr
 * @param pasted_arr Массив который копируют
 * @param len Длина массива
 */
void copy_paste_arr(int *copied_arr, const int *pasted_arr, const size_t len);

/**
 * @brief Выводит массив, в котором развёрнуты элементы
 * @param arr Массив
 * @param len Длина массива
 */
void reverse_arr(int *arr, const size_t len);

/**
 * @brief Ищет номер последней пары соседних элементов с одинаковыми знаками, произведение которых меньше заданного числа
 * @param arr Массив
 * @param len Длина массива
 * @return Возвращает номер последней пары соседних элементов с одинаковыми знаками, произведение которых меньше заданного числа
 */
int last_pair(const int *arr, const size_t length);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main(void) {
    setlocale(LC_ALL, "RU");

    printf("Количество элементов в массиве:\n");

    size_t len = get_val();

    if (len <= 0) {
        fprintf(stderr, "Error: кол-во элементов <= 0, должно быть > 0");
        return 1;
    }

    int *arr = (int*)malloc((size_t)len * sizeof(int));
    is_array(arr);

    printf("Способ заполнения\n");
    printf("%d - Заполнить случайными числами\n", fill_random);
    printf("%d - Заполнить вручную\n", fill_manual);
    printf("Выбор %d/%d: ", fill_random, fill_manual);

    int mode = get_val();

    switch (mode) {
        case fill_random: {
            printf("Random\n");
            fill_random(len, arr);
            break;
        }
        case fill_manual: {
            printf("Manual\n");
            fill_manual(len, arr);
            break;
        }
        default: {
            fprintf(stderr, "Exit: error choice\n");
            free(arr);
            return 1;
        }
    }
    printf("\nСформированный массив:\n");
    print_arr(arr, len);

    printf("%d - Найти сумму элементов, значения которых состоят из одной цифры\n", sum_1_dig);
    printf("%d - Заменить элементы массива между минимальным и максимальным на те же элементы в обратном порядке\n", reverse_);
    printf("%d - Найти номер последней пары соседних элементов с одинаковыми знаками, произведение которых меньше заданного числа\n", find_last_pair_);

    printf("Выбор %d/%d/%d: ", sum_1_dig, reverse_, find_last_pair_);

    int task = get_val();

    switch (task) {
        case sum_1_dig: {
            sum_1dig(arr, len);
        }
        case reverse_: {
            reverse_arr(arr, len);
        }
        case find_last_pair_: {
            last_pair(arr, len);
        }
        default: {
            free(arr);
            return 1;
        }
    }

    return 0;
}

int get_val() {
  int val = 0;
  if (!(scanf("%d", &val) == 1)) {
    fprintf(stderr, "Error\n");
    exit(1);
  }
  return val;
}

void is_array(const int *arr) {
  if (arr == NULL) {
    fprintf(stderr, "Не выделилась память\n");
    exit(1);
  }
}

void fill_manual(const size_t len, int *array) {
    is_array(array);
    printf("Введите каждый элемент массива (%d):\n", len);
    for (size_t i = 0; i < len; i++) {
        printf("Элемент %d: ", i);
        array[i] = get_val();
    }
}

void fill_random(const size_t len, int *arr) {
    is_array(arr);
    printf("\nДиапазон для случайных чисел\n");

    printf("\nМинимальное значение:\n");
    int min = get_val();

    printf("\nМаксимальное значение:\n");
    int max = get_val();

    if (min > max) {
        fprintf(stderr, "Error: min > max\n");
        return;
    }
    
    printf("Диапазон [%d; %d]...\n", min, max);
    
    for (size_t i = 0; i < len; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void print_arr(const int *arr, const size_t len) {
    is_array(arr);
    printf("[");
    if (len > 0) {
        printf("%d", arr[0]);
        for (size_t i = 1; i < len; i++) {
            printf(", %d", arr[i]);
        }
    }
    printf("]\n");
}

int sum_1dig(const int *arr, const size_t len) {
    is_array(arr)
    int sum = 0;
    for (size_t i = 0; i < len; i++) {
        int num = arr[i];
        if (num < 0) num = -num;
        if (num <= 9) {
            sum += arr[i];
        }
    }
    printf("Результат: %d", sum);
    return sum;
}

int last_pair(const int *arr, const size_t len) {
    is_array(arr);
    printf("Введите число, по которому будет производиться поиск пары\n");
    int num = get_val();
    if (num < 0) {
        fprintf(stderr, "Введеное число < 0, должно быть > 0\n");
        exit(1);
    }
    for (size_t i = len - 1; i > 0; i--) {
        if ((arr[i] * arr[i - 1] < num) &&
            ((arr[i] < 0 && arr[i - 1] < 0) || (arr[i] > 0 && arr[i - 1] > 0))) {
        return i;
        }
    }
    printf("Такой пары нет\n");
    return -1;
}

void copy_paste_arr(int *copied_arr, const int *pasted_arr, const size_t len) {
    is_array(copied_arr);
    is_array(pasted_arr);
    for (size_t i = 0; i < len; i++) {
        copied_arr[i] = pasted_arr[i];
    }
}

void reverse_arr(int *arr, const size_t len) {
    is_array(arr);
    if (len < 3) {
        fprintf(stderr, "В массиве недостаточно элементов для замены элементов");
        exit(1);
        return;
    }

    int *sec_arr = (int*)malloc(sizeof(int) * len);
    is_array(sec_arr);
    copy_paste_arr(sec_arr, arr, len);
    int min_i = 0;
    int max_i = 0;

    for (size_t i = 1; i < len; i++) {
        if (arr[i] < arr[min_i]) {
            min_i = i;
        }
        if (arr[i] > arr[max_i]) {
            max_i = i;
        }
    }

    int left = 0;
    int right = 0;

    if (min_i < max_i) {
        left = min_i;
        right = max_i;
    } else {
        left = max_i;
        right = min_i;
    }

    for (size_t i = left + 1, j = right - 1; i < j; i++, j--) {
        int temp = sec_arr[i];
        sec_arr[i] = sec_arr[j];
        sec_arr[j] = temp;
    }

    print_arr(sec_arr, len);
    free(sec_arr);
}

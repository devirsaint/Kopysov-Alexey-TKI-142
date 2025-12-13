// вариант 14
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Рассчитывает количество отрицательных чисел
 * @param a Первое число
 * @param b Второе число
 * @param c Третье число
 * @return Возвращает количество отрицательных чисел
 */

double count_nums(const double a, const double b, const double c);

/**
 * @brief Рассчитывает абсолютное значение суммы трёх чисел
 * @param a Первое число
 * @param b Второе число
 * @param c Третье число
 * @return Возвращает абсолютное значение трёх чисел
 */
double abs(const double a, const double b, const double c);

/**
 * @brief Считывает значение, введенное с клавиатуры с проверкой ввода
 * @return Считанное значение
 */
const double get_val();

/**
 * @brief Точка входа в программу
 * @return Возвращает 0 если все работает
 */
int main(void) {
  printf("Введите значения a,b,c: \n");
  double a = get_val();
  double b = get_val();
  double c = get_val();
  printf("Количество отрицательных чисел равно: %2.lf\n", count_nums(a, b, c));
  printf("Абсолютное значение суммы чисел равно: %2.lf\n", abs(a, b, c));
  return 0;
}

double count_nums(const double a, const double b, const double c) {
  int i = 0;
  if (a < 0) {
    i++;
  }
  if (b < 0) {
    i++;
  }
  if (c < 0) {
    i++;
  }
  return i;
}

double abs(const double a, const double b, const double c) {
  return fabs(a + b + c);
}

const double get_val() {
  double value = 0;
  if (!scanf("%lf", &value)) {
    printf("Error\n");
    exit(1);
  }
  return value;
}

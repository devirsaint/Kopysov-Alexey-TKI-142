// Var 14 
#include <locale.h> 
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Считывает значение, введенное с клавиатуры с проверкой ввода
 * @return Возвращает значение
 */
double get_value();

/**
 * @brief Проверяет, если переменная > 0
 * @param step Значение проверяемой переменной
 */
void is_step(const double step);

/**
 * @brief Проверяет, находится ли значение x в области определения
 * @param x - аргумент функции
 * @return Возвращает true, если аргумент принадлежит ОДЗ, false если не принадлежит
 */
bool is_dof(const double x);

/**
 * @brief Рассчитывает значение y от x
 * @param x - аргумент функции
 * @return
 */
double get_y(const double x);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void) {
  setlocale(LC_ALL, "Russian");

  printf("Начальное значение: ");
  double start = get_value();

  printf("Конечное значение: ");
  double end = get_value();

  printf("Шаг: ");
  double step = get_value();

  is_step(step);

  for (double x = start; x < end + 1e-12; x += step) {
    if (is_dof(x)) {
      printf("x = %.2lf, y = %.4lf\n", x, get_y(x));
    } else {
      printf("x = %.2lf, не принадлежит области определения\n", x);
    }
  }
  return 0;
}

double get_value() {
  double value = 0;
  if (!scanf("%lf", &value)) {
    printf("Error\n");
    exit(1);
  }
  return value;
}

void is_step(const double step) {
  if (step <= 1e-12) {
    printf("Шаг должен быть больше 0\n");
    exit(1);
  }
}

bool is_dof(const double x) 
{ 
    return ((x <= 1) && (fabs(cos(x)) > 1e-12));
}

double get_y(const double x) 
{ 
    return (sqrt(1 - x) - tan(x)); 
}

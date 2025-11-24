#include <stdio.h>
#include <math.h>

#ifndef EXP
#define EXP 2.718
#endif

/**
 * @brief прототип функции А, рассчитывает первую формулу
 * @param x - константа x (первое число)
 * @param y - константа y (второе число)
 * @param z - константа z (третье число)
 */
double get_sol_a(double x, double y, double z);
/**
 * @brief прототип функции B, рассчитывает вторую формулу
 * @param x - константа x (первое число)
 * @param y - константа y (второе число)
 * @param z - константа z (третье число)
 */
double get_sol_b(double x, double y, double z);

/**
 * @brief точка входа в программу
 * @return Возвращает 0 если все работает
 */
int main(void) 
{
    /*объявляем константы*/

    const double x = 0.3;
    const double y = 2.9;
    const double z = 0.5;

    /*Вывод с нужной точностью*/
    printf("A = %.4f \n", get_sol_a(x, y, z));
    printf("B = %.4f \n", get_sol_b(x, y, z));
    return 0;
}

double get_sol_a(double x, double y, double z)
{
    return ((double)pow(z, 2) * x + (double)pow(EXP, x * -1) * cos(y * x)) / (y * x - (double)pow(EXP, x * -1) * sin(y * x) + 1);
}

double get_sol_b(double x, double y, double z)
{
    return (double)exp(2 * x) * log(z + x) - (double)pow(y, 3 * x) * log(y - x);
}

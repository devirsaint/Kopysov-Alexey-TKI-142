/*Вариант 14*/

#include <stdio.h>
#include <math.h>


/* Объявляем экспоненту*/
#ifndef EXP
#define EXP 2.718
#endif

/**
 * @brief прототипы функции
 * 
 * @param x - константа x
 * @param y - константа y
 * @param z - константа z
 * 
*/

double get_sol_a(double x, double y, double z);
double get_sol_b(double x, double y, double z);

/**
 * @brief основная функцыя
 * @param x - константа x
 * @param y - константа y
 * @param z - константа z
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


/**
 * @brief функция для вычисления A
 * @param x - константа x
 * @param y - константа y
 * @param z - константа z
 */

double get_sol_a(double x, double y, double z)
{
    double a1 = (double)pow(z, 2) * x + (double)pow(EXP, x * -1) * cos(y * x);
    double a2 = y * x - (double)pow(EXP, x * -1) * sin(y * x) + 1;
    double a = a1 / a2;
    return a;
}

/**
 * @brief функцыя для вычисления B
 * @param x - константа x
 * @param y - константа y
 * @param z - константа z
 */

double get_sol_b(double x, double y, double z)
{
    double b = (double)exp(2 * x) * log(z + x) - (double)pow(y, 3 * x) * log(y - x);
    return b;
}

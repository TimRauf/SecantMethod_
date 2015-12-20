#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>

//Функция
double f(double x) { return sin(x) - pow(x,3) + 0.15*x; }        
int main() 
{
	setlocale(LC_CTYPE, "rus");
	double tmp, x0, x1, eps;
	int N;
	char y = 'y';                                      //переменная для символа продолжения работы
	while (y == 'y' || y == 'Y')                       //если пользователь ввел у или Y, продолжаем цикл
	{
		N = 0;                                         //обнуляем счетчик итераций, 
		std::cout << std::endl << "Введите eps = ";    // затем запрашиваем ввод переменных
		std::cin >> eps;   //Точность
		std::cout << "Первое начальное приближение x0 = ";
		std::cin >> x0;                                //Первое начальное приближение
		std::cout << "Второе начальное приближение x1 = ";
		std::cin >> x1;                                //Второе начальное приближение
					                                   //начинаем итерации
		while (fabs(x1 - x0)>eps) {                    //Остановимся, если |x[n]-x[n+1]|<eps
			tmp = x1;
			x1 = x1 - (x1 - x0)*f(x1) / (f(x1) - f(x0));
			std::cout << std::endl;
			std::cout << "Шаг " << N << " x = " << x1;
			x0 = tmp;
			N++;
		}
		std::cout.setf(std::ios::scientific);          //выведем результат в научном формате
		std::cout << std::endl << std::endl << "Корень x = " << x1 << " выполнено итераций N = " << N << std::endl;
		std::cout << "Проверка f(x) = " << f(x1) << std::endl; //проведем проверку полученного значения
		std::cout << std::endl << "Продолжить? (y - Да)" << std::endl;  //запрос на продолжение работы
		std::cin >> y;                                 //пользователь должен ввести символ для продолжения
	}
	std::cin.get();
	return 0;  
}

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>

//�������
double f(double x) { return sin(x) - pow(x,3) + 0.15*x; }        
int main() 
{
	setlocale(LC_CTYPE, "rus");
	double tmp, x0, x1, eps;
	int N;
	char y = 'y';                                      //���������� ��� ������� ����������� ������
	while (y == 'y' || y == 'Y')                       //���� ������������ ���� � ��� Y, ���������� ����
	{
		N = 0;                                         //�������� ������� ��������, 
		std::cout << std::endl << "������� eps = ";    // ����� ����������� ���� ����������
		std::cin >> eps;   //��������
		std::cout << "������ ��������� ����������� x0 = ";
		std::cin >> x0;                                //������ ��������� �����������
		std::cout << "������ ��������� ����������� x1 = ";
		std::cin >> x1;                                //������ ��������� �����������
					                                   //�������� ��������
		while (fabs(x1 - x0)>eps) {                    //�����������, ���� |x[n]-x[n+1]|<eps
			tmp = x1;
			x1 = x1 - (x1 - x0)*f(x1) / (f(x1) - f(x0));
			std::cout << std::endl;
			std::cout << "��� " << N << " x = " << x1;
			x0 = tmp;
			N++;
		}
		std::cout.setf(std::ios::scientific);          //������� ��������� � ������� �������
		std::cout << std::endl << std::endl << "������ x = " << x1 << " ��������� �������� N = " << N << std::endl;
		std::cout << "�������� f(x) = " << f(x1) << std::endl; //�������� �������� ����������� ��������
		std::cout << std::endl << "����������? (y - ��)" << std::endl;  //������ �� ����������� ������
		std::cin >> y;                                 //������������ ������ ������ ������ ��� �����������
	}
	std::cin.get();
	return 0;  
}

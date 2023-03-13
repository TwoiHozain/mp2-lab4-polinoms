#include <iostream>
#include "polinom.h"

using namespace std;
void main()
{
	Polynom polinom1,polinom2;
	char operation;

	try
	{
		setlocale(LC_ALL, "Russian");

		cout << "--------------------------INFO--------------------------" << endl;
		cout << "Полинов:" << endl;
		cout << "В качестве имен переменных в полиноме используются x,y,z" << endl;
		cout << "Общий вид монома в полиноме: а*x^X*y^Y*z^Z" << endl;
		cout << "Где:" << endl
			<< "\ta - вещественное число, может быть записано в кэспоненциальной форме, в качестве разделителя выступает ','" << endl
			<< "\tкоэффицент а опускать нельзя" << endl
			<< "\tX,Y и Z - числа от 0 до 9" << endl
			<< "\t ввод одинаковых мономов недопускается" << endl
			<< "\tНе обязательно что бы моном содержал все переменные " << endl
			<<"\tПорядок следованияпеременных неважен" << endl
			<< "Доступные операции: +, -, *"
			<< endl;
		cout << "--------------------------------------------------------" << endl;

		cout << endl;
		cout << "Введите первый полином: ";
		cin >> polinom1;

		cout << "Введите операцию: ";
		cin >> operation;

		cout << "Введите второй полином: ";
		cin >> polinom2;

		cout << "Полином1 "<<operation <<" Полином2 = ";
		switch (operation)
		{
		case('+'):
			cout << polinom1 + polinom2;
			break;
		case('-'):
			cout << polinom1 - polinom2;
			break;
		case('*'):
			cout << polinom1 * polinom2;
			break;
		default:
			cout << "Uncnown operation";
			break;
		}
	}
	catch (const std::exception& exc)
	{
		cout << exc.what();
	}
}
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
		cout << "�������:" << endl;
		cout << "� �������� ���� ���������� � �������� ������������ x,y,z" << endl;
		cout << "����� ��� ������ � ��������: �*x^X*y^Y*z^Z" << endl;
		cout << "���:" << endl
			<< "\ta - ������������ �����, ����� ���� �������� � ���������������� �����, � �������� ����������� ��������� ','" << endl
			<< "\t���������� � �������� ������" << endl
			<< "\tX,Y � Z - ����� �� 0 �� 9" << endl
			<< "\t ���� ���������� ������� �������������" << endl
			<< "\t�� ����������� ��� �� ����� �������� ��� ���������� " << endl
			<<"\t������� �������������������� �������" << endl
			<< "��������� ��������: +, -, *"
			<< endl;
		cout << "--------------------------------------------------------" << endl;

		cout << endl;
		cout << "������� ������ �������: ";
		cin >> polinom1;

		cout << "������� ��������: ";
		cin >> operation;

		cout << "������� ������ �������: ";
		cin >> polinom2;

		cout << "�������1 "<<operation <<" �������2 = ";
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
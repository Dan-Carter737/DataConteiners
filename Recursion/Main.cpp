#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

void Elevator(int floor);
int Factorial(int n);
double Power(double a, int n);


void main()
{
	setlocale(LC_ALL, "");

	int n;
	double a;

	cout << "������� ����� ��� ������ ��� ����������: ";cin >> n;
	cout << endl;
	cout << "!" << n << " = " << Factorial(n) << endl << endl;

	cout << "������� ����� ��� ���������� � �������: "; cin >> a;
	cout << "������� �������� ������� ��� ����� " << a << ": "; cin >> n;
	cout << a << "^" << n << " = " << Power(a, n) << endl;


	

}

void Elevator(int floor)
{
	if (floor == 0)
	{
		cout << "�� � �������" << endl;
		return;
	}
	cout << "�� �� " << floor << "����� " << endl;
	Elevator(floor - 1);
}

int Factorial(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;	 
	return n * Factorial(n - 1);	 
}

double Power(double a, int n)
{
	if (a == 0 && n < 0) return 0;
	
	if (a == 1 && n == 0) return 1;
	if (n > 1) return a * Power(a, --n);
		
}

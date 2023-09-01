#include"include/List2.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	List<int> list = { 3,5,8,13,21 };
	for (int i : list)cout << i << "\t"; cout << endl;

	List<double> d_list = { 2.7, 3.14, 5.1, 8.3 };
	for (double i : d_list)cout << i << "\t"; cout << endl;
}
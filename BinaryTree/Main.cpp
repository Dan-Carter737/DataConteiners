#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

//#define tab "\t"
#define delimiter "\n--------------------------------------------\n"

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public :
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			: Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "Econstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
	}*Root;
public:

	Tree(): Root(nullptr)
	{
		cout << "TConstructor" << this << endl;
	}
	~Tree()
	{
		cout << "TDestructor" << this << endl;
	}
	void insert()
	{

	}
};


void main()
{
	setlocale(LC_ALL, "");








}

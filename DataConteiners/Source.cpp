#include <iostream>
//using namespace std;
#define tab "\t"
using std::cin;
using std::cout;
using std::endl;

class ForwardList;
ForwardList operator+(const ForwardList& left, const ForwardList& right);

class Element
{
	int Data;
	Element* pNext;
public:
	Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;;
	}
	friend class ForwardList;
	friend class ForwardList;
	friend class Iterator;
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);


};
class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr) :Temp(Temp)
	{
		cout << "ITConstructor:\t" << this << std::endl;
	}
	~Iterator()
	{
		cout << "ITDestructor:\t" << this << std::endl;
	}
	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}
	bool operator ==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator !=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}
	int operator*()
	{
		return Temp->Data;
	}
};

class ForwardList
{
	Element* Head; // голова списка сожержит адрес начального элемента списка
public:
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	ForwardList()
	{
		Head = nullptr; //если список пуст, то его голова указывает на ноль
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	ForwardList(const std::initializer_list<int>& il) :ForwardList()
	{
		std::cout << typeid(il.begin()).name() << std::endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}

	ForwardList(const ForwardList& other) :ForwardList()
	{
		cout << "LCopyConstructor:\t" << this << endl;
		//deep copy
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
	}
	ForwardList(ForwardList&& other) :ForwardList() //ForwardList&& - rvalue reference
	{
		//this->Head = other.Head;
		//other.Head = nullptr;
		*this = std::move(other); //‘угкци€ move принудительно вызывает MoveAssignment дл€ объекта

	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

	///////////Operators


	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		cout << "LCopyAssignment:\t" << this << endl;
		//deep copy
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		return *this;
	}

	ForwardList& operator=(ForwardList&& other)
	{
		while (Head)pop_front();
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "LMoveAssignment:\t" << this << endl;
		return *this;
	}

	/////////////////////////// adding elements
	void push_front(int Data)
	{
		//Element* New = new Element(Data);
		Head = new Element(Data, Head);
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;
		Temp->pNext = new Element(Data);

	}
	void pop_front()
	{

		Element* erase = Head;
		Head = Head->pNext;
		delete erase;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
	}

	void insert(int Data, int index)
	{
		if (index == 0) return push_front(Data);
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
			if (Temp->pNext)
				Temp = Temp->pNext;
		//1) создаем новый элемент
		Element* New = new Element(Data);
		//2) 
		New->pNext = Temp->pNext;
		Temp->pNext = New;
	}

	void erase(int index)
	{
		if (index == 0)return pop_front();
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
			if (Temp->pNext)
				Temp = Temp->pNext;
		Element* erased = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete erased;
	}

	/////////// Methods

	void print()const
	{
		/*Element* Temp = Head; //Temp - это итератор
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}*/
		cout << "Head:" << Head << endl;
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;

	}
	friend class ForwardList;
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);

};
ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left;
	for (Element* Temp = right.Head; Temp; Temp = Temp->pNext)cat.push_back(Temp->Data);
	return cat;

}

//#define BASE_CHECK
//#define OPERATOR_PLUS_CHECK
//#define RAGE_BASED_FORWARD_LIST


void main()
{
	setlocale(LC_ALL, "");
#if defined BASE_CHECK
	int n;
	cout << "¬ведите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	//list.push_back(123);
	list.print();


	/*int value;
	int index;
	cout << "¬ведите индекс: "; cin >> index;
	cout << "¬ведите значение элемента: "; cin >> value;
	list.insert(value, index);
	list.print();

	cout << "¬ведите индекс: "; cin >> index;
	list.erase(index);
	list.print();*/

	/*ForwardList list2 = list;
	list2.print();*/
	ForwardList list2;
	list2 = list;
	list2.print();
#endif

#ifdef  OPERATOR_PLUS_CHECK 
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	list1.print();

	ForwardList list2;
	list1.push_back(34);
	list1.push_back(55);
	list1.push_back(89);
	list2.print();

	ForwardList list3 = list1 + list2;
	list3.print();

#endif

#ifdef RAGE_BASED_FORWARD_LIST
	ForwardList list = { 3, 5, 8, 13, 21 };
	list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
#endif


	ForwardList list1 = { 3, 5, 8, 13, 21 };
	for (int i : list1)cout << i << tab; cout << endl;

	ForwardList list2 = { 34, 55, 89 };
	for (int i : list2)cout << i << tab; cout << endl;

	ForwardList list3 = list1 + list2;
	for (int i : list3)cout << i << tab; cout << endl;

}

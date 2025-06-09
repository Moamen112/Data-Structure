#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(2);
	list.remove_value(2);
	list.print_all();


	cout << "This is the empty " << list.is_empty() << endl;
	cout << "This is the size " << list.size() << endl;
}

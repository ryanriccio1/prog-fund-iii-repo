#include <iostream>
#include "ArraySet.h"
using namespace std;


template<class ItemType>
void display(ArraySet<ItemType>& set)
{
	cout << "The bag contains " << set.getCurrentSize()
		<< " items:" << endl;
	// convert to vector and iterate through
	vector<ItemType> setItems = set.toVector();

	size_t numberOfEntries = static_cast<size_t>(setItems.size());
	for (int i = 0; i < numberOfEntries; i++)
	{
		cout << setItems[i] << " ";
	}
	cout << endl;
}

int main()
{	// test functions with int
	int num[] = { 23, 56, 38, 81, 32, 13, 1 };
	size_t size = sizeof(num) / sizeof(num[0]);
	auto intSet = ArraySet<int>(num, size);
	display<int>(intSet);
	cout << "\n(1 = true, 0 = false) Add 24: " << intSet.add(24) << endl;
	display<int>(intSet);
	cout << "\n(1 = true, 0 = false) Add 23: " << intSet.add(23) << endl;
	display<int>(intSet);
	cout << "\n(1 = true, 0 = false) Remove 23: " << intSet.remove(23) << endl;
	display<int>(intSet);
	cout << "\nClear!\n";
	intSet.clear();
	display<int>(intSet);
	cout << endl;

	// test template with different type
	const char * strings[] = { "Hi", "my", "name", "is", "Ryan" };
	size = sizeof(strings) / sizeof(strings[0]);
	auto stringSet = ArraySet<const char *>(strings, size);
	display<const char *>(stringSet);
	cout << endl;
}
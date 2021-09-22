#include <iostream>
#include <assert.h>

using namespace std;

int maxArray(const int* myArray, size_t sizeOfArray)
{	// assert on empty array
	assert(sizeOfArray != 0);
	if (sizeOfArray == 1)
		return myArray[0];

	// split left and right
	size_t leftSize = sizeOfArray / 2;
	size_t rightSize = sizeOfArray - leftSize;

	// recursively find maxes for both sides
	int leftMax = maxArray(myArray, leftSize);
	int rightMax = maxArray(myArray + leftSize, rightSize);
	
	// return and compare maxes
	if (leftMax > rightMax)
		return leftMax;
	return rightMax;

}

int main()
{
	// start recursive array and calculate size
	int startingArray[] = { 1, 2, 34, 4, 5 };
	size_t startingArraySize = sizeof(startingArray) / sizeof(startingArray[0]);
	cout << maxArray(startingArray, startingArraySize);
}
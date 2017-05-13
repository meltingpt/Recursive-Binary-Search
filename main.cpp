#include <iostream>
#include <cmath>
using namespace std;

template <class T> //Template needed so that it can search through int, double, float, or char, etc)
int binary_search(T array[], int low, int high, T target) {
	if (high >= low) {
		int middle = (low + high) / 2; //finds the middle of the array

		if (target == array[middle]) //if the target is the same position as the middle, return the index
			return middle;
		else if (target < array[middle]) //if the target is smaller/lower than the middle, go through the function again with a smaller sized array
			return binary_search(array, low, middle - 1, target); //cuts off the high positions of the array since the target is lower
		else //(target > array[middle]) if the target is larger/higher than the middle, go through the function again with a smaller sized array
			return binary_search(array, middle + 1, high, target); //cuts off the lower positions of the array since the target is higher
	}
	else
		return -1;
}

int main(int argc, char const *argv[])
{
	int iList[6] = { 1, 3, 5, 17, 23, 98 };
	double dList[6] = {0.3, 1.2, 11.3, 17.1, 18.9, 97.6};
	char cList[6] = {'a', 'c', 'f', 'j', 'o', 'z'};

	int iAns = binary_search(iList, 0, 5, 17); //target for an int
	int dAns = binary_search(dList, 0, 5, 18.9); //target is a double
	int cAns = binary_search(cList, 0, 5, 'c'); //target is a char

	cout << "Integer answer at index " << iAns << endl;
	cout << "Double answer at index " << dAns << endl;
	cout << "Char answer at index " << cAns << endl;

	return 0;
}

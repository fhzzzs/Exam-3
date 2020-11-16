#include "TArray.h"
#include "TArray.cpp"
#include <iostream>


using namespace std;

int main()
{
	TArray<int> ta1, ta2;

	ta1.insert(5);
	ta1.insert(2);
	//ta1.insert(5);				// wont insert duplicate 5
	ta1.insert(1);
	ta1.insert(7);
	ta1.insert(15);


	ta2 = ta1;					// test assignment operator
	TArray<int> ta1Copy(ta2);	// test copy constructor

	
	//if (ta1.find(7))			// test find function
	//{
	//	cout << "Found\n";
	//}
	//else
	//{
	//	cout << "Not Found\n";
	//}

	ta1.print();				// prints the array
	ta1Copy.print();			// print copy of array
	ta2.print();				// prints assigned array
	cout << ta1 << "\n";		// overloaded insertion operator

	system("pause");
	return 0;
}
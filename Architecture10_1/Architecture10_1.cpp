#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
void main()
{
	int arr[25] = { -77, -54, -50, 0, -36, 38, 33, -16, 34, -85, 90, 44, -63, 76, 9, 15, 32, -55, 29, 87, 8, -15, -48, 19, -38 };//source array
	int neg; //variable to hold the number of
	_asm
	{ //The beginning of the assembly

		pushad //Push the values of all 32-bit general
		xor edx, edx //for storage number of negative element
		lea eax, arr //eax <- pointer(arr
		mov ecx, 25 //ecx <- colCount

		_loop : //label
		push ecx //save pointer
			push eax //save pointer
			cmp[eax], 0 //comparing elements to find negative
			jl _lower //jump to label "_lower" if the elemen

			jmp _step //jump to label "step"
			_lower : //label
		inc edx //edx + 1
			jmp _step //jump to label "step"
			_step : //label
		pop eax //return pointer
			add eax, 4 //jump to the next row element
			pop ecx //return pointer
			loop _loop //until the counter is zero go to label

			mov neg, edx //neg <- edx
			popad //Extracting from the stack the values of all 32-
	}
	cout << "Array: " << endl; //output to the
	for (int i = 0; i < 25; i++, cout << endl) ///
		cout << setw(4) << arr[i] << " "; ///
	cout << "\nThe number of negative elements in the array: " << neg << endl;//output to
	//file output stream close
	system("pause");
	//system call for pause command waiting for any input
}
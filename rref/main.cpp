#include <iostream>
#include <iomanip>

#include "functions.h"

#define LOOP(i, a, b) for (int i = a; i < b; i++)
#define cap(o) o = std::toupper(o)
#define test(o) while (o!='A' && o!='B' && o!='C')

int main() {
	std::cout << "MATRIX CALCULATOR by Jack Harris" << '\n' << '\n';

	// Input values for matrix size
	int cols{ 0 };
	int row{ 0 };
	char opt;
	Manipulate m;

	std::cout << "Matrix columns: ";
	std::cin >> cols;
	std::cout << "\nMatrix rows: ";
	std::cin >> row;

	float** arr = new float* [row];

	// Create the n x m matrix
	LOOP(i, 0, row)
		arr[i] = new float[cols];

	// Enter in element values
	std::cout << "Element entry: " << '\n';
	LOOP(i, 0, row)
		LOOP(j, 0, cols) {
		std::cout << "Enter element at (" << i << ", " << j << "): ";
		std::cin >> arr[i][j];
	}
	system("CLS");

	m.printMatrix(arr, row, cols);

	std::cout << "\nSelect an operation to perform: " << '\n';
	std::cout << "\nA) Echelon Form" << '\n';
	std::cout << "B) Print Matrix" << '\n';
	// std::cout << "C) Reduced-Row Echelon Form" << '\n';

	std::cout << "\nOption: ";
	std::cin >> opt;
	cap(opt);
	test(opt) {
		std::cout << "\nError. Type appropriate letter. Try again: ";
		std::cin.clear();
		std::cin.ignore(1000000, '\n');

		std::cin >> opt;
	}
	switch (opt) {
	case 'A':
		m.echForm(arr, row, cols);
		// Print matrix
		system("CLS");
		m.printMatrix(arr, row, cols);
		break;
	case 'B':
		m.printMatrix(arr, row, cols);
		break;
	// case 'C':	

	default:
		break;
	}
	// De-allocate after code executes
	LOOP(i, 0, row)
		delete arr[i];
	delete[] arr;

	system("pause");
	return 0;
}
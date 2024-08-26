#pragma once
#define LOOP(i, a, b) for (int i = a; i < b; i++)

class Manipulate {
public:
	float** echForm(float**& matrix, int& row, int& col) {
		float constant{ 0 }; // constant to use for rref
		int colV{ 0 }; // colV acts as the first column
		int iterate{ 0 };

		LOOP(j, 0, col) // Goes through every row per column, then iterates to next column. 
		{
			std::cout << '\n';
			LOOP(i, iterate, row) { // Goes through every row element, makes necessary changes
				if (i + 1 == row) {
					break;
				}
				constant = (((-1) * (matrix[i + 1][j])) / matrix[j][j]);
				LOOP(k, 0, col) {
					matrix[i + 1][k] = matrix[j][k] * constant + matrix[i + 1][k];
				}
			}
			iterate++; // Going to next column
		}
		return matrix; // Sends the matrix back in EF
	}
	void printMatrix(float**& matrix, int& row, int& cols) {
		std::cout << "Matrix: " << '\n';
		LOOP(i, 0, row) {
			LOOP(j, 0, cols)
				std::cout << std::left << std::setw(3) << matrix[i][j] << " ";
			std::cout << '\n';
		}

	};
};

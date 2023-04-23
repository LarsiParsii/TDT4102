#include "fibonacci.h"
#include "matrix.h"
#include <iostream>
#define ARR_SIZE 10
int buf[ARR_SIZE]{};

int main()
{
	// createFibonacci();

	Matrix m1(2, 4);
	std::cout << m1.get(1, 1) << std::endl;
	
	m1.set(1, 1, 69);
	std::cout << m1.get(1, 1) << std::endl;
	
	m1.set(0, 0, 0);
	m1.set(0, 1, 1);
	m1.set(0, 2, 2);
	m1.set(0, 3, 3);
	std::cout << m1[0] << std::endl;
	std::cout << "Rows:\t " << m1.getRows() << "\nColumns: " << m1.getColumns() << std::endl;

	m1.set(1, 0, 4);
	m1.set(1, 1, 5);
	m1.set(1, 2, 6);
	m1.set(1, 3, 7);
	std::cout << "\n" << m1 << std::endl;
}
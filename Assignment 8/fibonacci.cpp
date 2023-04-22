#include "fibonacci.h"
#include <iostream>

void fillInFibonacciNumbers(int *result, int length)
{
	result[0] = 0;
	if (length == 1) {
		return;
	}
	result[1] = 1;
	
	for (int i = 2; i < length; i++)
	{
		result[i] = result[i-1] + result[i-2];
	}
}

void printArray(int *arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void createFibonacci()
{
	// 1. Spør brukeren hvor mange tall som skal genereres
	int n;
	std::cout << "How many numbers to generate? ";
	std::cin >> n;
	// 2. Alloker minne til en tabell som er stor nok til tallrekka
	int* arr_ptr = new int[static_cast<unsigned>(n)];
	// 3. Fylle tabellen med fillInFibonacciNumbers()
	fillInFibonacciNumbers(arr_ptr, n);
	// 4. Skriv ut resultatet til skjerm med printArray()
	printArray(arr_ptr, n);
	// 5. Frigjør minnet du har reservert
	delete[] arr_ptr;
	arr_ptr = nullptr;
}

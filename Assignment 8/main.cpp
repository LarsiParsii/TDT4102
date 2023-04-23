#include "fibonacci.h"
#include "matrix.h"
#include "dummy.h"
#include <iostream>

// Prototypes
void testMatrix();
void testMatrixCopy();

int main()
{
	// createFibonacci();
	// testMatrix();
	// dummyTest();
	// testMatrixCopy();
}

void testMatrix()
{
	std::cout << "--------------------" << std::endl;
	Matrix m1(2, 4);
	std::cout << m1.get(1, 1) << std::endl;

	std::cout << "--------------------" << std::endl;
	m1.set(1, 1, 69);
	std::cout << m1.get(1, 1) << std::endl;

	std::cout << "--------------------" << std::endl;
	m1.set(0, 0, 0);
	m1.set(0, 1, 1);
	m1.set(0, 2, 2);
	m1.set(0, 3, 3);
	std::cout << m1[0] << std::endl;
	std::cout << "Rows:\t " << m1.getRows()
			  << "\nColumns: " << m1.getColumns()
			  << std::endl;

	std::cout << "--------------------" << std::endl;
	m1.set(1, 0, 4);
	m1.set(1, 1, 5);
	m1.set(1, 2, 6);
	m1.set(1, 3, 7);
	std::cout << "\n"
			  << m1 << std::endl;
}

void testMatrixCopy()
{
	std::cout << "--------------------" << std::endl;
	Matrix m1(2, 3);
	m1.set(1, 1, 0);
	Matrix m2{m1};
	std::cout << m1 << std::endl;
	std::cout << m2 << std::endl;
	std::cout << "--------------------" << std::endl;
	m2.set(1, 1, 69);
	std::cout << m1 << std::endl;
	std::cout << m2 << std::endl;
	std::cout << "--------------------" << std::endl;
	m1 = m2;
	std::cout << m1 << std::endl;
	std::cout << m2 << std::endl;
}

/* TEORI
 *
 * 3b) Alle instansene av kalssen peker til samme minneadresse. Når dummyTest() er ferdig
 * går man ut av scope og instansene skal kjører destruktøren til hver klasse i motsatt rekkefølge
 * av rekkefølgen de ble kosntruert (c først, så b, så a). Når c destrueres deallokerer den minneområdet
 * som pekeren *num peker til, uten at pekeren settes til å bli en nullptr. Når b så skal destrueres
 * forsøker den å deallokere det samme minneområdet, men siden den ikke har tilgang til minnet får man en feilmelding.
 * 
*/
#include "matrix.h"
#include <cassert>

Matrix::Matrix(int nRows, int nColumns)
	: rows{nRows}, columns{nColumns}
{
	assert(nRows > 0 && nColumns > 0);
	matrix_ptr = new double[rows * columns];
}

Matrix::Matrix(int nRows)
	: Matrix{nRows, nRows}
{
}

Matrix::~Matrix()
{
	delete[] matrix_ptr;
	matrix_ptr = nullptr;
}

std::ostream &operator<<(std::ostream &os, const Matrix &m)
{
	for (int row = 0; row < m.getRows(); row++)
	{
		for (int col = 0; col < m.getColumns(); col++)
		{
			os << m.get(row, col) << " ";
		}
		os << std::endl;
	}
	return os;
}

double Matrix::get(int row, int col) const
{
	return matrix_ptr[col + row * columns];
}

void Matrix::set(int row, int col, double value)
{
	matrix_ptr[col + row * columns] = value;
}

int Matrix::getRows() const
{
	return rows;
}

int Matrix::getColumns() const
{
	return columns;
}

Matrix::Row::Row(double *row_pointer, int col)
{
	row_ptr = row_pointer;
	columns = col;
}

Matrix::Row Matrix::operator[](int row)
{
	assert(row >= 0 && row < rows);
	return Row(matrix_ptr + row * columns, columns);
}

double &Matrix::Row::operator[](int col)
{
	assert(col >= 0 && col < columns);
	return row_ptr[col];
}

std::ostream &operator<<(std::ostream &os, const Matrix::Row &row)
{
	for (int col = 0; col < row.columns; col++)
	{
		os << row.row_ptr[col] << " ";
	}
	return os;
}
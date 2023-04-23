#pragma once
#include <iostream>

class Matrix
{
private:
	int rows;
	int columns;
	double *matrix_ptr;

public:
	Matrix(int nRows, int nColumns);
	explicit Matrix(int nRows);
	~Matrix();
	friend std::ostream &operator<<(std::ostream &os, const Matrix &m);

	double get(int row, int col) const;
	void set(int row, int col, double value);
	int getRows() const;
	int getColumns() const;

	class Row
	{
	private:
		int columns;
		double *row_ptr;

	public:
		Row(double *row_pointer, int col);
		double &operator[](int col);
		friend std::ostream &operator<<(std::ostream &os, const Row &row);
	};

	Row operator[](int row);
};
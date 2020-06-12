#include "Matrix.h"
#include "iostream"
using namespace std;
// Inspiration
// 
// Method and data member should be devised in advance!!!!
Matrix::Matrix(int r, int c)
{
	m_num_row = r;
	m_num_col = c;

	m_ptr_element = new int[r*c];	
	if(!m_ptr_element)
	{
		cout << "Allocation fails!" <<endl;
	exit(0);
	}

	for (int i(0); i < r*c; i++)
	{
		*(m_ptr_element + i) = 0;
	}
	cout << "Matrix()" <<endl;
}

Matrix::~Matrix()
{
	delete []m_ptr_element; // no need to redirct to NULL because m_ptr_element will be disposed of after the temrination of programm
	cout << "~Matrix()" <<endl;
}

int Matrix::row_col_to_linear_index(int row, int col)
{
	// row anc col start counting from  1!!
	// index starting from 0;
	return row * col - 1;

}
int Matrix::linear_index_to_row_col(int linear_index, int * row_col)
{
	/* static int row_col[2]; */
	row_col[0] = (linear_index + 1) %  m_num_col; // row index starting from 1
	row_col[1] = (linear_index + 1) /  m_num_col; // column index starting from 1;

}

int Matrix::get_entry(int row, int col)
{
	return *(m_ptr_element + row_col_to_linear_index(row, col));
}

void Matrix::set_entry(int row, int col, int element)
{
	*(m_ptr_element + row_col_to_linear_index(row, col)) = element;
}


int Matrix::get_num_col()
{
	return m_num_col;
}
int Matrix::get_num_row()
{
	return m_num_row;
}

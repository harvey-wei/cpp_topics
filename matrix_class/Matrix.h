#ifndef MATRIX_H
#define MATRIX_H
class Matrix 
{
public:
	Matrix(int r = 1, int c = 1);
	~Matrix();
	int get_entry(int row, int col);
	void set_entry(int row, int col, int element);
	int get_num_col();
	int get_num_row();
private:
	int * m_ptr_element;
	int m_num_row;
	int m_num_col;
	int row_col_to_linear_index(int row, int col);
	int linear_index_to_row_col(int linear_index, int * row_col);
};
#endif

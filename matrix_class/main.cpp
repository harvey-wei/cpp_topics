#include "iostream"
#include "Matrix.h"
using namespace std;
int main()
{
	Matrix mat_1(4,5);
	int num_col = mat_1.get_num_col();
	int num_row = mat_1.get_num_row();
	for(int i(1); i <= num_row; i++)
		for(int j(1); j <= num_col;j++)
		{
			mat_1.set_entry(i,j,i+j);
		}
	
	for(int i(1); i <= num_row; i++)	
	{
		for(int j(1);j <= num_col; j++)
		{
			cout << mat_1.get_entry(i,j) << " " ;
		}

		cout << endl;
	}
	return 0;
}

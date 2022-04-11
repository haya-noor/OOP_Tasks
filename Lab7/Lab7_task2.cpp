#include<iostream>
using namespace std;

class MatrixType
{
	int rows, cols;
public:
	MatrixType()
	{
		cout << "Enter rows and colums:";
		cin >> rows >> cols;

		int** matrix;
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[rows] = new int[cols];
		}
	}
	void input()
	{
		int** matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols];
		}
		int i, j;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << "Enter row " << (i + 1) << " colum " << (j + 1) << " elements.";
				cin >> matrix[i][j];
				cout << endl;
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << matrix[i][j]<<" ";
			}
			cout << endl;
		}
	}
	
	MatrixType operator+(MatrixType& mt)
	{
		//MatrixType sum(rows, cols);
		MatrixType sum;
		if (rows == mt.rows && cols == mt.cols)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					sum.matrix[i][j] = matrix[i][j] + mt.matrix[i][j];
					return sum;
				}
			}	
		}
		else
		{
			cout << "Both the matrices are not suitable for addition.\n";
		}
	}
	MatrixType operator-(MatrixType& mt)
	{
		//MatrixType sub(rows, cols);
		MatrixType sub;
		if (rows == mt.rows && cols == mt.cols)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					sub.matrix[i][j] = matrix[i][j] - mt.matrix[i][j];
				}
			}
		}
		else
		{
			cout << "Matrices are not suitable for subtraction.\n";
		}
	}
	MatrixType operator*(MatrixType& mt)
	{
		//MatrixType mult(rows, mt.cols)
		MatrixType mult;
		if (cols == mt.rows)
		{
			for (int i = 0; i < cols; i++)
			{
				for (int j = 0; j < mt.rows; j++)
				{
					for (int k = 0; k < cols; k++)
					{
						mult.matrix[i][j] = mult.matrix[i][j] + (matrix[i][k] * matrix[k][j]);
						return mult;
					}
				}
			}
		}
		else
			cout << "Not valid for multiplication.\n";
	}
	friend ostream& operator<<(ostream& out, MatrixType& mt)
	{
		for (int i = 0; i < mt.rows; i++)
		{
			for (int j = 0; j < mt.cols; j++)
			{
				out << matrix[i][j] << " ";
			}
			out << endl;
		}
		return out;
	}
};
int main()
{
	MatrixType mt, mt2;
	mt.input();
	mt2.input();
	
	cout << endl;
	mt.operator+(mt2);
	cout << endl;
	mt.operator-(mt2);
	cout << endl;
	mt.operator*(mt2);

}

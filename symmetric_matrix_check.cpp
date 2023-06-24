#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 3;

class twoDArray {
private:
    int matrix[SIZE][SIZE];

public:
    void initialize()
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++) 
            {
                cin>>matrix[i][j];
            }
        }
    }

    void print_matrix() 
    {
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j < SIZE; j++) 
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void transpose() 
    {
        int transposed_matrix[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j < SIZE; j++) 
            {
                transposed_matrix[j][i] = matrix[i][j];
            }
        }
        memcpy(matrix, transposed_matrix, sizeof(matrix));
    }

    bool is_symmetric() 
    {
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = i + 1; j < SIZE; j++) 
            {
                if (matrix[i][j] != matrix[j][i]) 
                {
                    return false;
                }
            }
        }
        return true;
    }

    static twoDArray multiply(twoDArray& obj1, twoDArray& obj2) 
    {
        twoDArray result;
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j < SIZE; j++) 
            {
                for (int k = 0; k < SIZE; k++) 
                {
                    result.matrix[i][j] += obj1.matrix[i][k] * obj2.matrix[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    twoDArray array1;
    twoDArray array2;
    
    cout<<"Enter elements of first matrix:\n";
    array1.initialize();
    cout<<"Enter elements of second matrix:\n";
    array2.initialize();

    cout << "Array 1:" << endl;
    array1.print_matrix();

    cout << "Array 2:" << endl;
    array2.print_matrix();

    array1.transpose();
    cout << "Transpose of Array 1:" << endl;
    array1.print_matrix();

    if (array2.is_symmetric()) 
    {
        cout << "Array 2 is symmetric" << endl;
    } 
    else 
    {
        cout << "Array 2 is not symmetric" << endl;
    }

    twoDArray result_array = twoDArray::multiply(array1, array2);
    cout << "Multiplication result:" << endl;
    result_array.print_matrix();

    return 0;
}

/*
test code:
Enter elements of first matrix:
2 3 6 3 4 5 6 5 9
Enter elements of second matrix:
2 3 6 3 4 5 6 5 9
Array 1:
2 3 6 
3 4 5 
6 5 9 
Array 2:
2 3 6 
3 4 5 
6 5 9 
Transpose of Array 1:
2 3 6 
3 4 5 
6 5 9 
Array 2 is symmetric
Multiplication result:
50 48 -1776789247 
32812 51 83 
-1776788919 32847 -1776788842 
*/

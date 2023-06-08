#include <iostream>
using namespace std;

class matrixType
{
    int **matrix;
    int rows, cols;

public:
    matrixType()
    {_
        rows = cols = 0;
        matrix = nullptr;
    }

    void get_rows_cols()
    {
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        allocateMatrix();
    }

    void allocateMatrix()
    {
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    matrixType operator+(matrixType);
    matrixType operator-(matrixType);
    matrixType operator*(matrixType);

    friend istream &operator>>(istream &in, matrixType &t);
    friend ostream &operator<<(ostream &out, const matrixType &t);
};

istream &operator>>(istream &in, matrixType &t)
{
    for (int i = 0; i < t.rows; i++)
    {
        for (int j = 0; j < t.cols; j++)
        {
            cout << "Enter row " << (i + 1) << ", column " << (j + 1) << " element: ";
            in >> t.matrix[i][j];
        }
    }
    return in;
}

ostream &operator<<(ostream &out, const matrixType &t)
{
    for (int i = 0; i < t.rows; i++)
    {
        for (int j = 0; j < t.cols; j++)
        {
            out << t.matrix[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

matrixType matrixType::operator+(matrixType m)
{
    if (rows == m.rows && cols == m.cols)
    {
        matrixType add;
        add.rows = rows;
        add.cols = cols;

        /*add.allocateMatrix(): It allocates memory for the result matrix add based on the number of rows and columns of the matrices being added.
        It ensures that the add matrix has the same dimensions as the input matrices.*/
        add.allocateMatrix();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                add.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
            }
        }

        return add;
    }
    else
    {
        cout << "Matrices aren't compatible for addition :(" << endl;
    }
}

matrixType matrixType::operator-(matrixType m)
{
    if (rows == m.rows && cols == m.cols)
    {
        matrixType sub;
        sub.rows = rows;
        sub.cols = cols;
        sub.allocateMatrix();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                sub.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
            }
        }

        return sub;
    }
    else
    {
        cout << "Matrices aren't compatible for subtraction :(" << endl;
    }
}

matrixType matrixType::operator*(matrixType m)
{
    if (cols == m.rows)
    {
        matrixType mult;
        mult.rows = rows;
        mult.cols = m.cols;
        mult.allocateMatrix();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < m.cols; j++)
            {
                mult.matrix[i][j] = 0;
                for (int k = 0; k < cols; k++)
                {
                    mult.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
                }
            }
        }

        return mult;
    }
    else
    {
        cout << "Matrices aren't compatible for multiplication :(" << endl;
    }
}

int main()
{
    matrixType mt1, mt2;
    matrixType mt3;

    mt1.get_rows_cols();
    cout << "Enter elements of first matrix\n";
    cin >> mt1;

    mt2.get_rows_cols();
    cout << "Enter elements of second matrix\n";
    cin >> mt2;

    int option;
    while (option != -1)
    {
        cout << "Enter one of the following options:\n";
        cout << " 1. Add the matrices\n";
        cout << " 2. Subtract the matrices\n";
        cout << " 3. Multiply the matrices\n";
        cout << " 4. Output the matrices\n";
        cout << " 5. Input different matrices\n";
        cout << " 6. -1 to exit\n";
        cin >> option;

        switch (option)
        {
        case 1:
            mt3 = mt1 + mt2;
            cout << "Result of addition:\n";
            cout << mt3;
            break;

        case 2:
            mt3 = mt1 - mt2;
            cout << "Result of subtraction:\n";
            cout << mt3;
            break;

        case 3:
            mt3 = mt1 * mt2;
            cout << "Result of multiplication:\n";
            cout << mt3;
            break;

        case 4:
            cout << "First Matrix:\n";
            cout << mt1;
            cout << "Second Matrix:\n";
            cout << mt2;
            break;

        case 5:
            mt1.get_rows_cols();
            cout << "Enter elements of first matrix\n";
            cin >> mt1;

            mt2.get_rows_cols();
            cout << "Enter elements of second matrix\n";
            cin >> mt2;
            break;

        case 6:
            option = -1;
            break;

        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    }

    return 0;
}

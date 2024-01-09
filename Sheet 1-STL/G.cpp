// A boolean matrix has the parity property when each row and each column has an even sum, i.e. contains
// an even number of bits which are set. Here’s a 4 × 4 matrix which has the parity property:
// 1 0 1 0
// 0 0 0 0
// 1 1 1 1
// 0 1 0 1
// The sums of the rows are 2, 0, 4 and 2. The sums of the columns are 2, 2, 2 and 2.
// Your job is to write a program that reads in a matrix and checks if it has the parity property. If
// not, your program should check if the parity property can be established by changing only one bit. If
// this is not possible either, the matrix should be classified as corrupt.
// The input file will contain one or more test cases. The first line of each test case contains one integer
// n (n < 100), representing the size of the matrix. On the next n lines, there will be n integers per line.
// No other integers than ‘0’ and ‘1’ will occur in the matrix. Input will be terminated by a value of 0 for
// n
// For each matrix in the input file, print one line. If the matrix already has the parity property, print
// ‘OK’. If the parity property can be established by changing one bit, print ‘Change bit (i,j)’ where i
// is the row and j the column of the bit to be changed. Otherwise, print ‘Corrupt’.
// 4
// 1 0 1 0
// 0 0 0 0
// 1 1 1 1
// 0 1 0 1
// 4
// 1 0 1 0
// 0 0 1 0
// 1 1 1 1
// 0 1 0 1
// 4
// 1 0 1 0
// 0 1 1 0
// 1 1 1 1
// 0 1 0 1
// 0
// OK
// Change bit (2,3)
// Corrupt

#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int size;
    while (cin >> size && size != 0)
    {
        int matrix[size][size];
        int rows = 0;
        while (rows < size)
        {
            string row;
            char c = getc(stdin);
            getline(cin, row);
            row = c + row;
            stringstream ss(row);
            for (int i = 0; i < size; i++)
            {
                ss >> matrix[rows][i];
            }
            rows++;
        }
        rows = 0;
        int columns = 0;
        int coruptedrow = 0, corruptedcolumn = 0;
        int corruptedrowindex, corruptedcolumnindex;
        while (rows < size && columns < size)
        {
            int rowSum = 0, columnSum = 0;
            for (int i = 0; i < size; i++)
            {
                rowSum = rowSum + matrix[rows][i];
            }
            if (rowSum % 2 != 0)
            {
                coruptedrow++;
                corruptedrowindex = rows + 1;
            }
            rows++;
            for (int i = 0; i < size; i++)
            {
                columnSum = columnSum + matrix[i][columns];
            }
            if (columnSum % 2 != 0)
            {
                corruptedcolumn++;
                corruptedcolumnindex = columns + 1;
            }
            columns++;
        }
        if (coruptedrow == 0 && corruptedcolumn == 0)
        {
            cout << "OK\n";
        }
        else if (coruptedrow == 1 && corruptedcolumn == 1)
        {
            cout << "Change bit (" << corruptedrowindex << "," << corruptedcolumnindex << ")\n";
        }
        else
        {
            cout << "Corrupt\n";
        }
    }
    return 0;
}
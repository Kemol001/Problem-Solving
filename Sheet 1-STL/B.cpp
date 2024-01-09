// Write a program, that, given a board, and a list of rectangular sub-portions of the board, returns the
// number of positions that belong to no sub-portion.
// Input
// The input consists of a series of test sets separated by blank lines. A test set starts with a line with
// three numbers W, H and N, giving respectively the width, the height and the number of sub-boards.
// These values satisfy the following constraints: 1 ≤ W, H ≤ 500 and 0 ≤ N ≤ 99. Follow then N
// lines, composed of four integers X1, Y1, X2, Y2, such that (X1, Y1) and (X2, Y2) are the positions of two
// opposite corners of a sub-board. These values satisfy the following constraints: 1 ≤ X1, X2 ≤ W and
// 1 ≤ Y1, Y2 ≤ H. The end of the input is reached when the numbers W, H and N are equal to 0.
// This last line shall not be considered as a test set.
// Output
// The program shall output each result on a line by its own, following the format given in the sample
// output.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int W, H, N;

    while (cin >> W >> H >> N && (W || H || N)) {
        vector<vector<bool>> board(W + 1, vector<bool>(H + 1, false));

        for (int i = 0; i < N; ++i) {
            int X1, Y1, X2, Y2;
            cin >> X1 >> Y1 >> X2 >> Y2;

            for (int x = min(X1, X2); x <= max(X1, X2); ++x) {
                for (int y = min(Y1, Y2); y <= max(Y1, Y2); ++y) {
                    board[x][y] = true;
                }
            }
        }

        int count = 0;
        for (int x = 1; x <= W; ++x) {
            for (int y = 1; y <= H; ++y) {
                if (!board[x][y]) {
                    ++count;
                }
            }
        }
        if(count == 0)
            cout << "There is no empty spots." << endl;
        else if(count == 1)
            cout << "There is one empty spots." << endl;
        else
            cout << "There are " << count << " empty spots." << endl;
    }

    return 0;
}

/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/spiral-order-matrix-i/
 */

vector<int> Solution::spiralOrder(const vector<vector<int>> &A) {
    vector<int> result;
    int size = A.size();
    int rowStart = 0, rowEnd = size - 1;
    int colStart = 0, colEnd = A[0].size() - 1;
    int row = 0;
    int col = 0;
    int count = 0;
    int countMax = size * A[0].size();
    int direction = 1;
    while (count < countMax) {
        count++;
        result.emplace_back(A[row][col]);
        switch (direction) {
        case 1:
            if (col + 1 > colEnd) {
                rowStart++;
                row = rowStart;
                direction = 2;
            } else {
                col++;
            }
            break;
        case 2:
            if (row + 1 > rowEnd) {
                colEnd--;
                col = colEnd;
                direction = 3;
            } else {
                row++;
            }
            break;
        case 3:
            if (col - 1 < colStart) {
                rowEnd--;
                row = rowEnd;
                direction = 4;
            } else {
                col--;
            }
            break;
        case 4:
            if (row - 1 < rowStart) {
                colStart++;
                col = colStart;
                direction = 1;
            } else {
                row--;
            }
            break;
        }
    }

    return result;
}

vector<int> Solution::spiralOrder(const vector<vector<int>> &A) {
    vector<int> result;
    int topRow = 0;
    int bottomRow = A.size() - 1;
    int leftColumn = 0;
    int rightColumn = A[0].size() - 1;
    int direction = 1;
    while (topRow <= bottomRow && leftColumn <= rightColumn) {

        if (direction == 1) {
            for (int j = leftColumn; j <= rightColumn; j++) {
                result.emplace_back(A[topRow][j]);
            }
            topRow++;
            direction++;
        } else if (direction == 2) {
            for (int i = topRow; i <= bottomRow; i++) {
                result.emplace_back(A[i][rightColumn]);
            }
            rightColumn--;
            direction++;
        } else if (direction == 3) {
            for (int j = rightColumn; j >= leftColumn; j--) {
                result.emplace_back(A[bottomRow][j]);
            }
            bottomRow--;
            direction++;
        } else {
            for (int i = bottomRow; i >= topRow; i--) {
                result.emplace_back(A[i][leftColumn]);
            }
            leftColumn++;
            direction = 1;
        }
    }
    return result;
}
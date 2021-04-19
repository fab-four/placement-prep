/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/spiral-order-matrix-ii/
 */

vector<vector<int>> Solution::generateMatrix(int A) {
    vector<vector<int>> result(A, vector<int>(A));
    int topRow = 0;
    int bottomRow = A - 1;
    int leftColumn = 0;
    int rightColumn = A - 1;
    int direction = 1;
    int count = 1;
    while (topRow <= bottomRow && leftColumn <= rightColumn) {

        if (direction == 1) {
            for (int j = leftColumn; j <= rightColumn; j++) {
                result[topRow][j] = count++;
            }
            topRow++;
            direction++;
        } else if (direction == 2) {
            for (int i = topRow; i <= bottomRow; i++) {
                result[i][rightColumn] = count++;
            }
            rightColumn--;
            direction++;
        } else if (direction == 3) {
            for (int j = rightColumn; j >= leftColumn; j--) {
                result[bottomRow][j] = count++;
            }
            bottomRow--;
            direction++;
        } else {
            for (int i = bottomRow; i >= topRow; i--) {
                result[i][leftColumn] = count++;
            }
            leftColumn++;
            direction = 1;
        }
    }
    return result;
}
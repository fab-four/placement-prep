/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/dungeon-princess/
 */

// select path which needs less health points.
// -02   -03    03      07   05   02    M
// -05   -10    01  =>  06   11   05    M
//  10    30   -05      01   01   06    1
//                      M     M    1    M

int Solution::calculateMinimumHP(vector<vector<int>> &dungeon) {
    int rows = dungeon.size();
    int cols = dungeon[0].size();

    vector<vector<int>> hp(rows + 1, vector<int>(cols + 1, INT_MAX));

    // base case ... i.e. minimum energy Player should have when it reaches Destination + 1
    hp[rows][cols - 1] = 1;
    hp[rows - 1][cols] = 1;

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
            hp[i][j] = need <= 0 ? 1 : need;
        }
    }
    return hp[0][0];
}
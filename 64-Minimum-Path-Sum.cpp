/// @see https://leetcode.com/problems/minimum-path-sum
class Solution {
public:
    /**
     * @brief Calculates the minimum path in a matrix, starting from the top left and ending at the bottom right.
     * 
     * @param grid: A 2D array.
     * @pre (1 <= m, n <= 200) where (m == grid.length) and (n == grid[i].length).
     * @pre 0 <= grid[i][j] <= 200.
     * @return The minimum path sum.
     *
     * @details Traverse the grid by moving either down or right at any point in time.
    */
    int minPathSum(vector<vector<int>>& grid);
};

int Solution::minPathSum(vector<vector<int>>& grid) {
    int numRows = grid.size();
    int numCols = grid[0].size();

    vector<vector<int>> minPathSumToReachACell(numRows, vector<int>(numCols, 0));
    minPathSumToReachACell[0][0] = grid[0][0];

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if (row == 0 && col == 0) {
                continue;
            }
            int minPathToReachPrevCellUp = (row > 0) ? minPathSumToReachACell[row - 1][col] : INT_MAX;
            int minPathToReachPrevCellLeft = (col > 0) ? minPathSumToReachACell[row][col - 1] : INT_MAX;
            int curCellVal = grid[row][col];

            minPathSumToReachACell[row][col] = std::min(minPathToReachPrevCellUp, minPathToReachPrevCellLeft) + curCellVal;
        }
    }

    return minPathSumToReachACell[numRows - 1][numCols - 1];
}

/**
 * @brief Calculates the maximum number of moves that can be performed by moving across the grid from left to right from a smaller cell to a bigger cell.
 *
 * @param grid: A 2D array.
 * @pre (2 <= m, n <= 1000) and (2 <= m * n <= 10^5) where (m == grid.length) and (n == grid[i].length).
 * @pre 1 <= grid[i][j] <= 10^6.
 * @return The maximum number of moves that can be performed.
 *
 * @details The starting point can be any cell in the first column of the matrix.
 * @details Traverse the grid by moving from a cell (row, col) to any one of the three cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1)
 *    such that the value of the destination cell is strictly bigger than the value of the source cell.
 *
 * @see https://leetcode.com/problems/maximum-number-of-moves-in-a-grid
*/
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        const int INVALID_SOURCE_CELL = -1;
        vector<vector<int>> maxMovesToReachACell(numRows, vector<int>(numCols, INVALID_SOURCE_CELL));
        for (int row = 0; row < numRows; row++) {
            maxMovesToReachACell[row][0] = 0; // any cell in the first column of the matrix is a valid source cell
        }

        // We are moving from left to right one column at a time. 
        // The maximum number of moves is given by how many columns we can reach
        int maxColReached = 0;
        // If we cannot make a move to the next column, there will be a gap that can't be bridged, and we can no longer proceed
        // i.e. (col - maxColReach) > 2 means we already reached the farthest column possible and made the max amount of moves
        for (int col = 1; (col < numCols) && ((col - maxColReached) < 2); col++) {
            for (int row = 0; row < numRows; row++) {
                int cellValCur = grid[row][col];
                int cellValLeft = grid[row][col - 1]; // loop starts from col = 1, so col-1 won't be out of bounds
                int cellValLeftUp = (row > 0) ? grid[row - 1][col - 1] : INT_MAX;
                int cellValLeftDown = (row < numRows - 1) ? grid[row + 1][col - 1] : INT_MAX;
                
                int maxMovesToReachCellLeft = (cellValLeft < cellValCur) ? maxMovesToReachACell[row][col - 1] : INVALID_SOURCE_CELL;
                int maxMovesToReachCellLeftUp = (cellValLeftUp < cellValCur && row > 0) ? maxMovesToReachACell[row - 1][col - 1] : INVALID_SOURCE_CELL;
                int maxMovesToReachCellLeftDown = (cellValLeftDown < cellValCur && row < numRows - 1) ? maxMovesToReachACell[row + 1][col - 1] : INVALID_SOURCE_CELL;

                int maxMovesToReachCellPrevCol = std::max({maxMovesToReachCellLeft, maxMovesToReachCellLeftUp, maxMovesToReachCellLeftDown});
                if (maxMovesToReachCellPrevCol != INVALID_SOURCE_CELL) {
                    maxColReached = col;
                    maxMovesToReachACell[row][col] = 1 + maxMovesToReachCellPrevCol;
                }
            }
        }

        return maxColReached;
    }
};

/// @see https://leetcode.com/problems/triangle
class Solution {
public:
    /**
     * @brief Calculates the minimum path sum from top to bottom in a triangle array.
     *
     * @param triangle: A triangle array.
     * @pre 1 <= triangle.length <= 200.
     * @pre triangle[0].length == 1.
     * @pre triangle[i].length == triangle[i - 1].length + 1.
     * @pre -10^4 <= triangle[i][j] <= 10^4.
     * @return The minimum path sum from top to bottom.
     *
     * @details Traverse the triangle array by moving from triangle[row][col] to either triangle[row + 1][col] or triangle[row + 1][col + 1] at each step.
    */
    int minimumTotal(vector<vector<int>>& triangle);
};

int Solution::minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> triangleCopy = triangle; // to avoid altering the passed-by-reference parameter
    int numRows = triangle.size();
        
    //  2
    //  3 4
    //  6 5 7    <-- loop starts at this row (numRows - 2), therefore (row + 1) and (col + 1) can't be out of bounds.
    //  4 1 8 3 
    for (int row = numRows - 2; row >= 0; row--) {
        int numCols = row + 1;
        for (int col = 0; col < numCols; col++) {
            triangleCopy[row][col] += std::min(triangleCopy[row + 1][col], triangleCopy[row + 1][col + 1]);
        }
    }

    return triangleCopy[0][0];
}

/// @see https://leetcode.com/problems/longest-square-streak-in-an-array
class Solution {
public:
    /**
     * @brief Calculates the longest square streak in an array.
     *
     * @param nums: An integer array.
     * @pre (2 <= nums.length <= 10^5) and (2 <= nums[i] <= 10^5).
     * @return The length of the longest square streak in nums, or -1 if there is no square streak.
     *
     * @note A subsequence of nums is called a square streak if the length of the subsequence is at least 2, and
     *   after sorting the subsequence, each element (except the first element) is the square of the previous number.
     * @note A subsequence is an array that can be derived from another array by deleting some or no elements without
     *   changing the order of the remaining elements.
    */
    int longestSquareStreak(vector<int>& nums);
};

int Solution::longestSquareStreak(vector<int>& nums) {
    std::unordered_map<int, int> numToLongestStreakStartingFromNum;
    std::sort(nums.begin(), nums.end());

    for (int num : nums) {
        numToLongestStreakStartingFromNum[num] = 1;
    }

    int longestStreak = 1;

    int maxPossibleNum = std::pow(10, 5); // 2 <= nums[i] <= 10^5 is a precondition
    int maxNumThatCanBeSquared = std::sqrt(maxPossibleNum);

    for (int i = nums.size() - 1; i >= 0; i--) {
        int curNum = nums[i];
        if (curNum > maxNumThatCanBeSquared) {
            continue;
        }
        int curNumSquare = curNum * curNum;
        if (numToLongestStreakStartingFromNum.contains(curNumSquare)) {
            numToLongestStreakStartingFromNum[curNum] = 1 + numToLongestStreakStartingFromNum[curNumSquare];

            longestStreak = std::max(longestStreak, numToLongestStreakStartingFromNum[curNum]);
        }
    }

    return (longestStreak == 1) ? -1 : longestStreak;
}

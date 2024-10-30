/// @see https://leetcode.com/problems/beautiful-towers-i
class Solution {
private:
    /**
     * @brief Produces the mountain-shaped version of an array by decrementing zero or more elements until all elements before a pivot index are non-decreasing, and all elements after a pivot index are non-increasing.
     *
     * @param[in] maxElementIndex: Chosen index of an element in heights to be the pivot(peak of the mountain).
     * @param[in] heights: Integer array holding the original values.
     * @param[out] heightsAsAMountain: Integer array to store the result.
     * @pre heights.length == heightsAsAMountain.length.
     * @pre (1 <= heights.length <= 10^3) and (1 <= heights[i] <= 10^9)
     * @pre 0 <= maxElementIndex < heights.length.
     * @post heightsAsAMountain is altered such that all elements before maxElementIndex are non-decreasing, and all elements after maxElementIndex are non-increasing, and heightsAsAMountain[maxElementIndex] = heights[maxElementIndex].
     * @return None
     *
     * @details The function achieves the goal of obtaining a mountain-shaped array by decrementing zero or more elements while using the least amount of decrementing operations possible, 
     *  i.e. sum(heights) - sum(heightsAsAMountain) is as small as possible
    */
    void getMountainArray(int maxElementIndex, const vector<int>& heights, vector<int>& heightsAsAMountain);

    /**
     * @brief Calculates the sum of all values in an array.
     *
     * @param[in] arr: An integer array.
     * @return The sum of all values in the array.
    */
    long long getArraySum(const vector<int>& arr);
public:
    /**
     * @brief Calculates the maximum possible sum of heights of a mountain-shaped tower arrangement.
     *
     * @param[in] heights: Integer array.
     * @pre (1 <= heights.length <= 10^3) and (1 <= heights[i] <= 10^9).
     * @return The maximum possible sum of heights of a mountain-shaped tower arrangement.
    */
    long long maximumSumOfHeights(vector<int>& heights);
};

long long Solution::maximumSumOfHeights(vector<int>& heights) {
    long long maxSum = 0;
    vector<int> heightsAsAMountain = heights;

    for (int peakIndex = 0; peakIndex < heights.size(); peakIndex++) {
        if (peakIndex > 0 && heights[peakIndex] == heights[peakIndex - 1]) {
            continue;
        }
        getMountainArray(peakIndex, heights, heightsAsAMountain);
        maxSum = std::max(maxSum, getArraySum(heightsAsAMountain));
    }

    return maxSum;
}

long long Solution::getArraySum(const vector<int>& arr) {
    long long result = 0;
    for (int num : arr) {
        result += num;
    }
    return result;
}

void Solution::getMountainArray(int maxElementIndex, const vector<int>& heights, vector<int>& heightsAsAMountain) {
    heightsAsAMountain[maxElementIndex] = heights[maxElementIndex];

    for (int i = maxElementIndex + 1; i < heights.size(); i++) {
        // For the current index, we can only check heights[i] and not heightsAsAMountain[i], because we don't know yet
        // the value of heightsAsAMountain at the current index, we are now about to set it
        heightsAsAMountain[i] = (heights[i] > heightsAsAMountain[i - 1]) ? heightsAsAMountain[i - 1] : heights[i];
    }

    for (int i = maxElementIndex - 1; i >= 0; i--) {
        heightsAsAMountain[i] = (heights[i] > heightsAsAMountain[i + 1]) ? heightsAsAMountain[i + 1] : heights[i];
    }
}

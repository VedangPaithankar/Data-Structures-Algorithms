/*
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

https://leetcode.com/problems/subsets-ii/description/
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the input to handle duplicates
        vector<int> currentCombination;
        vector<vector<int>> combinations;
        generateCombinations(nums, 0, currentCombination, combinations);
        return combinations;
    }

    void generateCombinations(vector<int>& nums, int index, vector<int>& currentCombination,        vector<vector<int>>& combinations) {
        combinations.push_back(currentCombination);

        for (int i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue; // Skip duplicates
            }
            currentCombination.push_back(nums[i]);
            generateCombinations(nums, i + 1, currentCombination, combinations);
            currentCombination.pop_back();
        }
    }
};

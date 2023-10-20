/*
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

https://leetcode.com/problems/subsets/description/
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(0, nums, subset, res);
        return res;
    }

    void dfs(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        // Decision to include nums[i]
        subset.push_back(nums[i]);
        dfs(i + 1, nums, subset, res);
        subset.pop_back();  // Backtrack

        // Decision NOT to include nums[i]
        dfs(i + 1, nums, subset, res);
    }
};
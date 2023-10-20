/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

https://leetcode.com/problems/permutations/description/
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>  res;
        sort(nums.begin(), nums.end());

        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return res;
    }
};
/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

https://leetcode.com/problems/combination-sum/description/
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end()); // Sort candidates to handle duplicates
        backtrack(result, current, candidates, target, 0);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
            // Skip duplicates to avoid duplicate combinations
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            current.push_back(candidates[i]);
            backtrack(result, current, candidates, target - candidates[i], i);
            current.pop_back();
        }
    }
};
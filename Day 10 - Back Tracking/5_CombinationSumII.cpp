/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

https://leetcode.com/problems/combination-sum-ii/description/
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, current, result);
        return result;
    }

    void backtrack(int start, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue; // Skip duplicates to avoid duplicate combinations
            }
            current.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, current, result);
            current.pop_back();
        }
    }
};

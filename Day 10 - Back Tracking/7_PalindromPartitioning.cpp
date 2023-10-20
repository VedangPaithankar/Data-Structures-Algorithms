/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

https://leetcode.com/problems/palindrome-partitioning/description/
*/

class Solution {
public:
    vector<vector<string>> result;
    vector<string> current;

    void dfs(string s, int start) {
        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            string substring = s.substr(start, i - start + 1);
            if (isPalindrome(substring)) {
                current.push_back(substring);
                dfs(s, i + 1);
                current.pop_back(); // Backtrack
            }
        }
    }

    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return result;
    }
};

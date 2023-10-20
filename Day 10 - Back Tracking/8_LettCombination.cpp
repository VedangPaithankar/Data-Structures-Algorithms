/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        multimap<char, string> gquiz1;
        gquiz1.insert(pair<char, string>('2', "abc"));
        gquiz1.insert(pair<char, string>('3', "def"));
        gquiz1.insert(pair<char, string>('4', "ghi"));
        gquiz1.insert(pair<char, string>('5', "jkl"));
        gquiz1.insert(pair<char, string>('6', "mno"));
        gquiz1.insert(pair<char, string>('7', "pqrs"));
        gquiz1.insert(pair<char, string>('8', "tuv"));
        gquiz1.insert(pair<char, string>('9', "wxyz"));

        string current;
        generateCombinations(digits, gquiz1, 0, current, result);

        return result;
    }

private:
    void generateCombinations(const string& digits, const multimap<char, string>& gquiz1, int index, string& current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        char digit = digits[index];
        auto range = gquiz1.equal_range(digit);
        for (auto it = range.first; it != range.second; ++it) {
            const string& letters = it->second;
            for (char ch : letters) {
                current.push_back(ch);
                generateCombinations(digits, gquiz1, index + 1, current, result);
                current.pop_back();
            }
        }
    }
};
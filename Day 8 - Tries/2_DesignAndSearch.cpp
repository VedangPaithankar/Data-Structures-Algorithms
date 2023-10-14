/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

https://leetcode.com/problems/design-add-and-search-words-data-structure/
*/

class TrieNode {
public:
    TrieNode() {
        is_end_of_word = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    bool is_end_of_word;
    TrieNode* children[26];
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(std::string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->is_end_of_word = true;
    }

    bool search(std::string word) {
        return searchRecursive(root, word, 0);
    }

private:
    TrieNode* root;

    bool searchRecursive(TrieNode* node, const std::string& word, int index) {
        if (node == nullptr) return false;

        if (index == word.length()) {
            return node->is_end_of_word;
        }

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (searchRecursive(node->children[i], word, index + 1)) {
                    return true;
                }
            }
        } else {
            int childIndex = ch - 'a';
            return searchRecursive(node->children[childIndex], word, index + 1);
        }

        return false;
    }
};

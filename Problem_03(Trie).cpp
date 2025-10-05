#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct TrieNode {
    map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {}
};

class AutoComplete {
private:
    TrieNode* root;
    void dfs(TrieNode* node, string prefix, vector<string>& results) {
        if (!node || results.size() >= 3) return;

        if (node->isEndOfWord)
            results.push_back(prefix);

        for (auto& child : node->children) {
            if (results.size() >= 3) break;
            dfs(child.second, prefix + child.first, results);
        }
    }

public:
    AutoComplete() {
        root = new TrieNode();
    }
    void add_word(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children[c])
                current->children[c] = new TrieNode();
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }
    vector<string> get_suggestions(const string& prefix) {
        TrieNode* current = root;
        vector<string> results;
        for (char c : prefix) {
            if (!current->children[c])
                return results; 
            current = current->children[c];
        }
        
        dfs(current, prefix, results);
        return results;
    }
};

int main() {
    AutoComplete system;
    system.add_word("apple");
    system.add_word("application");
    system.add_word("appetizer");
    system.add_word("banana");
    vector<string> suggestions = system.get_suggestions("app");
    cout << "[";
    for (int i = 0; i < suggestions.size(); i++) {
        cout << "\"" << suggestions[i] << "\"";
        if (i < suggestions.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}
/*
Time Complexity:
- add_word(word): O(L), where L is the length of the word.
- get_suggestions(prefix): O(P + K), where P is the prefix length and K is total characters in up to 3 suggestions.
Space Complexity: O(N * L), where N is number of words and L is average word length (for Trie storage).
*/


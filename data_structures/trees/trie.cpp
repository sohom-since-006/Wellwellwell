#include <iostream>
#include <string>
#include <memory>

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() : root(new TrieNode()) {}
    void insert(const std::string& key) {
        TrieNode* curr = root;
        for (char c : key) {
            int index = c - 'a';
            if (!curr->children[index]) curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
    bool search(const std::string& key) const {
        TrieNode* curr = root;
        for (char c : key) {
            int index = c - 'a';
            if (!curr->children[index]) return false;
            curr = curr->children[index];
        }
        return curr && curr->isEndOfWord;
    }
    bool startsWith(const std::string& prefix) const {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!curr->children[index]) return false;
            curr = curr->children[index];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("algorithm");
    trie.insert("alexandria");
    trie.insert("algebra");

    std::cout << "Search 'algorithm': " << (trie.search("algorithm") ? "Found" : "Not Found") << "\n";
    std::cout << "Prefix 'alg': " << (trie.startsWith("alg") ? "Yes" : "No") << "\n";
    std::cout << "Prefix 'zoo': " << (trie.startsWith("zoo") ? "Yes" : "No") << "\n";
    return 0;
}

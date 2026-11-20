#include <iostream>
#include <string>
#include <vector>

struct AutoNode {
    AutoNode* child[26];
    bool isLeaf;
    AutoNode() : isLeaf(false) {
        for (int i = 0; i < 26; ++i) child[i] = nullptr;
    }
};

void insertWord(AutoNode* root, const std::string& word) {
    AutoNode* curr = root;
    for (char c : word) {
        int idx = c - 'a';
        if (!curr->child[idx]) curr->child[idx] = new AutoNode();
        curr = curr->child[idx];
    }
    curr->isLeaf = true;
}

void dfsSuggestions(AutoNode* node, std::string prefix, std::vector<std::string>& results) {
    if (node->isLeaf) results.push_back(prefix);
    for (int i = 0; i < 26; ++i) {
        if (node->child[i]) {
            dfsSuggestions(node->child[i], prefix + char('a' + i), results);
        }
    }
}

std::vector<std::string> getAutocomplete(AutoNode* root, const std::string& prefix) {
    AutoNode* curr = root;
    for (char c : prefix) {
        int idx = c - 'a';
        if (!curr->child[idx]) return {};
        curr = curr->child[idx];
    }
    std::vector<std::string> suggestions;
    dfsSuggestions(curr, prefix, suggestions);
    return suggestions;
}

int main() {
    AutoNode* root = new AutoNode();
    for (const std::string& w : {"apple", "app", "application", "apt", "banana", "bat"}) {
        insertWord(root, w);
    }

    std::string prefix = "app";
    auto list = getAutocomplete(root, prefix);
    std::cout << "Autocomplete for '" << prefix << "':\n";
    for (const auto& s : list) std::cout << "  - " << s << "\n";
    return 0;
}

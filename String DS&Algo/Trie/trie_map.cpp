#include <iostream>
#include <map>
#include <string>

class TrieNode {
public:
    std::map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* node = searchNode(word);
        return (node != nullptr && node->isEndOfWord);
    }

    bool startsWith(const std::string& prefix) {
        return (searchNode(prefix) != nullptr);
    }

private:
    TrieNode* root;

    TrieNode* searchNode(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return nullptr;
            }
            current = current->children[c];
        }
        return current;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    
    std::cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not found") << std::endl;
    std::cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not found") << std::endl;
    std::cout << "Starts with 'app': " << (trie.startsWith("app") ? "Found" : "Not found") << std::endl;
    std::cout << "Search 'orange': " << (trie.search("orange") ? "Found" : "Not found") << std::endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[10];
    bool EoW;

    TrieNode() : EoW(false) {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }
};

TrieNode* root= new TrieNode();

class Trie {
public:
    Trie() {
        // root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - '0';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->EoW = true;
    }

    bool isEmpty(TrieNode* root) {
        for (int i = 0; i < 10; ++i) {
            if (root->children[i]) {
                return false;
            }
        }
        return true;
    }

    TrieNode* dlt(TrieNode* root, string s, int d = 0) {
        if (!root)
            return NULL;
        if (isEmpty(root)) {
            delete (root);
            root = NULL;
            return NULL;
        }
        if (d == s.size()) {
            if (root->EoW)
                root->EoW = 0;
            return root;
        }
        int index = s[d] - '0';
        root->children[index] = dlt(root->children[index], s, ++d);
        return root;
    }

    void printTrie(TrieNode* cur, string s = "") {
        if (cur->EoW)
            cout << s << endl;
        for (int i = 0; i < 10; i++) {
            if (cur->children[i] != NULL) {
                char c = (char)(i + '0');
                cout << c << " ";
                printTrie(cur->children[i], s + c);
            }
        }
    }

    // TrieNode* root;

    TrieNode* searchNode(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - '0';
            if (current->children[index] == nullptr) {
                return nullptr;
            }
            current = current->children[index];
        }
        return current;
    }

    bool search(const std::string& word) {
        TrieNode* node = searchNode(word);
        return (node != nullptr && node->EoW);
    }

    bool startsWith(const std::string& prefix) {
        return (searchNode(prefix) != nullptr);
    }

};

int main() {
    Trie trie;
    // TrieNode* root=new TrieNode;
    int n = 57;
    cout<<"Enter total students:\n";
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        trie.insert(s);
    }
    cout<<"Now insert the Present Students:\n";
    int t = 31;
    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        trie.dlt(trie.searchNode(s), s);
    }
    trie.printTrie(root);
    return 0;
}

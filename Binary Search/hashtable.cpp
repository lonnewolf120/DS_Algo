#include <iostream>
using namespace std;
const int N = 10;

struct Node {
    string key,val;
    Node* next;
};

class SLL {

public:
    Node* head;
    SLL() {
        head = NULL;
    }

    void setter(string a) {
        Node* newitem = new Node;
        newitem->val = a;
        newitem->next = NULL;

        if (head == NULL) {
            head = newitem;
        }
        else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newitem;
        }
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }

    bool search(string key) {
        Node* temp = head;
        while (temp) {
            if (temp->val == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    string getValue(string key) {
        Node* temp = head;
        while (temp) {
            if (temp->val == key)
                return temp->val;
            temp = temp->next;
        }
        return "";
    }

    ~SLL() {}
};

int hashtable(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); ++i)
        sum += s[i] % N;
    return sum % N;
}

int main() {
    SLL obj[N];
    int freq[N] = { 0 };
    string s[20] = { "1112323", "23454667", "22908943", "651232", "1145", "7645", "235656", "99965", "85456", "94434540", "karim", "rahim", "sharif", "pops", "rocky", "heru", "karma", "naughty", "daddy", "floppy" };

    for (int i = 0; i < 20; ++i) {
        int l = hashtable(s[i]);
        freq[l]++;
        obj[l].setter(s[i]);
    }

    for (int i = 0; i < N; ++i) {
        cout << "key: " << i << " frequency: " << freq[i] << " ";
        obj[i].print();
        cout << "\n";
    }

    // Print value for a specific key
    string searchKey = "1112323";
    int searchHash = hashtable(searchKey);
    if (obj[searchHash].search(searchKey))
        cout << "Value for key '" << searchKey << "': " << obj[searchHash].getValue(searchKey) << endl;
    else
        cout << "Key '" << searchKey << "' not found." << endl;

    // Deallocate memory for linked lists
    for (int i = 0; i < N; ++i) {
        Node* temp = obj[i].head;
        while (temp) {
            Node* curr = temp;
            temp = temp->next;
            delete curr;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Hash table using chaining
class HashTable {
private:
    std::vector<Node*> table;
    size_t tableSize;

    // Hash function
    size_t hashFunction(int key) {
        return key % tableSize;
    }

public:
    HashTable(size_t size) : tableSize(size) {
        table.resize(tableSize, nullptr);
    }

    // Insert a key into the hash table
    void insert(int key) {
        size_t index = hashFunction(key);
        Node* newNode = new Node(key);
        
        if (!table[index]) {
            table[index] = newNode;
        } else {
            Node* current = table[index];
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Search for a key in the hash table
    bool search(int key) {
        size_t index = hashFunction(key);
        Node* current = table[index];

        while (current) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    // Print the hash table
    void display() {
        for (size_t i = 0; i < tableSize; ++i) {
            std::cout << "Index " << i << ": ";
            Node* current = table[i];
            while (current) {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            std::cout << "nullptr" << std::endl;
        }
    }

    // Destructor to free memory
    ~HashTable() {
        for (size_t i = 0; i < tableSize; ++i) {
            Node* current = table[i];
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable ht(10); // Create a hash table with size 10

    ht.insert(42);
    ht.insert(23);
    ht.insert(15);
    ht.insert(30);

    ht.display();

    std::cout << "Search 15: " << (ht.search(15) ? "Found" : "Not found") << std::endl;
    std::cout << "Search 99: " << (ht.search(99) ? "Found" : "Not found") << std::endl;

    return 0;
}
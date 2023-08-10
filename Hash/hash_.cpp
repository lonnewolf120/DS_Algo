#include <iostream>
#include <vector>
#include <list>

// Define a structure for each node in the linked list
struct Node {
    int key;
    int value;
    Node* next;

    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

// Define the hash table with chaining
class HashTable {
private:
    std::vector<std::list<Node*>> table;
    int size;

    // Hash function
    size_t hash(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size);
    }

    // Insert a key-value pair into the hash table
    void insert(int key, int value) {
        size_t index = hash(key);

        // Check if the key already exists in the linked list at the index
        for (Node* curr = table[index].front(); curr != nullptr; curr = curr->next) {
            if (curr->key == key) {
                // Key already exists, add the new node after the previous node
                Node* newNode = new Node(key, value);
                newNode->next = curr->next;
                curr->next = newNode;
                return;
            }
        }

        // Key doesn't exist, create a new node and insert at the beginning of the linked list
        Node* newNode = new Node(key, value);
        newNode->next = table[index].front();
        table[index].push_front(newNode);
    }

    void print()
    {
        for (int i = 0; i < table.size(); ++i)
        {
            std::cout<<"Key: "<<i<<" value: ";
            for(Node* tmp=table[i].front(); tmp!=NULL; tmp=tmp->next)
            {
                if(tmp->value)
                    std::cout<<tmp->value << " ";
            }
            std::cout<<std::endl;
            /* code */
        }
        
    }
    void _insert(int k, int v)
    {
        int index= hash(k);
        // vector<list<Node*>> table;        
        Node* newNode= new Node(k,v);
        for(Node* curr=table[index].front();curr!=NULL;curr=curr->next)
        {
            if(curr->key==k)
            {
                newNode->next=curr->next;
                curr->next=newNode;
                return;
            }
        }
        //if not found then just add newNode
        newNode->next=table[index].front();
        table[index].push_front(newNode);
    }
};

int main() {
    HashTable ht(10);  // Create a hash table with size 10

    // Insert some key-value pairs
    ht._insert(5, 50);
    ht._insert(15, 150);
    ht._insert(25, 250);
    ht._insert(2,10);
    ht._insert(5, 55);  // Inserting a duplicate key
    ht.print();
    return 0;
}

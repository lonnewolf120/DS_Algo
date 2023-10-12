#include<bits/stdc++.h>
using namespace std;
int capacity;
class Node{
private:
    int val;
    Node *next;

public:
    Node(){
        next = NULL;
    }
    void setValue(int n)
    {
        this->val = n;
    }
    void setValue1(Node *n)
    {
        this->next = n;
    }
    int getValue()
    {
        return val;
    }
    Node *getValue1()
    {
        return next;
    }
};

class Stack{
private:
    Node *head;
    int SIZE;
public:
    Stack(int n){
        head = NULL;
        SIZE = 0;
        capacity = n;
    }

    void push(int n)
    {
        if(isStackFull())
        {
           cout<<"Capacity full.Value cannot be inserted\n";
        }
        else
        {
            Node *newitem;
            newitem = new Node;
            newitem->setValue(n);
            if(head==NULL)
            {
                head = newitem;
            }
            else
            {
                head->setValue1(newitem);
                head = newitem;
            }
            SIZE++;
        }


    }
    bool isStackFull()
    {
        if(SIZE==capacity)return 1;
        return 0;
    }
    bool isEmpty(){
        if(SIZE==0)return 1;
        return 0;
    }

    int top(){
        ///Stack functionality: Returns the last inserted value/top value of the stack (doesn't remove from stack)
        ///Linked list functionality: Returns the value located at head
        ///If the user calls this function for an empty stack, it will generate runtime error
    }

    void pop(){
        ///Stack functionality: Removes the top value of the stack
        ///Linked list functionality: if the list is not empty then removes the node under head and declares new head
        ///If the user calls this function for an empty stack, it will generate runtime error
    }

    int size(){
        return SIZE;
    }

    void displaystack(){
        Node *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->getValue()<<" ";
            temp = temp->getValue1();
        }

    }
};


int main(){
    int choice;
    cin>>choice;
    int n;
    cin>>n;
    Stack s(n);

    while(choice!=0)
    {
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - View Top Item."<<endl;
        cout<<"4 - Size of Stack."<<endl;
        cout<<"5 - Display Items (Print STACK)."<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 0:
                break;

            case 1:
                int x;
                cin>>x;
                s.push(x);
                cout<<"Current Array: \n";
                s.displaystack();

                break;

            case 2:
                ///Must check whether the stack is empty or not before popping
                break;

            case 3:
                ///Must check whether the stack is empty or not before viewing top item
                break;

            case 4:
                break;

            case 5:
                s.displaystack();
                break;

            default:
                cout<<"An Invalid choice."<<endl;
        }

        cout<<endl<<endl;
    }


    return 0;
}
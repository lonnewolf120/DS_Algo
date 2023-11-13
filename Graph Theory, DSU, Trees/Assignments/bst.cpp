#include<bits/stdc++.h>
using namespace std;

struct Node{
    string Title, Author; long long ISBN; int Price, Quantity;
    Node *left, *right, *parent;
};

Node *root;

void init(){
    root = NULL;
}

void insertRoot(long long i, string t, string a, int p, int q){

    root=new Node;
    root->ISBN=i;
    root->Title=t;
    root->Author=a;
    root->Price=p;
    root->Quantity=q;
    root->left=NULL  ;
    root->right=NULL;
    root->parent=NULL;
}

void insertOther(long long  i, string t, string a, int p, int q){

    Node *temp=root;
    Node *prev=NULL;///prev pointer is used to keep trac of previos poiter of temp
    //this part traverses to find the suitable node
    //left<root<=right

    while(temp!=NULL)
    {
        prev=temp;  //keeping track of prev cause we're traversing till temp!=NULL
        if(i<temp->ISBN)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }

    }
    //this part initializes a loc to temp & adds it
    temp=new Node;

    temp->ISBN=i; temp->Title=t; temp->Author=a; temp->Price=p; temp->Quantity=q; temp->left=NULL; temp->right=NULL;

    temp->parent=prev;

    //left<root<=right
    if(i<prev->ISBN)
    {
        prev->left=temp;
    }
    else{
        prev->right=temp;
    }

}

void insert(){
	string t, a; long long  i; int p, q;
	cout<<"Enter the book's ISBN: "; cin >> i;
	cout<<"Enter the book's title: "; cin.ignore();
    getline(cin,t);
	cout<<"Enter the book's author: ";
    getline(cin,a);
	cout<<"Enter the book's price: "; cin >> p;
	cout<<"Enter the book's quantity "; cin >> q;
    if(root==NULL)
    {
        insertRoot(i,t,a,p,q);
    }
    else{
        insertOther(i,t,a,p,q);
    }
}

Node* findNode(long long val, Node* node){
    //Node *temp=root;

    //left<root<=right
    /*if(node->ISBN==val || node==NULL) return node;

    if(node->ISBN < val) 
        return findNode(val, node->right);
    else 
        return findNode(val, node->left);*/
    Node* tmp=node;
    while(tmp!=NULL && tmp->ISBN!=val)
    {
        //left<root<=right
        if(val>tmp->ISBN) tmp=tmp->right;
        else tmp=tmp->left;
    }
    return tmp;
}

Node* findMaximum(Node *node){
    Node *temp=node;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;

}

Node* findMinimum(Node *node){
    Node *temp=node;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}


Node* findSuccessor(Node *node){
    //successor of a node is the immediate senior, meaning smallest element bigger than the node
    Node *temp=node->right;
    while(temp->left!=NULL)
    {
       temp=temp->left;
    }
    return temp;
}

void delete0Child(Node *node){
    Node *par=node->parent;
    //left<root<=right
    if((node->ISBN)<(par->ISBN))
    {
        par->left=NULL;
    }
    else
    {
        par->right=NULL;
    }
    free(node);
}

void delete1Child(Node *node){
    Node *par,*child;
    par=node->parent;
    ///we will grab the child of deleting node
    if(node->left==NULL)
    {
        child=node->right;
    }
    else{
        child=node->left;
    }
    ///deleting node will be on left
    if((node->ISBN )<(par->ISBN ))
    {
        par->left=child;
        child->parent=par;
    }
    ///deleting node is on right
    else
    {
        par->right=child;
        child->parent=par;
    }
}

void delete2Child(Node *node){
    Node *f=findSuccessor(node);
    node->ISBN=f->ISBN;///so successor will set
    if(f->left==NULL && f->right==NULL)
    {
        delete0Child(f);
    }
    else
    {
        delete1Child(f);
    }
}

bool deleteNode(long long val)
{
    Node *t=findNode(val, root);
    if(t==NULL)
    {
        return false;
    }
    else
    {
        if(t->left==NULL && t->right==NULL)
        {
            delete0Child(t);
        }

        else if(t->left==NULL || t->right==NULL)
        {
            delete1Child(t);
        }
        else
        {
            delete2Child(t);
        }
        return true;
    }
}
const int N=1e2;
int visited[N];
void bfs(Node* node)
{
    queue<Node*> q;
    q.push(node);

    while(!q.empty())
    {
        Node* top = q.front();
        
        cout<<"ISBN: "<<top->ISBN<<endl;
        cout<<"Title: "<<top->Title<<endl;
        cout<<"Author: "<<top->Author<<endl;
        cout<<"Price: "<<top->Price<<endl;
        cout<<"Quantity: "<<top->Quantity<<endl;

        q.pop();
        if(top->left!=NULL)
            q.push(top->left);
        if(top->right != NULL)
            q.push(top->right);
    }

}

bool isValidBST(Node* node)
{
    int val=node->ISBN;

}

void dfs(Node * node)
{
    stack<Node*> q;
    q.push(node);

    while(!q.empty())
    {
        Node* top = q.top();
        cout << top->ISBN << endl;
        q.pop();
        if(top->left!=NULL)
            q.push(top->left);
        if(top->right!=NULL)
            q.push(top->right);
    }
}

void inOrder(Node * node)
{
    if(node==NULL) return;
    if(node->left!=NULL)
        inOrder(node->left);
    cout << node->ISBN << endl;
    if(node->right!=NULL)
        inOrder(node->right);
    
}


int main(){
    init();

        

    while(1){
        cout<<"1. Add a book to the inventory\n2. Remove a book from the inventory\n3. Update the quantity of a book\n4. Search for a book by ISBN\n5. Display all books in the inventory\n7. Exit\n\n";
        int x;
        cout <<"\nEnter your choice: \n"; cin >> x;
        if(x==1){
            //cout<<"Insert Value: ";
            insert();
            cout<<"\nBook added to the inventory successfully\n";
        }

        else if(x==2){
            cout<<"Delete Value: ";
            long long y;
            cin>>y;
            bool b = deleteNode(y);
            if(b)   cout<<"Deleted"<<endl;
            else    cout<<y<<" not found"<<endl;

        }

        else if(x==3)
        {
            cout<<"Enter the ISBN: ";
            long long s;
            cin>>s;
            cout<<"Enter new quantity: ";
            int q; cin >> q;
            Node* t=findNode(s, root);
            cout << "the Quantity of " << s << " updated from "<<t->Quantity<<" to "<<q<<endl;
            t->Quantity=q;
        }
        else if(x==4)
        {

            cout<<"Enter the value you want to search ";
            long long s;
            cin>>s;
            Node* t=findNode(s, root);
            if(t==NULL)
                cout<<"Not found"<<endl;
            else
            {
                cout<<"ISBN: "<<t->ISBN<<endl;
                cout<<"Title: "<<t->Title<<endl;
                cout<<"Author: "<<t->Author<<endl;
                cout<<"Price: "<<t->Price<<endl;
                cout<<"Quantity: "<<t->Quantity<<endl;
            }

        }
        else if(x==5)
        {
            cout << "Traverse: \n";
            bfs(root);
        }
        


    }
}

/*
1
44

1
17

1
88

1
32

1
65

1
97

1
28

1
54

1
82

1
29

1
76

1
80
*/





















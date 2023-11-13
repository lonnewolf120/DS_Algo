
#include<bits/stdc++.h>
using namespace std;
int nC;
class node
{
public:
    int key, value;
    node(){
        key=0;value=0;
    }
    node(int k, int v)
    {
        key=k; value=v;
    }
    // ostream& operator<<(node a)
    // {
    //     cout<<"{"<<a.key<<", "<<a.value<<"} ";
    // }
};

class Heap{
private:
    node a[101];
    int size;

public:
    Heap(){
        size = 0;
    }

private:
    void swap(node&a, node&b)
    {
        node tmp=a;
        a=b;
        b=tmp;
        // delete tmp;
    }
    int parent(int i) {
        return i/2; //1-based
    }
    int left(int i) {
        return 2*i; //1-based
    }
    int right(int i) {
        return 2*i+1; //1-based
    }
    void bottomTopAdjust(int i){

        if(nC==1)
        {
            while(a[i].key<a[parent(i)].key)
            {
                swap(a[i],a[parent(i)]);
                i=parent(i);
            }
            while(a[i].key==a[parent(i)].key && a[i].value<a[parent(i)].value)
            {
                swap(a[i],a[parent(i)]);
                i=parent(i);
            }
        }
        else
        {
            while(a[i].key>a[parent(i)].key)
            {
                swap(a[i],a[parent(i)]);
                i=parent(i);
            }
            while(a[i].key==a[parent(i)].key && a[i].value>a[parent(i)].value)
            {
                swap(a[i],a[parent(i)]);
                i=parent(i);
            }
        }
    }

    void convert(){
        int s=size, ns=size;
        while(size>=1)
        {
            node t=extractMax();
            a[ns--]=t;
        }
        size=s;
        // for(int i=s-1;i>1;--i) cout<<a[i]<<" ";
        //     cout<<endl;
 
    }

    void topBottomAdjust(int i){    /// HEAPIFY!
        int l = 2*i, r = 2*i+1, largest;

        if(nC==1) //largest is smallest
        {
            if(l<=size && ((a[l].key<a[i].key) || (a[l].key==a[i].key && a[l].value<a[i].value)))
                largest = l;
            else
                largest = i;
            if(r<=size && (a[r].key<a[largest].key) || (a[r].key==a[largest].key && a[r].value<a[largest].value))
                largest = r;
        }
        else
        {
            if(l<=size && ((a[l].key>a[i].key) || a[l].key==a[i].key && a[l].value>a[i].value) )
                largest = l;
            else
                largest = i;
            if(r<=size && ((a[r].key>a[largest].key) || a[r].key==a[largest].key && a[r].value>a[largest].value))
                largest = r;
        }
        
        if(largest!=i)
        {
            swap(a[i], a[largest]);
            topBottomAdjust(largest);
        }
    }

public:
    bool insert(int key, int val){
        a[++size]=node(key,val);
        bottomTopAdjust(size);
        return true;
    }
    bool increaseKey(int n, int k)  // {keyToIncrease, newKey}
    {
        if(k<n) return false;
        if(nC==1)
        {
            for (int i = 0; i < size; ++i)
            {
                if(a[i].key==n)
                {
                    a[i]=node(k,a[i].value);
                    topBottomAdjust(n);
                }
            }
        }
        else
        {
            for (int i = 0; i < size; ++i)
            {
                if(a[i].key==n)
                {
                    a[i]=node(k,a[i].value);
                    bottomTopAdjust(i);
                }
            }
        }
        
        return true;
    }
    node showMax(){
        return a[1];
    }

    int showSize(){
        return size;
    }

    node extractMax(){
        node t = a[1];
        swap(a[1],a[size]);
        size--;
        topBottomAdjust(1);
        return t;
    }

    void bfs(){
        // convert(); 
        if(size==0) return;
        int level = 2;
        queue<int>q;
        q.push(1);
        cout<<"{key,value} pairs below:\n";

        while(!q.empty()){
            int par = q.front();
            // int key = par.key, val=par.value;
            q.pop();
            if(par==level){
             
                cout<<endl;
                level = level * 2;
            }
            if(a[par].key>=0)cout<<"{"<<a[par].key<<" "<<a[par].value<<"} "; 
            if(2*par <= size) q.push(2*par);
            if(2*par + 1 <= size) q.push(2*par + 1);
        }
    }
};

int main(){

    Heap heap;
    cout<<"----------------choose Heap------------------\n\n\t 1. Min-Heap \t2. Max-Heap\n\n\t    Enter (1 or 2): ";
    cin>>nC;
    while(1){
        cout<<"1. Insert    2. Increase Key    3. Show Min    4. Extract Min  5. Level Order Traversal 6. End"<<endl<<endl;
        int choice;
        cin>>choice;

        if(choice==1){
            cout<<"Insert Index: ";
            int x;
            cin>>x;
            cout<<"Insert Value: ";
            int y;
            cin>>y;
            bool b = heap.insert(x,y);

            if(b)   cout<<y<<" is inserted in the heap"<<endl;
        }
        else if(choice==2){
            cout<<"Which node you want to increase?"<<endl;
            int nodeNo;
            cin>>nodeNo;
            cout<<"What will be the new value?"<<endl;
            int value;
            cin>>value;
            // bool b=false;
            bool b=heap.increaseKey(nodeNo,value);
            if(b) cout<<"Node value increased successfully!"<<endl;
            else cout<<"Unsuccessful Operation :("<<endl;
        }
        else if(choice==3){
            if(heap.showSize()!=0) (nC==1)? cout<<"Min Element: {"<<heap.showMax().key<<", "<<heap.showMax().value<<"}\n" : cout<<"Max Element: "<<heap.showMax().key<<", "<<heap.showMax().value<<"}\n";
            else    cout<<"No element in the heap"<<endl;
        }

        else if(choice==4){
            if(heap.showSize()!=0) (nC==1)? cout<<"Min Element: "<<heap.extractMax().value : cout<<"Max Element: "<<heap.extractMax().value;
            else    cout<<"No element in the queue"<<endl;
        }

        else if(choice==5){
           cout<<"Level Wise Traversal of the Queue:"<<endl;
           heap.bfs();
           cout<<endl;
        }
        else if(choice==6)
            break;
        else{
            cout<<"Invalid Choice"<<endl;
        }
        cout<<endl;
    }
}

/*
1 1 2 
1 2 9
1 3 8
1 2 16
1 3 3
1 4 7
1 5 10
1 4 1
1 1 4
1 2 14
*/

/*
1 22 2
1 25 9
1 27 8
1 29 16
1 30 3
1 35 7
1 40 10
1 21 1
1 33 4
1 49 14
*/



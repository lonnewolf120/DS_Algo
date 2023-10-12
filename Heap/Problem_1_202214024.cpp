///Max Heap

#include<bits/stdc++.h>
using namespace std;

class Heap{
private:
    int a[101], size;

public:
    Heap(){
        size = 0;
    }

private:
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
        while(a[i]>a[parent(i)])
        {
            swap(a[i],a[parent(i)]);
            i=parent(i);
        }
    }

        bool delet(int ind)
    {
        if(size<1)return false;
        a[ind]=a[size--];
        topBottomAdjust(ind);
        //size--;
        return true;
    }
    /*
    bool deletee(int ind)
    {
        if(size<1)return false;
        a[ind]=a[size--];
        topBottomAdjust(ind);
        //size--;
        return true;
    }
    bool deleteRoot(){
        if(size<1) return false;
        delet(1);
        return true;
    }*/
 
    void reverse(){ 
        int s=size, ns=size;
        while(size>=1)
        {
            int t=extractMax();
            a[ns--]=t;
            //size--;
        }
        size=s;
        // for(int i=s-1;i>1;--i) cout<<a[i]<<" ";
        //     cout<<endl;
 
    }

    void topBottomAdjust(int i){    /// HEAPIFY!
        int l = 2*i, r = 2*i+1, largest;
        if(l<=size && a[l]>a[i])
        {
            largest = l;
        }
        else
        {
            largest = i;
        }
        if(r<=size && a[r]>a[largest])
        {
            largest = r;
        }
        if(largest!=i)
        {
            swap(a[i], a[largest]);
            topBottomAdjust(largest);
        }
    }

public:
    bool insert(int val){
        a[++size]=val;
        bottomTopAdjust(size);
        return true;
    }
    bool increaseKey(int i, int k)
    {
        if(k>a[i])
        {
            a[i]=k;
            bottomTopAdjust(i);
        }
    }
    int showMax(){
        return a[1];
    }

    int showSize(){
        return size;
    }

    int extractMax(){
        int t = a[1];
        swap(a[1],a[size]);
        size--;
        topBottomAdjust(1);
        return t;
    }

    void bfs(){
        // reverse();
        if(size==0) return;
        int level = 2;
        queue<int>q;
        q.push(1);

        while(!q.empty()){
            int par = q.front();
            q.pop();
            if(par==level){
                cout<<endl;
                level = level * 2;
            }
            cout<<a[par]<<" ";
            if(2*par <= size) q.push(2*par);
            if(2*par + 1 <= size) q.push(2*par + 1);
        }
    }
};

int main(){

    Heap heap;

    while(1){
        cout<<"1. Insert    2. Increase Key    3. Show Max    4. Extract Max  5. Level Order Traversal 6. End"<<endl<<endl;
        int choice;
        cin>>choice;

        if(choice==1){
            cout<<"Insert Value: ";
            int y;
            cin>>y;
            bool b = heap.insert(y);

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
            if(heap.showSize()!=0)  cout<<"Max Element: "<<heap.showMax();
            else    cout<<"No element in the heap"<<endl;
        }

        else if(choice==4){
            if(heap.showSize()!=0)  cout<<"Max element extracted: "<<heap.extractMax();
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
1 2
1 9
1 8
1 16
1 3
1 7
1 10
1 1
1 4
1 14
*/




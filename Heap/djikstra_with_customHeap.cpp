
#include <bits/stdc++.h>
using namespace std;
class Heap
{
    public:
    int *arr;
    int size;

    Heap(int n)
    {
        size=0;
        arr = new int[n];
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
    void heapify(int i)
    {
        int l = left(i), r = right(i), largest;
        if(l<=size && arr[l]>arr[i])
        {
            largest = l;
        }
        else
        {
            largest = i;
        }
        if(r<=size && arr[r]>arr[largest])
        {
            largest = r;
        }
        if(largest!=i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    void build_max_heap()
    {
        for(int i=size/2; i>=0; --i)
            heapify(i);
    }

    
};

int main()
{
    fastio
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}
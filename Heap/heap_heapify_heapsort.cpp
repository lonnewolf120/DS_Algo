#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int key, val;
    node()
    {
        key = 0, val = 0;
    }
    node(int k, int v)
    {
        key = k, val = v;
    }
};
class Heap
{
private:
    node a[101];
    int size;

public:
    Heap()
    {
        size = 0;
    }

private:
    void bottomTopAdjust(int i)
    {
        while (i > 1)
        {
            int child = a[i].key;
            int parent = a[i / 2].key;
            if (child < parent)
                swap(a[i], a[i / 2]);
            else
                break;
            i /= 2;
        }
    }
    void topBottomAdjust(int i)
    {
        int lc = 2 * i, rc = lc + 1;
        if (lc == size)
        {
            if (a[lc].key > a[i].key)
            {
                swap(a[lc], a[i]);
                topBottomAdjust(lc);
            }
        }
        else if (rc <= size)
        {
            int m;
            if (a[lc].key < a[i].key)
                m = lc;
            else
                m = i;
            if (a[rc].key < a[m].key)
                m = rc;
            if (m != i)
            {
                swap(a[m], a[i]);
                topBottomAdjust(m);
            }
        }
        else
            return;
    }

public:
    bool insert(int key, int val)
    {
        if (size == 100)
            return false;
        node n(key, val);
        a[++size] = n;
        bottomTopAdjust(size);
        return true;
    }
    bool increaseKey(int val, int key)
    {
        if (!size)
            return false;
        else
        {
            for (int i = 1; i <= size; ++i)
            {
                if (a[i].val == val and a[i].key < key)
                {
                    a[i].key = key;
                    bottomTopAdjust(i);
                    return true;
                }
            }
            return false;
        }
    }
    pair<int, int> showMax()
    {
        pair<int, int> p;
        p.first = a[1].key;
        p.second = a[1].val;
        return p;
    }
    int showSize()
    {
        return size;
    }
    void deleteHead()
    {
        swap(a[1], a[size]);
        size--;
        topBottomAdjust(1);
    }
    pair<int, int> extractMax()
    {
        pair<int, int> p;
        p.first = a[1].key;
        p.second = a[1].val;
        deleteHead();
        return p;
    }
    void bfs()
    {
        if (size == 0)
            return;
        int level = 2;
        queue<int> q;
        q.push(1);
        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            if (parent == level)
            {
                cout << endl;
                level = level * 2;
            }
            cout << "{" << a[parent].key << " " << a[parent].val << "}"
                 << " ";
            if (2 * parent <= size)
                q.push(2 * parent);
            if (2 * parent + 1 <= size)
                q.push(2 * parent + 1);
        }
    }
};
int main()
{

    Heap heap;

    while (1)
    {
        cout << "1. Insert    2. Increase Key    3. Show Max    4. Extract Max  5. Level Order Traversal 6. End" << endl
             << endl;
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Insert Key: ";
            int x;
            cin >> x;
            cout << "Insert Value: ";
            int y;
            cin >> y;
            bool b = heap.insert(x, y);

            if (b)
                cout << y << " is inserted in the heap" << endl;
        }
        else if (choice == 2)
        {
            cout << "Which node's key you want to increase?" << endl;
            int nodeNo;
            cin >> nodeNo;
            cout << "What will be the new key value?" << endl;
            int keyV;
            cin >> keyV;
            bool b = heap.increaseKey(nodeNo, keyV);
            if (b)
                cout << "Node's key value increased successfully!" << endl;
            else
                cout << "Unsuccessful Operation :(" << endl;
        }

        else if (choice == 3)
        {
            if (heap.showSize() != 0)
            {
                pair<int, int> p = heap.showMax();
                cout << "Key->" << p.first << " Value->" << p.second << endl;
            }
            else
                cout << "No element in the queue" << endl;
        }

        else if (choice == 4)
        {
            if (heap.showSize() != 0)
            {
                pair<int, int> p = heap.extractMax();
                cout << "Key->" << p.first << " Value->" << p.second << endl;
            }
            else
                cout << "No element in the queue" << endl;
        }

        else if (choice == 5)
        {
            cout << "Level Wise Traversal of the Queue:" << endl;
            heap.bfs();
            cout << endl;
        }
        else if (choice == 6)
            break;
        else
        {
            cout << "Invalid Choice" << endl;
        }
        cout << endl;
    }
}

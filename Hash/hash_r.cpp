
#include <bits/stdc++.h>
using namespace std;

class data
{
public:
    int key;
    int val;
    data *next;
    data(int key, int val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
    }
};
int power(int x)
{
    int s = 1;
    for (int i = 0; i < x; ++i)
        s *= 10;
    return s;
}
class HashTable
{
public:
    data **table;
    int mx;
    int sz;
    HashTable()
    {
        mx = 20;
        sz = 0;
        table = new data *[mx];
        for (int i = 0; i < mx; ++i)
            table[i] = NULL;
    }
    int halfsum(int &k, int c)
    {
        int p = 0, sum = 0;
        for (int i = 0; i < c; ++i)
        {
            int y = k % 10;
            k /= 10;
            int xy = power(p) * y;
            sum += xy;
            p++;
        }
        return sum;
    }
    int countdigit(int x)
    {
        int c = 0;
        while (x > 0)
        {
            x /= 10;
            c++;
        }
        return c;
    }
    int Hash_folding(int k)
    {
        int a,b,c;
        while(true)
        {
            if(k<10) break;
            c=countdigit(k);
            if(c%2==0)
            {
                a=halfsum(k,c/2);
                b=halfsum(k,c/2);
            }
            else
            {
                a=halfsum(k,c/2);
                b=halfsum(k,c/2+1);
            }
            k=a+b;
        }
        return k;
    }
    void insert(data *it)
    {
        int ind = Hash_folding(it->key);
        if (table[ind] == NULL)
        {
            table[ind] = it;
        }
        else
        {
            chaininput(it, ind);
        }
        sz++;
    }
    void chaininput(data *it, int ind)
    {
        data *temp = table[ind];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = it;
    }
    bool find(int k)
    {
        int ind = Hash_folding(k);
        if (table[ind] == NULL)
        {
            return false;
        }
        else
        {
            data *head = table[ind];
            while (head != NULL)
            {
                if (head->key == k)
                    return true;
                head = head->next;
            }
            return false;
        }
    }
    void printll(data *it)
    {
        data *head = it;
        while (head != NULL)
        {
            cout << "(" << head->key << "->" << head->val << ")";
            if (head->next != NULL)
            {
                cout << "-->";
            }
            head = head->next;
        }
    }
    void print()
    {
        for (int i = 0; i < mx; ++i)
        {
            if (table[i] == NULL)
            {
                cout << i << "--> <Empty>\n";
            }
            else
            {
                cout << i << "--> ";
                printll(table[i]);
                cout << endl;
            }
        }
        cout << endl;
    }
    bool del(int k)
    {
        int ind = Hash_folding(k);
        if (table[ind] == NULL)
        {
            return false;
        }
        else
        {
            data *it = table[ind];
            if (it->key == k)
            {
                if (it->next != NULL)
                    table[ind] = it->next;
                else
                    table[ind] = NULL;
                free(it);
                sz--;
                return true;
            }
            else
            {
                data *prev = NULL;
                while (it != NULL)
                {
                    if (it->key == k)
                        break;
                    prev = it;
                    it = it->next;
                }
                if (it != NULL)
                {
                    if (it->next != NULL)
                        prev->next = it->next;
                    else
                        prev->next = NULL;
                    free(it);
                    sz--;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
};
int main()
{
    HashTable h;
    // cout<<h.Hash_folding(9);
    while (true)
    {
        int c;
        int k, v;
        cout << "1.Insert\n2.Delete\n3.Find\n4.Size\n5.Print\n\nChoose: ";
        cin >> c;
        if (c == 1)
        {
            cout << "Key: ";
            cin >> k;
            cout << "Value: ";
            cin >> v;
            data *obj;
            obj = new data(k, v);
            h.insert(obj);
        }
        else if (c == 2)
        {
            cout << "Key: ";
            cin >> k;
            if (h.del(k))
            {
                cout << "Key Deleted\n";
            }
            else
            {
                cout << "Key Not Found\n";
            }
        }
        else if (c == 3)
        {
            cout << "Key: ";
            cin >> k;
            if (h.find(k))
            {
                cout << "Key Found\n";
            }
            else
            {
                cout << "Key Not Found\n";
            }
        }
        else if (c == 4)
        {
            cout << "Size of Hash Table is " << h.sz << "\n";
        }
        else if (c == 5)
        {
            h.print();
        }
        else
        {
            break;
        }
    }
}

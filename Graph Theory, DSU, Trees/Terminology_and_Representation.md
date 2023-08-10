# Terminology and Representation

### Graph theory terminology:

[Graphs in Data Structure: Overview, Types and More [Updated] | Simplilearn](https://www.simplilearn.com/tutorials/data-structure-tutorial/graphs-in-data-structure#:~:text=A%20graph%20is%20a%20non,%2C(4%2C50%20%7D.)

### Representation:

```cpp
//Adjacency Matrix
const int N = 1e6;
int g[N][N];

int main()
{
    int v1,v2,wt;
    forn(i,m)
    {
        cin >> v1 >> v2 >> wt;
        g[v1][v2] = wt;
        g[v2][v1] = wt;
}

//Takes less time, more space
```

```cpp
//Adjacency List
const int N = 1e6;
vector<int> g[N];
//N array of vectors, meaning here there will be fixed number of vectors
//if weights given,
vector<pair<int,int>> g1[N];
int main()
{
    int v1,v2,wt;
    forn(i,m)
    {
        cin >> v1 >> v2 >> wt;
        g[v1].pb({v2,wt}); //v1 connected with v2 with path weight wt
        g[v2].pb({v1,wt});
    } 
}
///More Time, less space
```
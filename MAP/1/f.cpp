#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;

/*DFS on tree
const int N = 1e3+10;
vector<int> tree[N];
void dfs1(int vertex, int parent)
{
   for(auto child:tree[vertex]) //go to each child subtree and run dfs again
   {
      if(child!=parent) dfs1(child,vertex);
   }
}
*/
    map<string, string> mp;

int main()
{
    //fastio
    char a[100], b[100],c[100];
    while(gets(a) && a[0]!='\0')
    {
       sscanf(a,"%s %s",b,c); 
       mp[c]=b;
    }
    while(gets(a))
    {
       if(mp.find(a)!=mp.end()) cout << mp[a] << endl;
       else cout << "eh\n";
    }

    return 0;
}
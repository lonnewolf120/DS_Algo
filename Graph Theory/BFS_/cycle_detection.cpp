#include <bits/stdc++.h>
   
using namespace std;

const int N = 1e3+10;  
vector<int> g[N];
bool visited[N]; //can use a map instead too


//FIND if there's any cycle in the graph;

vector<int> par(N,0);

bool BFS_loopfind(int src)
{
	queue<int> q;
	q.push(src);
	visited[src]=true;
	
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		
		for(int i=0; i<g[v].size(); i++)
      {
        int node = g[v][i];
		
			if(!visited[node])
			{
				visited[node]=true;
				par[node]=v;
				q.push(node);
			}
			else if(par[v]!=node) return true;
		}
		return false;
	}
}


int main()
{
    int n,e,x,y; cin >> n >> e; //nodes & edges
    for (int i = 0; i < e; ++i)
    {
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);  //if undirected
    }

    bool f=false;
   for(int i=1;i<=n;++i)
   {
      if(visited[i])continue;
      if(BFS_loopfind(i)){f=true;break;}
   }
   f?cout<<"yes\n":cout<<"no\n";
   
   return 0;
}
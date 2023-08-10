# Depth-First Search (DFS)

We’ll just try to reach the max depth of  a graph/tree and after we’re at the max depth, then we’ll take steps back and traverse other nodes.

![Untitled](Depth-First%20Search%20(DFS)%20731b561acc60416189af9660e2782675/Untitled.png)

![DFS.jpg](Depth-First%20Search%20(DFS)%20731b561acc60416189af9660e2782675/DFS.jpg)

```cpp
vector<int> g[N];
bool visited[N]; //can use a map instead too

void dfs(int vertex)
{
	//take action on the vertice before moving on to next vertexes
	visited[vertex] = true;
	for(int neighbor:g[vertex])
	{
		//take action on neighbor before dfs/starting dfs on it recurcively
		if(!visited[neighbor])  dfs(neightbor);

		//take action on neighbor after dfs/exiting neighbors
	}
	//take action on vertice after exiting the vertice
}
```

[Example Concepts/Problems: (1)](Depth-First%20Search%20(DFS)%20731b561acc60416189af9660e2782675/Example%20Concepts%20Problems%20(1)%209d8cf68a5d0f4d1bb6b89748afaacaa1.csv)

[Example Concepts/Problems: (2)](Depth-First%20Search%20(DFS)%20731b561acc60416189af9660e2782675/Example%20Concepts%20Problems%20(2)%2050dec900f419436295206e6eea8d1717.csv)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
vector<int> primeCheck(N,0);

//for simplicity: 
//unmarked = 0
//marked = 1
void prepros()
{
	for (int i = 2; i < 100000; ++i)
	{
		if(primeCheck[i] == 0) //if i is unmarked, it's a prime, then
		{
			for (int j = 2; i*j <= 100000; j+=i)
			{
				primeCheck[i*j]=1; //mark all multiples of i
			}
		}
	}
}

int main()
{
	//prepros();
	int i,k, cnt=0;double n; cin >> n >> k;
	cout << pow(n,k);
	// for (int i = 2; i <= n; ++i)
	// {
	// 	if(primeCheck[i]==0)
	// 	{
	// 		cnt++;
	// 		printf("%d is the %d th prime!\n",i,cnt);
	// 	}
	// }
}
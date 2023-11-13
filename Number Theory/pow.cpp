#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
   
using namespace std;  
typedef long long ll;
typedef long double ld;
//Recursion 1:

double pow(double a, int n)
{
	if(n==0) return 1;
	if(n==1) return a;
	if(n&1) return a*pow(pow(a,n-1/2),2);
	return pow(pow(a,n/2),2);
}
//Recursion 2:
const int M = 1e9+7;
int pow2(int a, int n)
{
	if(n==0) return 1;
	if(n==1) return a;
	int t = pow(a,n/2);
  	//return t*t*pow(a,n%2); //to get exact result
	return (t*1LL*t*pow(a,n%2))%M; //to get mod result
}
//iterative:
double pow3(double a, int n)
{
	
}

int main()
{
	int n; int k; cin >> n >> k;
	cout << pow2(n,k);
	return 0;
}

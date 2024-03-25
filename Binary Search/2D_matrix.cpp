#include <bits/stdc++.h>
using namespace std;

vector<int> bin_search_2d(int n, int m, vector<vector<int>> &v)
{
	int target; cin>>target;

	for (int i = 0; i < n; ++i)
	{
		//if v[i][0] <= x <= v[i][m-1] target lies here
		if(*(v[i].begin())<= target && *(v[i].rbegin())>= target)
		{
			//do binary search to find target cause it's 1d sorted array here
			int left=v[i][0], right=v[i][m-1];
			int mid = right+ (right-left)/2;
			while(left<=right)
			{
				mid=right+(right-left)/2;
				if(mid==target)
					return vector<int>{i,mid};
				if(mid>target){
					right=mid;
				}
				else if(mid<target){
					left=mid+1;
				}
			}
			return vector<int>{-1,-1};
		}	
	}
}


//Flattening a 2D matrix for bin search
vector<int> binsearch2d(int n, int m, int target, vector<vector<int>> &v)
{
/*
   i,j    0  1  2

	  0	  1  2  3
	  1	  4  5  6
	  2	  7  8  9

		 0 1 2 3 4 5 6 7 8
		 1 2 3 4 5 6 7 8 9

	SO, to convert a matrix's 1D co-ordinate to 2D :
		col = i % m
		row = i / m
	here, m is the row(---) size

		intuition:
		in 2D every row has m numbers, so every row's index in 1D starts with multiples of m
		for determining cols in 2D, we need to find how many remove how many rows of size m have been gone by, we'll be left with col;
		so col = i%m
*/
	int leftInd = 0, rightInd = (n*m)-1; 

	while(leftInd<=rightInd){
		/*Optimization: instead of using LeftInd, rightInd we can directly use mid of 1D
		 int Li=leftInd/m, Lj=leftInd%m, left=v[Li][Lj];
		 int Ri=rightInd/m, Rj=rightInd%m, right=v[Ri][Rj];*/
		int mid=leftInd+(rightInd-leftInd)/2;
		int midRow=mid/m, midCol=mid%m, midVal=v[midRow][midCol];

		if(midVal==target){
			return vector<int>{midRow, midCol};
		}
		else if(midVal<target){
			leftInd=mid+1;
		}
		else{
			rightInd=mid-1;
		}
	}
	return vector<int>{-1,-1};
}
int main(){

	int n,m; cin>>n>>m;
	vector<vector<int>> v(n,vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>v[i][j];
		}
	}
	bin_search_2d(n,m,v);


	return 0;
}
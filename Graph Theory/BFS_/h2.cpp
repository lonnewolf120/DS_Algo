#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateMex(vector<int>& set) {
    int mex = 0;
    sort(set.begin(), set.end());
// for(auto i:set)cout<<i<<" ";
//              cout<<endl;

    for (int i = 0; i < set.size(); i++) {
        if (set[i] == mex) {
            mex++;
        }
    }

    return mex;
}
int n,m;
int dfs(vector<vector<int>>& grid, int row, int col, vector<int>& set) {


    // If we reach the bottom-right corner, calculate Mex and return
    if (row == n-1 && col == m-1) {
        set.push_back(grid[row][col]);
        //set.pop_back();
        for(auto i:set)cout<<i<<" ";
            cout<<endl;
        return calculateMex(set);
    }

    // Add the current number to the set
    set.push_back(grid[row][col]);

    int a,b;
    a = n + m; // Initialize with a large value
    b = n + m;  // Initialize with a large value
    // r[2] = n + m; // Initialize with a large value
    // r[3] = n + m;
    // Explore the right cell if within bounds
    if (col + 1 <n) {
        a = dfs(grid, row, col + 1, set);
    }

    // Explore the down cell if within bounds
    if (row + 1 <m) {
        b = dfs(grid, row + 1, col, set);
    }
    // if (col - 1 < m && col-1>0 ) {
    //     r[2] = dfs(grid, row, col - 1, set);
    // }

    // // Explore the down cell if within bounds
    // if (row - 1 < n && col-1>0) {
    //     r[3] = dfs(grid, row - 1, col, set);
    // }

    // Remove the current number from the set before backtracking
    set.pop_back();
    //sort(r,r+1);
    // Return the minimum Mex value
    return min(a,b);
}

int main() {
    int t; cin >> t;
    while(t--)
    {
        cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> set;
    int mex = dfs(grid, 0, 0, set);

    cout << mex << endl;
    }
    

    return 0;
}

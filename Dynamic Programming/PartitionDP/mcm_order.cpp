#include <bits/stdc++.h>
using namespace std;

const int N = 5; // Number of matrices
int dp[N][N];
vector<int> dimensions = {10, 20, 30, 40, 50}; // Matrix dimensions

void printMCMOrder(int i, int j, vector<vector<int>>& bracket) {
    if (i == j) {
        cout << "A" << i + 1;
        return;
    }
    cout << "(";
    printMCMOrder(i, bracket[i][j], bracket);
    cout << " x ";
    printMCMOrder(bracket[i][j] + 1, j, bracket);
    cout << ")";
}

int mcm() {
    int n = dimensions.size();

    // Initialize the DP table
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0;
    }

    vector<vector<int>> bracket(N, vector<int>(N, 0));

    for (int len = 2; len < n; ++len) {
        for (int i = 1; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    // Print the order of matrices to minimize the multiplication cost
    cout << "Optimal Parenthesization: ";
    printMCMOrder(1, n - 1, bracket);
    cout << endl;

    return dp[1][n - 1];
}

int main() {
    int minCost = mcm();
    cout << "Minimum Cost of Matrix Chain Multiplication: " << minCost << endl;

    return 0;
}

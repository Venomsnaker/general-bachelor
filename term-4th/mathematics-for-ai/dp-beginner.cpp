#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int coinChange(vector<int> &coins, int n, int sum, vector<vector<int>> &dp) {
    if (sum == 0) return dp[n][sum] = 1;

    if (n == 0 || sum < 0) return 0;

    if (dp[n][sum] != -1) return dp[n][sum];

    return dp[n][sum] = coinChange(coins, n, sum - coins[n - 1], dp) + coinChange(coins, n - 1, sum, dp);
}

int cutARod(vector<int> prices, int n) {
    vector<int> val(n + 1);
    val[0] = 0;

    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;

        for (int j = 0; j < i; j++) {
            max_val = max(max_val, prices[j] + val[i-j-1]);
        }
        val[i] = max_val;
    }
    return val[n];
}

int lcs(string x, string y) {
    int m = x.size();
    int n = y.size();
    vector<vector<int>> temp(n, vector<int> (m));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) temp[i][j] = 0;
            else if (x[i - 1] == y[j - 1]) temp[i][j] = temp[i - 1][j - 1] + 1;
            else temp[i][j] = max(temp[i-1][j], temp[i][j-1]);
        }
    }
    return temp[n][m];
}

int main() {
    // Coin Change
    int n, sum;
    n = 3, sum = 5;
    vector<int> coins = {1, 2, 3};
    vector<vector<int>> dp(n + 1, vector<int> (sum + 1, -1));
    int res = coinChange(coins, n, sum, dp);
    cout << res << endl;
    // Cutting A Rod
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    n = 8;
    cout << cutARod(prices, n) << endl;
    // Longest Common Subsequence
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << lcs(s1, s2);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Item {
    int profit, weight;

    Item(int profit, int weight) {
        this->profit = profit;
        this->weight = weight;
    }
};

bool compareRatio(struct Item a, struct Item b) {
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

int knapSack(int w, vector<int> weights, vector<int> values, int n) {
    int res = 0;
    vector<vector<int>> temp(n + 1, vector<int> (w + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0) temp[i][j] = 0;
            else {
                if (weights[i-1] <= w) {
                    temp[i][j] = max(values[i-1] + temp[i-1][j - weights[i-1]], temp[i-1][j]);
                } else {
                    temp[i][j] = temp[i-1][j];
                }
            }
        }
    }
    return temp[n][w];
}

double fractionalKnapsack(int w, vector<struct Item> arr, int n) {
    sort(arr.begin(), arr.end(), compareRatio);
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= w) {
            w -= arr[i].weight;
            finalValue += arr[i].profit;
        }
        else {
            finalValue += arr[i].profit * ((double)w / (double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int getLongestPalinSub(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    vector<vector<int>> dp(s.size() + 1, vector<int> (r.size() + 1, 0));

    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= r.length(); j++) {
            if (s[i - 1] == r[j - 1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[s.size()][r.size()];
}

int main() {
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int w = 50;
    cout << knapSack(w, weights, values, weights.size()) << endl;
    vector<struct Item> arr = {{60,10}, {100, 20}, {120, 30}}; 
    cout << fractionalKnapsack(w, arr, arr.size()) << endl;
    string s = "ohehelyu";
    cout << "The length of the LPS is " << getLongestPalinSub(s) << endl;
    return 0;
}
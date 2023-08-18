#include<iostream>
#include<vector>
using namespace std;

int subset_sum(vector<int> v, int w) {
    int n = v.size();
    int dp[n + 1][w + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (v[i - 1] <= j)
                dp[i][j] = max(v[i - 1] + dp[i - 1][j - v[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][w];
}

int main() {
    vector<int> v = { 5, 4,  7 , 10};
    int w = 18;
    cout << "Max Subset Sum: " << subset_sum(v, w) << endl;
    return 0;
}

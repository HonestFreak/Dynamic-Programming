#include<iostream>
#include<vector>
using namespace std;

int subset_sum(vector<int> v, int w) {
    int n = v.size();
    int dp[n + 1][w + 1];
    dp[0][0] = 1;
    for(int x = 1; x<=n ; x++) dp[x][0]=1;
    for(int x = 1; x<=w ; x++) dp[0][x]=0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (v[i - 1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-v[i-1]];
            else
                dp[i][j] = dp[i - 1][j];

        }
    }
    return dp[n][w];
}

int main() {
    vector<int> v = { 5, 4, 2, 1, 7};
    int w = 6;
    cout << subset_sum(v, w) << endl;
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

int subset_sum(vector<int> v, int w, vector<int> l) {
    int n = v.size();
    int dp[n + 1][w + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (l[i - 1] <= j)
                dp[i][j] = max(v[i - 1] + dp[i][j - l[i - 1]], dp[i - 1][j]); 
                // removed the '-1' from dp[i-1]
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][w];
}

int main() {
    vector<int> v = { 2,3,6,9,10,11,1};
    vector<int> l = { 1,2,3,4,5,6,7};
    int w = 7;
    cout << "Max Profit: " << subset_sum(v, w, l) << endl;
    return 0;
}

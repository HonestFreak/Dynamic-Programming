#include<iostream>
#include<vector>
using namespace std;
//returns if it is possible to get the required sum from the elements
//of the array

bool subset_sum(vector<int> v, int w) {
    int n = v.size();
    bool dp[n + 1][w + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (v[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - v[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][w];
}

int main() {
    vector<int> v = { };
    int w = 0;
    cout << subset_sum(v, w) << endl;
    return 0;
}

//count of subsets having particular difference
#include<iostream>
#include<vector>
using namespace std;

int subset_diff(vector<int> v, int w) {
  int n = v.size();
  int dp[n + 1][w + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (v[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - v[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][w];
}

int equalpart(vector<int> v, int diff){
    int sum = 0;
    for(int i: v) sum+= i;
    cout<<sum<<endl;
    cout<<(sum-diff)/2<<endl;
    return subset_diff(v, (sum-diff)/2); 
}

int main() {
    vector<int> v = { 3,6,20};
    int diff = 12;
    cout<<equalpart(v,diff);
    return 0;
}

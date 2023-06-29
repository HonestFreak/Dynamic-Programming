//leetcode 416
#include<iostream>
#include<vector>
using namespace std;

bool issubset(vector<int> v, int w) {
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
    return dp[n][w]==w;
}

bool equalpart(vector<int> v){
    int sum = 0;
    for(int i: v) sum+= i;
    if(sum%2!=0) return false;
    else return issubset(v, sum/2); 
}

int main() {
    vector<int> v = { 1,5,11,5};
    cout<<equalpart(v);
    return 0;
}

//leetcode 416
#include<iostream>
#include<vector>
using namespace std;

bool issubset(vector<int> v, int w) {
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

bool equalpart(vector<int> v){
    int sum = 0;
    for(int i: v) sum+= i;
    if(sum%2!=0) return false;
    else return issubset(v, sum/2); 
}

int main() {
    vector<int> v = { 6,4,2};
    cout<<equalpart(v);
    return 0;
}

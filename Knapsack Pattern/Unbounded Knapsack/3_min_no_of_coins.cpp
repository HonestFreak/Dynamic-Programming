//minimum no of coins to make the sum
//leetcode 322
#include<vector>
#include<iostream>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }

int main(){
    vector<int> coins = {1,3,5};
    int sum = 19;
    cout<<coinChange(coins, sum);
}
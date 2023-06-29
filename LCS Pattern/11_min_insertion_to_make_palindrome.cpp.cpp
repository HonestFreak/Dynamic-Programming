//leetcode 1312
#include<iostream>
#include<vector>
using namespace std;
//returns minimum insertion to make a palindrome
int lcs(string a) {
        int m=a.size() , n=a.size();
        string b;
        for(char c : a) b=c+b;
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<n+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
               if(a[i-1]==b[j-1]){
                  dp[i][j]= 1+dp[i-1][j-1];
               }else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               } 
            }
        }
        return m - dp[m][n];
    }

int main()
{
    string a = "hello";
    cout<<lcs(a);
return 0;
}
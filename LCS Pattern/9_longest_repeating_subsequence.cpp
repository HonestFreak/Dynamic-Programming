#include<iostream>
#include<vector>
using namespace std;

//returns longest repeating subsequence
int lcs(string text1) {
        int m=text1.size(),n=m;
        string text2 = text1;
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<n+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
               if(text1[i-1]==text2[j-1] && i!=j){  // extra condition i!=j
                  dp[i][j]= 1+dp[i-1][j-1];
               }else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               } 
            }
        }
        return dp[m][n];
    }

int main()
{
    string a = "hello";
    cout<<lcs(a);
return 0;
}
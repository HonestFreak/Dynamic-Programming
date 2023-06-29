//leetcode 583
#include<iostream>
#include<vector>
using namespace std;

//number of insertion and deletion to convert a to b
//beats 98.1% in runtime
int insdel(string a, string b){
    int m=a.size(),n=b.size();
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
        return ((m+n)-2*(dp[m][n]));
}

int main()
{
    string a = "hello";
    string b = "hkelo";
    cout<<insdel(a,b);
return 0;
}
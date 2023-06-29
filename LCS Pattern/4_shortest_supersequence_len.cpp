#include<iostream>
#include<vector>
using namespace std;

//length of shortest supersequence
int shortest_superseq_val(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<n+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
               if(text1[i-1]==text2[j-1]){
                  dp[i][j]= 1+dp[i-1][j-1];
               }else{
                   dp[i][j]=0;
               } 
            }
        }
        m+n-dp[m][n];
    }

int main()
{
    string a = "abac";
    string b = "cab";
    cout<<shortest_superseq_val(a,b);
return 0;
}
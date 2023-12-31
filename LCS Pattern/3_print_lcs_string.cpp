#include<iostream>
#include<vector>
using namespace std;

//prints the longest common subsequence
string getstring(string a, string b){
    string res = "";
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
                   dp[i][j]=0;
               } 
            }
        }

    while(m>=0 && n>=0){
        if(a[m] == b[n]) {
            res = a[m]+res;
            m-- ; n--;
        }
        else{
            if(a[m-1] > b[n-1]) m--;
            else n--; 
        }
    }
    return res;
}

int main()
{
    string a = "abac";
    string b = "cab";
    cout<<getstring(a,b);
return 0;
}
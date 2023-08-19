#include<iostream>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;

int t[1001][1001];

bool ispalindrome(string s, int i, int j){
    string temp = s.substr(i,j-i+1);
    reverse(temp.begin(),temp.end());
    return s.substr(i,j-i+1) ==temp;
}

int solve(string s, int i, int j){
    int ans=INT_MAX;
    if(i>=j) return 0;
    if(ispalindrome(s,i,j)) return 0;
    if(t[i][j]!=-1) return t[i][j];
    int left,right;
    for(int k=i; k < j; k++){
        if(t[i][k]!=-1) left = t[i][k];
        else left = solve(s,i,k);
        if(t[k+1][j]!=-1) right = t[k+1][j];
        else right = solve(s,k+1,j);

        int tempans = left + right + 1;
        ans=min(ans,tempans);
    }
    return ans;
}

int main()
{   
    memset(t,-1,sizeof(t));
    cout<<solve("apple",0,4);
    return 0;
}
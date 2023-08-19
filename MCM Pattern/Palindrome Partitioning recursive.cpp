#include<iostream>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;

bool ispalindrome(string s, int i, int j){
    string temp = s.substr(i,j-i+1);
    reverse(temp.begin(),temp.end());
    return s.substr(i,j-i+1) ==temp;
}

int solve(string s, int i, int j){
    int ans=INT_MAX;
    if(i>=j) return 0;
    if(ispalindrome(s,i,j)) return 0;
    for(int k=i; k < j; k++){
        int tempans = solve(s,i,k) + solve(s,k+1,j) + 1;
        ans=min(ans,tempans);
    }
    return ans;
}

int main()
{
    cout<<solve("apple",0,4);
    return 0;
}
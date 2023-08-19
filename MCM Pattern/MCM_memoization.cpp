#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

int t[1001][1001];
int solve(int arr[], int i, int j){
    int ans=INT_MAX;
    if(t[i][j]!=-1) return t[i][j];
    if(i>=j) return 0;
    for(int k=i; k < j; k++){
        int tempans = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        ans=min(ans,tempans);
    }
    t[i][j]=ans;
    return ans;
}

int main(){
    int arr[] = {40, 20, 30, 10, 30};
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < 1001; i++) 
        for (int j = 0; j < 1001; j++) 
            t[i][j] = -1;
    cout<< solve(arr,1,size-1);
}
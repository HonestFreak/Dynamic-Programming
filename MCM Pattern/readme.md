either string will be given or an array
array will be divided into two parts i to k , k to j
it's like divide and rule technique

temp. anwer : fun(i,j) -> fun(i,k) and fun(k,j)
merge the temp answer

i = left index
j = right index
break at k
repeat

base condition ??
think of the smallest valid input
*think of the invalid input

format:
int solve(int arr[], int i, int j)
{
    if(i>j) return 0;
    for(int k=i; k < j; k++){
        //calculate temp. answer
        tempans = solve(arr,i,k) + solve(arr,k+1,j);
        ans = fun(tempans);
    }
}

problem statement 1:
given arr[] = {40 20 30 10 30}
the array represent dimensions of matrix A1,A2..A(n-1)
find the minimum cost
Ai = arr[i-1] * arr[i]
i starts from 1 while j = size-1
at i==j cost i 0, bcz there is no other matrix to which the remaining matrix could be multiplied (and the size of matrix is 1)
int solve(int arr[], int i, int j){
    int ans=INT_MAX;
    if(i>=j) return 0;
    for(int k=i; k < j; k++){
        int tempans = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        ans=min(ans,tempans);
    }
    return ans;
}

memoization
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

palindrome partitioning
given a string, make minimum paritions such that all substrings are palindrome.
worst case answer = n-1
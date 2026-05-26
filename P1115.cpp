#include<iostream>
using namespace std;
const int N = 2e5 + 9;
int a[N];
int dp[N];
int n;

int main (){
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  dp[1] = a[1];
  int maxSum = a[1];
  for(int i = 2; i <= n; i++){
    dp[i] = max(a[i], dp[i-1] + a[i]);
    maxSum = max(dp[i], maxSum);
  }
  cout << maxSum;
  return 0;
}
#include<iostream>
using namespace std;
const int N = 5e3 + 9;
const int M = 5e5 + 9;

int a[N];
bool dp[M];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];

  dp[0] = true;
  for(int i = 1; i <= n; i++){
    for(int j = 5e5 + 9; j >= a[i]; j--){
      dp[j] |= dp[j - a[i]];
    }
  }

  long long sum = 0;
  for(int i = 0; i < M; i++){
    if(dp[i]) sum++;
  }
  cout << sum;
  return 0;
}
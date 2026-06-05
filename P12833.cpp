#include<iostream>
using namespace std;
const int N = 1e5 + 9;
const long long mod = 1e9 + 7;
int x;
long long dp[N];
long long zero[N];
long long one[N];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  dp[1] = 0;
  dp[2] = 0;
  zero[1] = 1;
  one[2] = 1;
  for(int i = 3; i <= N; i++){
    zero[i] = (zero[i-1] + zero[i-2]) % mod;
    one[i] = (one[i-1] + one[i-2]) % mod;
    dp[i] = (dp[i-1] + dp[i-2] + one[i-2] * zero[i-1]) % mod;
  }
  while (t--) {
    cin >> x;
    cout << dp[x] << endl;
  }
  
  return 0;
}
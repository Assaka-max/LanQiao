#include<iostream>
using namespace std;
const int N = 1e5 + 9;
long long a[N];
long long b[N];
long long dp[N];
int n, x;
long long sum = 0;

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> x;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) b[i] = x - a[i];
  long long max_sum = b[1];
  for(int i = 1; i <= n; i++) {
    dp[i] = max(b[i], dp[i-1] + b[i]);
    max_sum = max(max_sum, dp[i]);
  }
  bool flag = false;
  for(int i = 1; i <= n; i++) if(b[i] > 0) flag = true;
  for(int i = 1; i <= n; i++) sum += a[i];
  
  if(flag) cout << max_sum + sum;
  else cout << sum;
  return 0;
}
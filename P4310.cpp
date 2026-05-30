#include<iostream>
using namespace std;
const int N = 1e3 + 9;
int a[N];
int n;
int memo[N];
int best[32];

int dfs(int index) {
  if (index == 0) return 0;
  if (memo[index]) return memo[index];
  
  dfs(index - 1);
  
  int mx = 0;
  for (int i = 0; i < 31; i++) {
    if ((a[index] >> i) & 1) {
      mx = max(mx, best[i]);
    }
  }
  int sum = mx + 1;
  
  for (int i = 0; i < 31; i++) {
    if ((a[index] >> i) & 1) {
      best[i] = max(best[i], sum);
    }
  }
  
  return memo[index] = sum;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dfs(i));
  }
  cout << ans;
  return 0;
}
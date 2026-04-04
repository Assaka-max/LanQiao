#include<iostream>
using namespace std;
int m, n;
long long dp[100005];
pair<int, int> a[505];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> m >> n;
  for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  for(int i = 0; i <= m; i++) dp[i] = 0;
  for(int i = 1; i <= n; i++){
    for(int j = a[i].second; j <= m; j++){
      dp[j] = max(dp[j], dp[j-a[i].second] + a[i].first);
    }
  }
  cout << dp[m];
  return 0;
}
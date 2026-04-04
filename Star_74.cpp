#include<iostream>
#include<cmath>
using namespace std;
const int T = 1005;
const int M = 105;
int t, m;
pair<int, int> a[M];
long long dp[M][T];
void ans(){
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= t; j++){
      if(j >= a[i].first) dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i].first] + a[i].second);
      else dp[i][j] = dp[i-1][j];
    }
  }
  cout << dp[m][t] << '\n';
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t >> m;
  while(t != 0 && m != 0){
    for(int i = 1; i <= m; i++){
      int t, w; cin >> t >> w;
      a[i] = {t, w};
    }
    ans();
    cin >> t >> m;
  }
  return 0;
}
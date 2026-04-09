#include<iostream>
#include<vector>
using namespace std;
int m, n;
long long dp[2050];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> m >> n;
  for(int i = 1; i <= n; i++){
    int s, w, v; cin >> s >> w >> v;
    vector<int> vec;
    int x = 1;
    while(x <= s) s -= x, vec.push_back(x), x <<= 1;
    if(s != 0) vec.push_back(s);
    for(auto &k : vec){
      for(int j = m; j >= v * k; j--) dp[j] = max(dp[j], dp[j - v * k] + w * k);
    }
  }
  cout << dp[m];
  return 0;
}
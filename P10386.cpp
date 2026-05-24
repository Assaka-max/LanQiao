#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 17;
int num[N];
int memo[N][N][N];
int prefix[N];
int n, k;
//  1  2  3  4  5
int dfs(int l, int r, int k){
  if(l == r) return num[l];
  if(k == 0) return prefix[r] - prefix[l-1];
  if(memo[l][r][k]) return memo[l][r][k];
  int res = -1;
  for(int i = l; i <= r - k; i++){
    res = max(res, (prefix[i] - prefix[l-1]) * dfs(i+1, r, k-1));
  }
  return memo[l][r][k] = res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> num[i];
    prefix[i] = prefix[i-1] + num[i];
  }
  cout << dfs(1, n, k);
  return 0;
}

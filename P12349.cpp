#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e3 + 5;
int a[N][N];
int memo[N][2][2];
int n, m;

int value(int step, bool before, bool later, bool current){
  int sum = 0;
  int pre[N];
  if(step > 1){
    for(int i = 1; i <= m; i++){
      pre[i] = a[step-1][i];
      if(before) pre[i] ^= 1;
    }
  }
  int nxt[N];
  if(step < n){
    for(int i = 1; i <= m; i++){
      nxt[i] = a[step+1][i];
      if(later) nxt[i] ^= 1;
    }
  }
  int cur[N];
  for(int i = 1; i <= m; i++){
    cur[i] = a[step][i];
    if(current) cur[i] ^= 1;
  }
  for(int i = 1; i <= m; i++){
    int cnt = 0;
    if(i > 1 && cur[i] == cur[i-1]) cnt++;
    if(i < m && cur[i] == cur[i+1]) cnt++;
    if(step > 1 && cur[i] == pre[i]) cnt++;
    if(step < n && cur[i] == nxt[i]) cnt++;
    sum += cnt * cnt;
  }
  return sum;
}

int dfs(int step, bool before, bool current){
  if(step == n) return value(step, before, 0, current);
  if(memo[step][before][current] != -1) return memo[step][before][current];
  int sum = 0;
  sum = max(sum, dfs(step + 1, current, 0) + value(step, before, 0, current));
  sum = max(sum, dfs(step + 1, current, 1) + value(step, before, 1, current));
  return memo[step][before][current] = sum;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    string s;
    cin >> s;
    for(int j = 1; j <= m; j++) a[i][j] = s[j-1] - '0';
  }
  memset(memo, -1, sizeof(memo));
  int res = 0;
  res = max(res, dfs(1, 0, 0));
  res = max(res, dfs(1, 0, 1));
  cout << res;
  return 0;
}
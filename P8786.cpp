#include<iostream>
#include<cstring>
using namespace std;
const int N = 205;
const long long MOD = 1e9 + 7;
int memo[N][N][N][2];
int n, m;

long long dfs(int x, int flower, int store, int last){
  if(x > m - flower) return 0;
  if(x < 0 || flower > m || store > n) return 0;
  if(flower == m && store == n && x == 0){
    if(last == 0) return 1;
    else return 0;
  }
  if(memo[x][flower][store][last] != -1) return memo[x][flower][store][last];
  long long ans = 0;
  ans = (ans + dfs(x * 2, flower, store + 1, 1)) % MOD;
  ans = (ans + dfs(x - 1, flower + 1, store, 0)) % MOD;
  return memo[x][flower][store][last] = ans;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  memset(memo, -1, sizeof(memo));
  cout << dfs(2, 0, 0, 0);
  return 0;
}
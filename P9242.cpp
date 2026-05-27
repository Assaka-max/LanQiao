#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5 + 5;
int memo[N][10];
int n;
int a[N];

int prefix(int x){
  while(x >= 10) x /= 10;
  return x;
}

int dfs(int index, int before){
  if(index > n) return 0;
  if(memo[index][before] != -1) return memo[index][before];
  int res = dfs(index + 1, before);
  if(before == -1 || before == prefix(a[index])){
    res = max(res, dfs(index + 1, a[index] % 10) + 1);
  }
  if(before == -1) return res;
  else return memo[index][before] = res;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  memset(memo, -1, sizeof(memo));
  cout << n - dfs(1, -1);
  return 0;
}
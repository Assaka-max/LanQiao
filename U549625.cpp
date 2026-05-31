#include<iostream>
#include<cstring>
using namespace std;
const int N = 2e5 + 9;
const long long INF = -0x3f3f3f3f3f3f3f3f;
long long a[N];
int n;
long long memo_l[N];
long long memo_r[N];

long long dfs_l(int index){
  if(index == 1) return memo_l[index] = a[1];
  if(memo_l[index] != INF) return memo_l[index];
  long long sum = max(a[index], dfs_l(index - 1) + a[index]);
  return memo_l[index] = sum;
}

long long dfs_r(int index){
  if(index == n) return memo_r[index] = a[n];
  if(memo_r[index] != INF) return memo_r[index];
  long long sum = max(a[index], dfs_r(index + 1) + a[index]);
  return memo_r[index] = sum;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 0; i < N; i++){
    memo_l[i] = INF;
    memo_r[i] = INF;
  }
  dfs_l(n);
  dfs_r(1);
  for(int i = 1; i <= n; i++){
    cout << memo_l[i] + memo_r[i] - a[i] << ' ';
  }
  return 0;
}
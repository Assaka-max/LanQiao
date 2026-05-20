#include<iostream>
#include<cmath>
using namespace std;
const int N = 22;
int a[N];
int n, k;
int ans = 0;

bool isPrime(int x){
  if(x < 2) return false;
  int limit = sqrt(x);
  for(int i = 2; i <= limit; i++){
    if(x % i == 0) return false;
  }
  return true;
}

void dfs(int start, int selected, int sum){
  if(k - selected > n - start + 1) return;
  if(selected == k){
    if(isPrime(sum)) ans++;
    return;
  }
  for(int i = start; i <= n; i++){
    dfs(i + 1, selected + 1, sum + a[i]);
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> a[i];
  dfs(1, 0, 0);
  cout << ans;
  return 0;
}
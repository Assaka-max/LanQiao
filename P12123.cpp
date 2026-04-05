#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6 + 9;
int n;
int a[N];
int parent[N];
int t[N];
int ans = 0;

int root(int x){
  if(parent[x] != x) parent[x] = root(parent[x]);
  return parent[x];
}

void merge(int x, int y){
  parent[root(x)] = root(y);
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) parent[i] = i;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    if(root(i) != root(a[i])) merge(i, a[i]);
  }
  for(int i = 1; i <= n; i++) t[root(i)]++;

  for(int i = 1; i < n; i++){
    if(root(i) != root(i+1)) ans = max(ans, t[root(i)]+t[root(i+1)]);
    else ans = max(ans, t[root(i)]);
  }
  ans = max(ans, t[n]);
  cout << ans;
  return 0;
}
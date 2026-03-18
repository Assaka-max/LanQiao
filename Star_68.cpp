#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 2e5 + 9;
const int M = 2e5 + 9;
int n, m;
int pre[N];
int ans[N];

int root(int x){
  if(pre[x] == x) return x;
  else return pre[x] = root(pre[x]);
}

void merge(int x, int y){
  int rx = root(x);
  int ry = root(y);
  if(rx != ry) pre[rx] = ry;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) pre[i] = i;
  for(int i = 1; i <= m; i++){
    int u, v; cin >> u >> v;
    merge(u, v);
  }

  for(int i = 1; i <= n; i++) ans[root(i)]++;
  vector<int> vec;
  for(int i = 1; i <= n; i++) if(ans[i]) vec.push_back(ans[i]);
  sort(vec.begin(), vec.end());
  for(int &x : vec) cout << x << ' ';
  return 0;
}
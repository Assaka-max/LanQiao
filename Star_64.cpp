#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e5+9;
int vis[N];
vector<int> p[N];
vector<int> ans;
void dfs(int x){
  if(p[x].empty()) {
    ans.push_back(x);
    vis[x] = 1;
    return;
  }
  ans.push_back(x);
  vis[x] = 1;
  for(auto & item : p[x]){
    if(vis[item]) continue;
    dfs(item);
  }
  return;
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int a, b;cin >> a >> b;
    p[a].push_back(b);
  }

  dfs(1);
  sort(ans.begin(), ans.end());
  for(auto & x : ans) cout << x << ' ';
  return 0;
}
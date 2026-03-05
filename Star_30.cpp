#include<iostream>
#include<vector>
using namespace std;
const int N = 15;
int n;
int vis[N];
int ans[N];

void dfs(int dep){
  if(dep > n){
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
    return;
  }
  for(int i = 1; i <= n; i++){
    if(vis[i]) continue;
    vis[i] = true;
    ans[dep] = i;
    dfs(dep + 1);
    ans[dep] = 0;
    vis[i] = false;
  }
  
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  dfs(1);
  return 0;
}
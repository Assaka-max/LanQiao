#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int const N = 5000+5;
int const INF = 0x3f3f3f3f;
int n, m;
int c[N];
vector<int> graph[N];
bool vis[N];


void bfs(int a, int b){
  memset(vis, 0, sizeof(vis));
  queue<pair<int, int>> q;
  q.push({a, 0});
  while(!q.empty()){
    int u = q.front().first;
    int dis = q.front().second;
    q.pop();
    if(u == b) {
      cout << dis << '\n';
      return;
    }
    if(vis[u]) continue;
    vis[u] = true;
    for(auto &next : graph[u]) q.push({next, dis+1});
  }
  
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> c[i];
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    graph[c[u]].push_back(c[v]);
    graph[c[v]].push_back(c[u]);
  }
  
  while(m--){
    int u, v; cin >> u >> v;
    bfs(c[u], c[v]);
  }
  
  return 0;
}
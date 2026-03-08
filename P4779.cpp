#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
const int N = 1e5 + 9;
const int M = 2e5 + 9;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, s;
  cin >> n >> m >> s;
  vector<pair<int, int>> graph[N];
  for(int i = 1; i <= m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }
  int dist[N] = {INT16_MAX};
  dist[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});
  while(!pq.empty()){
    int current_dist = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if(current_dist > dist[u]) continue;
    for(auto &edge : graph[u]){
      int v = edge.first;
      int w = edge.second;
      if(dist[u] + w < dist[v]){
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
  for(int i = 1; i <= n; i++){
    cout << dist[i] << ' ';
  }
  return 0;
}
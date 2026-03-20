#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N = 2e5 + 9;
const int M = 2e5 + 9;
const int INF = 0x3f3f3f3f;
int n, m;
int dist[N];
vector<pair<int, int>> map[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(){
  while(!pq.empty()){
    int current_dist = pq.top().first;
    int current_dot = pq.top().second;
    pq.pop();
    if(current_dist > dist[current_dot]) continue;
    for(auto &x : map[current_dot]){
      int out_dot = x.first;
      int w = x.second;
      if(current_dist + w < dist[out_dot]){
        dist[out_dot] = current_dist + w;
        pq.push({dist[out_dot], out_dot});
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    int u, v, w; cin >> u >> v >> w;
    map[u].push_back({v, w});
  }
  for(int i = 1; i <= n; i++) dist[i] = INF;
  dist[1] = 0;
  pq.push({0, 1});
  dijkstra();
  if(dist[n] == INF) cout << -1;
  else cout << dist[n];
  return 0;
}
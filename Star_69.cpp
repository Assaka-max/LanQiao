#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1e3 + 9;
const int M = 1e5 + 9;
int n, m;
vector<pair<int, int>> map[N];
int dist[N];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    int u, v, w; cin >> u >> v >> w;
    map[u].push_back({v, w});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 1});
  memset(dist, 0x3f, sizeof(dist));
  dist[1] = 0;
  while(!pq.empty()){
    int current_dist = pq.top().first;
    int current_dot = pq.top().second;
    pq.pop();
    if(current_dist > dist[current_dot]) continue;
    for(auto &x : map[current_dot]){
      int out_dot = x.first;
      int w = x.second;
      if(dist[current_dot] + w < dist[out_dot]){
        dist[out_dot] = dist[current_dot] + w;
        pq.push({dist[out_dot], out_dot});
      }
    }
  }
  if(dist[n] < 1e9 + 9) cout << dist[n];
  else cout << -1;
  return 0;
}
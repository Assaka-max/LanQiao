#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int INT = 2e9;
const int N = 1e4 + 9;
const int M = 5e4 + 9;
int n, m, k, s, t;
vector<pair<int, int>> graph[N];
vector<vector<int>> dist(N, vector<int>(10, INT));

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  cin >> s >> t;
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  dist[s][0] = 0;
  pq.push({0, {s, 0}});
  while(!pq.empty()){
    auto current = pq.top();
    pq.pop();
    int current_cost = current.first;
    int current_city = current.second.first;
    int used_free = current.second.second;

    if(current_cost > dist[current_city][used_free]) continue;

    for(auto &neighbor : graph[current_city]){
      int next_city = neighbor.first;
      int cost = neighbor.second;

      if(current_cost + cost < dist[next_city][used_free]){
        dist[next_city][used_free] = current_cost + cost;
        pq.push({dist[next_city][used_free], {next_city, used_free}});
      }

      if(used_free < k && current_cost < dist[next_city][used_free + 1]){
        dist[next_city][used_free + 1] = current_cost;
        pq.push({dist[next_city][used_free + 1], {next_city, used_free + 1}});
      }
    }
  }

  int min_cost = INT;
  for(int i = 0; i <= k; i++){
    min_cost = min(min_cost, dist[t][i]);
  }
  cout << min_cost;
  return 0;
}
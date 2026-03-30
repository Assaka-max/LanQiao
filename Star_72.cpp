#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5+5;
const int M = 1e5+5;
long long totalweight;
int n, m;

struct Edge{
  int to;
  int weight;
};

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

vector<Edge> graph[N];
long long minEdge[N];
int vis[N];

long long prim(){
  priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
  minEdge[1] = 0;
  pq.push({1, 0});
  totalweight = 0;

  while(!pq.empty()){
    int u = pq.top().first;
    int w = pq.top().second;
    pq.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    totalweight += w;
    for(auto &edge : graph[u]){
      int to = edge.to;
      int weight = edge.weight;
      if(!vis[to] && weight < minEdge[to]){
        minEdge[to] = weight;
        pq.push({to, weight});
      }
    }
  }
  for(int i = 1; i <= n; i++){
    if(!vis[i]) return -1;
  }
  return totalweight;
};

int main(){
  ios::sync_with_stdio(0) , cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    int u, v, w; cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }
  for(int i = 1; i <= n; i++) minEdge[i] = INF;
  memset(vis, 0, sizeof(vis));
  cout << prim();
  return 0;
}
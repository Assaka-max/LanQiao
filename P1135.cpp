#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 205;
vector<int> graph[N];
int vis[N];
int n, a, b;

void bfs(int s, int e){
  if(a == b){
    cout << 0;
    return;
  }
  queue<pair<int, int>> q;
  q.push({s, 0});
  vis[s] = 1;
  while (!q.empty())
  {
    pair<int, int> dot = q.front();
    q.pop();
    for(auto &out_dot : graph[dot.first]){
      if(vis[out_dot]) continue;
      if(out_dot == e) {
        cout << dot.second + 1;
        return;
      }
      q.push({out_dot, dot.second+1});
      vis[out_dot] = 1;
    }
  }
  cout << -1;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> a >> b;
  for(int i = 1; i <= n; i++) {
    int k; cin >> k;
    if(i - k > 0) graph[i].push_back(i-k);
    if(i + k <= n) graph[i].push_back(i+k);
  }
  bfs(a, b);
  return 0;
}
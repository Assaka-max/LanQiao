#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 300 + 9;
const int M = 1e5 + 9;
const int INF = 0x3f3f3f3f;
  int n, m, q;
int dist[N][N];

void floyd(){
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  memset(dist, INF, sizeof(dist));
  for(int i = 1; i <= n; i++) dist[i][i] = 0;
  for(int i = 1; i <= m; i++){
    int u, v, w;cin >> u >> v >> w;
    dist[u][v] = min(dist[u][v], w);
  }
  floyd();
  while(q--){
    int a, b; cin >> a >> b;
    if(dist[a][b] == INF) cout << -1;
    else cout << dist[a][b] << "\n";
  }
  return 0;
}
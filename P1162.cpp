#include<iostream>
#include<queue>
using namespace std;
const int N = 31;
int graph[N][N];
int n;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool bfs(int x, int y){
  queue<pair<int, int>> q;
  int vis[N][N] = {0};
  q.push({x, y});
  vis[x][y] = 1;
  while(!q.empty()){
    pair<int, int> top = q.front();
    q.pop();
    for(int i = 0; i < 4; i++){
      int nx = top.first + dx[i];
      int ny = top.second + dy[i];
      if(vis[nx][ny] || graph[nx][ny] == 1) continue;
      if(graph[nx][ny] == 0) {
        q.push({nx, ny});
        vis[nx][ny] = 1;
      }
      else return false;
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++) graph[i][j] = -1;
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++) cin >> graph[i][j];
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(graph[i][j] == 1) cout << 1 << ' ';
      else if(bfs(i, j)) cout << 2 << ' ';
      else cout << 0 << ' ';
    }
    cout << endl;
  }
  return 0;
}
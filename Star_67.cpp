#include<iostream>
#include<queue>
#include <cstring>
using namespace std;
const int N = 1000 + 9;
const int M = 1000 + 9;
int n, m;
int map[N][M];
int d[N][M];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool inmap(int x, int y){
  return x >= 1 && x <= n && y >= 1 && y <= m;
}
void bfs(int x, int y){
  memset(d, -1, sizeof d);
  queue<pair<int, int>> q;
  q.push({x, y});
  d[x][y] = 0;
  while(!q.empty()){
    pair<int, int> cur = q.front();
    q.pop();
    int x = cur.first;
    int y = cur.second;
    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(inmap(nx, ny) && !map[nx][ny] && d[nx][ny] == -1){
        d[nx][ny] = d[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> map[i][j];
    }
  }


  bfs(1, 1);
  cout << d[n][m];
  return 0;
}
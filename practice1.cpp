#include<iostream>
#include<queue>
using namespace std;
const int N = 105;
const int M = 105;
int n, m;
int start_x, start_y, end_x, end_y;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
char map[N][M];
int dist[N][M];

bool inmap(int x, int y){
  return x >= 1 && x <= n && y >= 1 && y <= m;
}

void bfs(){
  queue<pair<int, int>> q;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++) dist[i][j] = -1;
  }
  q.push({start_x, start_y});
  dist[start_x][start_y] = 0;
  while(!q.empty()){
    pair<int, int> current = q.front();
    q.pop();
    int current_x = current.first;
    int current_y = current.second;

    for(int i = 0; i < 4; i++){
      int nx = current_x + dx[i];
      int ny = current_y + dy[i];

      if(inmap(nx, ny) && dist[nx][ny] == -1 && (map[nx][ny] == '.' || map[nx][ny] == 'T')){
        dist[nx][ny] = dist[current_x][current_y] + 1;
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
      if (map[i][j] == 'S') {
        start_x = i;
        start_y = j;
      }
      if (map[i][j] == 'T') {
        end_x = i;
        end_y = j;
      }
    }
  }
  cout << dist[end_x][end_y];
  return 0;
}
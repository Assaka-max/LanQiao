#include<iostream>
using namespace std;
int n;
char grid[105][105];
bool vis[105][105];
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

string word = "yizhong";

void dfs(int x, int y){
  for(int i = 0; i < 8; i++){
    bool flag = true;
    for(int j = 1; j < 7; j++){
      int nx = x + dx[i] * j;
      int ny = y + dy[i] * j;
      if(nx < 1 || ny < 1 || nx > n || ny > n || grid[nx][ny] != word[j]){
        flag = false;
        break;
      }
    }
    if(flag){
      for(int j = 0; j < 7; j++){
        int nx = x + dx[i] * j;
        int ny = y + dy[i] * j;
        vis[nx][ny] = true;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++) cin >> grid[i][j];
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(grid[i][j] == 'y') dfs(i, j);
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(vis[i][j] == true) cout << grid[i][j];
      else cout << '*';
    }
    cout << endl;
  }
  return 0;
}
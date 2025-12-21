#include<iostream>
using namespace std;
const int N = 1000 + 9;
int a[N][N];
int diff[N][N];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    diff[x1][y1] += 1;
    diff[x1][y2+1] -= 1;
    diff[x2+1][y1] -= 1;
    diff[x2+1][y2+1] += 1;
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++) {
      a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + diff[i][j];
      cout << a[i][j] << ' ';
    }
    cout << "\n";
  }
  
  return 0;
}
#include<iostream>
using namespace std;
const int N = 1000 + 9;
int a[N][N];
int prefix[N][N];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++) {
      cin >> a[i][j];
      prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j];
    }
  }

  while (q--){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long sum;
    sum = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];
    cout << sum << "\n";
    }
  
  return 0;
}
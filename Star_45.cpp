#include<iostream>
using namespace std;
const int N = 1e3 + 5;
const int M = 1e3 + 5;
const long long p = 1e9+7;
long long c[N][M];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; i++) c[i][0] = (long long) 1;
  for(int i = 1; i < n; i++){
    for(int j = 1; j <= i; j++){
      c[i][j] = (c[i-1][j] + c[i-1][j-1]) % p;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cout << c[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
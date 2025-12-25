#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100000 + 5;
const int M = 100000 + 5;
int road[M];
int diff_road[N];
int times[N];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; i++) cin >> road[i];
  for(int i = 1; i < m; i++){
    int r = max(road[i], road[i+1]);
    int l = min(road[i], road[i+1]);
    diff_road[l]++;
    diff_road[r]--;
  }
  for(int i = 1; i < n; i++) times[i] = times[i-1] + diff_road[i];

  int road_price[M] = {0};
  int road_buy_ic[M] = {0};
  long long sum_price = 0;

  for(int i = 1; i < n; i++){
    long long a, b, c;
    cin >> a >> b >> c;
    sum_price = sum_price + min(a*times[i], c + b*times[i]);
  }
  cout << sum_price;
  return 0;
}
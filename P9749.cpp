#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 5;
int dis[N];
int price[N];
int a[N];
const int INF = 0x3f3f3f3f;
long long s = 0;
int n, d;
long long res = 0;

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> d;
  for(int i = 2; i <= n; i++) cin >> dis[i];
  for(int i = 1; i <= n; i++) cin >> price[i];
  for(int i = 2; i <= n; i++) a[i] = dis[i] + a[i-1];
  int mi = price[1];
  for(int i = 1; i < n; i++){
    long long need = 0;
    mi = min(mi, price[i]);
    if(s < a[i+1] - a[i]) {
      int next = i + 1;
      while(next <= n && price[next] >= mi) next++;
      if(next > n) next = n;
      need = (a[next] - a[i] - s + d - 1) / d;
      res = res + (need * mi);
      s = s + (need * d);
    }
    s -= a[i+1] - a[i];
  }
  cout << res;
  return 0;
}
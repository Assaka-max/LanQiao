#include<iostream>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int n, m;

int check(int mid){
  int res = 0;
  for(int i = 1; i <= n; i++) {
    int d = a[i] - a[i-1];
    if(d <= mid) continue;
    if(d % mid == 0) res = res + (d / mid) - 1;
    else res = res + (d / mid);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cin.tie(0);
  cin >> n >> m;
  m++;
  for(int i = 1; i <= n; i++) cin >> a[i];
  int l = 1, r = 1e9;
  while(l + 1 != r){
    int mid = (l + r) / 2;
    if(check(mid) > m) l = mid;
    else r = mid;
  }
  if(check(1) == m) cout << 1;
  else cout << r;
  return 0;
}
#include<iostream>
using namespace std;
const int N = 1e6 + 9;
int a[N];

long long check(int mid){
  long long sum = 0;
  for(int i = 1; i <= N; i++){
    if(a[i] <= mid) continue;
    sum += a[i] - mid;
  }
  return sum;
} 

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  long long m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  int l = 1;
  int r = 4e5 + 9;
  while (l+1 != r){
    int mid = (l+r)/2;
    if(check(mid) >= m) l = mid;
    else r = mid;
  }
  if(check(1) < m) cout << 0;
  else cout << l;
  return 0;
}
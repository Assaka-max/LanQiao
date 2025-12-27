#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int n, k;

long long check(int mid){
  long long sum = 0;
  for(int i = 1; i <= n; i++) sum += a[i] / mid;
  return sum;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  int l = 1;
  int r = 1e8 + 9;
  while (l+1 != r){
    int mid = (l+r)/2;
    if(check(mid) >= k) l = mid;
    else r = mid; 
  }
  if(check(1) < k) cout << 0;
  else cout << l;
  return 0;
}
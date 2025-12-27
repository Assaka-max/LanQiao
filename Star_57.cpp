#include<iostream>
using namespace std;
const int N = 2e5 + 9;
int a[N];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> a[i];
  while (q--){
    int x;
    cin >> x;
    int l = 0;
    int r = n;
    while (l+1 != r){
      int mid = (l + r)/2;
      if(a[mid] < x) l = mid;
      else r = mid;
    }
    if(a[r] == x) cout << r << ' ';
    else cout << -1 << ' ';
  }
  
  return 0;
}
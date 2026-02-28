#include<iostream>
using namespace std;
const int N = 1e6 + 9;
int n, m;
int a[N];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  while(m--){
    int num; cin >> num;
    int l = 1;
    int r = n+1;
    while(l + 1 != r){
      int mid = (l+r)/2;
      if(a[mid] < num) l = mid;
      else r = mid;
    }
    if(a[1] == num) cout << 1 << ' ';
    else if(a[r] == num) cout << r << ' ';
    else cout << -1 << ' ';
  }
  return 0;
}
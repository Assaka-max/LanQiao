#include<iostream>
using namespace std;
const int N = 2*1e5 + 9;
int a[N];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++){
    int ans = 0;
    while (a[i])
    {
      if(a[i] & 1) ans++;
      a[i] >>= 1;
    }
    cout << ans << ' ';
  }
  return 0;
}
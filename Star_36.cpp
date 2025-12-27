#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int c[N] = {0};
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 1, j = 1; j <= n; j++){
      c[a[j]]++;
      while(c[a[j]] > 1){
        c[a[i]]--;
        i++;
      }
      ans = max(ans, j - i + 1);
    }
    cout << ans << '\n';
  }
  
  return 0;
}
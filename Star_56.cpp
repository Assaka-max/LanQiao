#include<iostream>
#include<algorithm>
using namespace std;
const int N = 3e6 + 9;
int a[N];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}
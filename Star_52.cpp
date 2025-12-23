#include<iostream>
using namespace std;
const int N = 1000+5;
int a[N];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int x = a[1];
    for(int i = 2; i <= n; i++) x ^= a[i];
    cout << x << '\n';
  }
  
  return 0;
}
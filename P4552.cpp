#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 9;
long long a[N];
long long diff[N];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) diff[i] = a[i] - a[i-1];
  long long pos = 0;
  long long nag = 0;
  for(int i = 2; i <= n; i++){
    if(diff[i] > 0) pos += diff[i];
    else nag += abs(diff[i]);
  }
  long long sum = max(pos, nag);
  long long res = abs(pos - nag) + 1;
  cout << sum << '\n' << res;
  return 0;
}
#include<iostream>
using namespace std;
const int N = 5e4 + 9;
long long a[N];
long long prefix[N];
int first[7], last[7];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n; cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i];
  for(int i = 1; i <= n; i++) prefix[i] %= 7; 
  for(int i = n; i >= 1; i--) first[prefix[i]] = i;
  for(int i = 1; i <= n; i++) last[prefix[i]] = i;
  first[0] = 0;
  int res = 0;
  for(int i = 0; i <= 6; i++) res = max(last[i] - first[i], res);
  cout << res;
  return 0;
}
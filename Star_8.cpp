#include<iostream>
using namespace std;
const long long N = 100005;
long long a[N];
long long diff[N];
long long prefix[N];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, p, q;
  cin >> n >> p >> q;

  for(int i = 1; i <= n; i++) cin >> a[i];

  for(int i = 0; i < n + 2; i++) diff[i] = 0;

  while (p--)
  {
    int l, r;
    long long x;
    cin >> l >> r >> x;
    diff[l] += x;
    diff[r+1] -= x;
  }

  prefix[0] = 0;
  long long curr_add = 0;
  for(int i = 1; i <= n; i++){
    curr_add += diff[i];
    a[i] += curr_add;
    prefix[i] = a[i] + prefix[i-1];
  }

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << prefix[r] - prefix[l-1] << "\n";
  }
  
  return 0;
}
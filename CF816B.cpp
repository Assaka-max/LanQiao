#include<iostream>
using namespace std;
const int N = 2e5 + 9;
int a[N];
int diff[N];
int prefix[N];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k, q; cin >> n >> k >> q;
  while(n--){
    int l, r; cin >> l >> r;
    diff[l]++; diff[r+1]--;
  }
  for(int i = 1; i <= N; i++) a[i] = a[i-1] + diff[i];
  for(int i = 1; i <= N; i++) {
    if(a[i] < k) a[i] = 0;
    else a[i] = 1;
  }
  for(int i = 1; i <= N; i++) prefix[i] = prefix[i-1] + a[i];
  while(q--){
    int l, r; cin >> l >> r;
    cout << prefix[r] - prefix[l-1] << endl;
  }
  return 0;
}
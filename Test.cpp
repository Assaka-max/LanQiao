#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e6 + 9;
int a[N];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k; cin >> n >> k;
  int ans = -1;
  for(int i = 1; i <= n; i++) cin >> a[i];
  int q[N];
  int front = 1; int back = 0;
  for(int i = 1; i <= n; i++){
    if(back >= front && i - q[front] + 1 > k) front++;
    while(a[q[back]] >= a[i]) back--;
    back++; q[back] = i;
    if(i >= k) ans = max(ans, a[q[back]] - a[q[front]]);
  }
  cout << ans;
  return 0;
}
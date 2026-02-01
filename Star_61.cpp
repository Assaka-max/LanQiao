#include<iostream>
using namespace std;
const int N = 2e5 + 9;
int a[N];
int dq[N];
int hh = 1, tt = 0;

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> a[i];

  //最大值
  for(int i = 1; i <= n; i++){
    while(hh <= tt && dq[hh] <= i-k) hh++;
    while(hh <= tt && a[dq[tt]] <= a[i]) tt--;
    dq[++tt] = i;
    if(i >= k) cout << a[dq[hh]] << ' ';
  }

  cout << "\n";
  hh = 1, tt = 0;

  //最小值
  for(int i = 1; i <= n; i++){
    while(hh <= tt && dq[hh] <= i-k) hh++;
    while(hh <= tt && a[dq[tt]] >= a[i]) tt--;
    dq[++tt] = i;
    if(i >= k) cout << a[dq[hh]] << ' ';
  }
  return 0;
}
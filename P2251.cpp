#include<iostream>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int dq[N];;
int hh = 1, tt = 0;

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++){
    while(hh <= tt && i - dq[hh] + 1 > m) hh++;
    while(hh <= tt && a[dq[tt]] >= a[i]) tt--;
    dq[++tt] = i;
    if(i >= m) cout << a[dq[hh]] << '\n';
  }
  return 0;
}
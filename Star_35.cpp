#include<iostream>
using namespace std;
const int N = 1e5 + 9;
int type[N];
long long weight[N];
long long prefix[N];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> type[i];
    for(int i = 1; i <= n; i++) cin >> weight[i];

    for(int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + (type[i] ? -1 : 1) * weight[i];

    long long ess = 0;
    for(int i = 1; i <= n; i++) {
      ess += weight[i] * type[i];
    }
    long long mi = 0; 
    long long fix = 0;
    for(int i = 1; i <= n; i++){
      fix = max(fix, prefix[i] - mi);
      mi = min(mi, prefix[i]);
    }
    cout << ess + fix << "\n";
  }
  
  return 0;
}
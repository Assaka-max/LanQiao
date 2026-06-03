#include<iostream>
#include<unordered_map>
using namespace std;
const int N = 1e5 + 9;
long long x;
int n, m;
int l, r;
long long a[N];
unordered_map<int, int> lst;
int f[N];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> x;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    lst[a[i]] = i;
    f[i] = max(f[i-1], lst[a[i] ^ x]);
  }
  for(int i = 1; i <= m; i++){
    cin >> l >> r;
    if(f[r] >= l){
      cout << "yes" << "\n";
    }else cout << "no" << '\n';
  }
  return 0;
}
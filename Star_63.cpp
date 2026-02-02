#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 3e5 + 10;
vector<int> X;
long long a[N];

struct Q{
  int a, b;
}add[N], que[N];

int getidx(int x){
  return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++){
    int x, w; cin >> x >> w;
    X.push_back(x);
    add[i] = {x, w};
  }

  for(int i = 1; i <= q; i++){
    int l, r; cin >> l >> r;
    X.push_back(l);
    X.push_back(r);
    que[i] = {l, r};
  }

  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());

  for(int i = 1; i <= n; i++) a[getidx(add[i].a)] += add[i].b;
  for(int i = 1; i <= X.size(); i++) a[i] += a[i-1];

  for(int i = 1; i <= q; i++) cout << a[getidx(que[i].b)] - a[getidx(que[i].a) - 1] << "\n";
  return 0;
}
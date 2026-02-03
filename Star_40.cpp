#include<iostream>
using namespace std;
const int N = 2e5 + 9;
long long a[N];
long long t[N];
int n, q;

int lowbit(int x) {return x & -x;}

void update(int k, long long x){
  for(int i = k; i <= n; i += lowbit(i)) t[i] += x;
}

long long getsum(int x){
  long long sum = 0;
  for(int i = x; i > 0; i -= lowbit(i)) sum += t[i];
  return sum;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) update(i, a[i]);

  while(q--){
    int op; cin >> op;
    if(op == 1){
      int k, v;
      cin >> k >> v;
      update(k, v);
    }else{
      int l, r;
      cin >> l >> r;
      cout << getsum(r) - getsum(l-1) << '\n';
    }
  }
  return 0;
}
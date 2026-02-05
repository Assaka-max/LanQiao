#include<iostream>
using namespace std;

const int N = 2e5 + 9;
long long a[N];
long long td[N];
long long tdi[N];
int n, q;

int lowbit(int x) {return x & -x;}

void update_td(int x, long long k){
  for(int i = x; i <= n; i += lowbit(i)) td[i] += k;
}

void update_tdi(int x, long long k){
  for(int i = x; i <= n; i += lowbit(i)) tdi[i] += x * k;
}

long long getsum(int x) {
  long long sum = 0;
  for(int i = x; i > 0; i -= lowbit(i)) sum += (x+1) * td[i] - tdi[i];
  return sum;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = n; i >= 1; i--) a[i] -= a[i-1];
  for(int i = 1; i <= n; i++) update_td(i, a[i]), update_tdi(i, a[i]);
  
  while(q--){
    int op; cin >> op;
    if(op == 1){
      int l, r;
      long long v;
      cin >> l >> r >> v;
      update_td(l, v), update_td(r+1, -v);
      update_tdi(l, v), update_tdi(r+1, -v);
    }else{
      int l, r;
      cin >> l >> r;
      cout << getsum(r) - getsum(l-1) << '\n';
    }
  }
  return 0;
}
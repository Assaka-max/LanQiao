#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int N = 2e5 + 9;
int n;
int sum;
int lt[N];
int rt[N];
set<pair<int, int>> segs;

int lowbit(int x){return x & -x;}

void update_lt(int x, int k){
  for(int i = x; i <= N; i += lowbit(i)) lt[i] += k;
}

void update_rt(int x, int k){
  for(int i = x; i <= N; i += lowbit(i)) rt[i] += k;
}

int getsum_lt(int x){
  int sum = 0;
  for(int i = x; i > 0; i -= lowbit(i)) sum += lt[i];
  return sum;
}

int getsum_rt(int x){
  int sum = 0;
  for(int i = x; i > 0; i -= lowbit(i)) sum += rt[i];
  return sum;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  while(n--){
    char a; cin >> a;
    if(a == 'A'){
      int l, r; cin >> l >> r;
      int intersect = getsum_lt(r) - getsum_rt(l-1);
      cout << intersect << '\n';
      auto item = segs.begin();
      while(item != segs.end() && item->first <= r){
        if(item->second >= l){
          update_lt(item->first, -1), update_rt(item->second, -1);
          item = segs.erase(item);
          sum--;
        }else item++;
      }
      segs.insert({l, r});
      update_lt(l, 1), update_rt(r, 1);
      sum++;
    }else cout << sum << '\n';
  }
  return 0;
}
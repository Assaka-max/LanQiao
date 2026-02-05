#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 2e5 + 9;
int a[N];
int tree[N];
vector<int> vec;
int n;

int getidx(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}

int lowbit(int x) {return x & -x;}

void update(int x, int k){
  for(int i = x; i <= n; i += lowbit(i)) tree[i] += k;
}

long long getsum(int x){
  long long sum = 0;
  for(int i = x; i > 0; i -= lowbit(i)) sum += tree[i];
  return sum;
}

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    vec.push_back(a[i]);
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());

  long long ans = 0;
  for(int i = 1; i <= n; i++){
    ans += getsum(n) - getsum(getidx(a[i]));
    update(getidx(a[i]), 1);
  }
  cout << ans;
  return 0;
}
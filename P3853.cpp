#include<iostream>
using namespace std;
const int N = 1e5+9;
int pos[N];
int l, n, k;

int check(int mid){
  int sum = 0;
  for(int i = 1; i < n; i++){
    int dis = pos[i+1] - pos[i];
    if(dis > mid) sum += (dis - 1) / mid;
  }
  return sum;
}


int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> l >> n >> k;
  for(int i = 1; i <= n; i++) cin >> pos[i];

  int left = 1;
  int right = 1e7 + 9;
  while (left+1 != right){
    int mid = (left + right)/2;
    if(check(mid) > k) left = mid;
    else right = mid;
  }
  if(check(1) <= k) cout << 1;
  else cout << right;

  return 0;
}

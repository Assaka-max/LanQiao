#include<iostream>
using namespace std;
const int N = 5e5+9;
int a[N];
int L, n, m;

int check(int mid){
  int will_move = 0;
  int last_stone = 0;
  for(int i = 1; i <= n; i++){
    if(a[i] - last_stone < mid) will_move++;
    else last_stone = a[i];
  }
  if(L - last_stone < mid) will_move++;
  return will_move;
}


int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> L >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  int l = 1;
  int r = 1e9+9;
  while (l+1 != r){
    int mid = (l+r)/2;
    if(check(mid) > m) r = mid;
    else l = mid;
  }
  cout << l;
  return 0;
}
#include<iostream>
using namespace std;
const int N = 5e4 + 9;
const int M = 5e4 + 9;
int n, m;
long long stone[N];

long long check(long long mid){
  long long res = 0;
  long long pre = 0;
  for(int i = 2; i <= n + 2; i++){
    if(stone[i] - pre < mid){
      res++;
      continue;
    }
    pre = stone[i];
  }
  return res;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int L;
  cin >> L >> n >> m;
  stone[n+2] = L;
  for(int i = 2; i <= n+1; i++) cin >> stone[i];
  long long l = 1;
  long long r = 1e9 + 9;
  while(l + 1 != r){
    long long mid = (l+r)/2;
    if(check(mid) <= m) l = mid;
    else r = mid;
  }
  cout << l;
  return 0;
}
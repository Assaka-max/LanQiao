#include<iostream>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int prefix[N];
int n;
int m;

int check(int mid){
  int sum = 0;
  int graph = 1;
  for(int i = 1; i <= n; i++){
    if(a[i] > mid) return 1;
    if(sum + a[i] > mid) {
      sum = a[i];
      graph++;
    }else{
      sum += a[i];
    }
  }
  if(graph > m) return 1;
  else return 0;
}


int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    prefix[i] = a[i] + prefix[i-1];
  }
  int l = 1;
  int r = 1e9 + 9;
  while (l+1 != r){
    int mid = (l+r)/2;
    if(check(mid)) l = mid;
    else r = mid;
  }
  if(!check(1)) cout << 1;
  else cout << r;
  return 0;
}
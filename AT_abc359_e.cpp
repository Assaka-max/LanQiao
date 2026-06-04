#include<iostream>
using namespace std;
const int N = 2e5 + 9;
long long res = 1;
int a[N];
int queue[N];
int h = 1;
int t = 0;
int n;

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++){
    if(h > t){
      queue[++t] = a[i];
      cout << res + queue[t] << ' ';
      continue;
    }
    if(a[i] <= queue[t]){
      res += a[i];
      queue[++t] = a[i];
      cout << res << ' ';
      continue;
    }
    long long sum = 0;
    while(h <= t && a[i] > queue[t]) {
      sum += a[i] - queue[t];
      t--;
    }
    res += sum;
    queue[++t] = a[i];
    cout << res << ' ';
  }
  return 0;
}
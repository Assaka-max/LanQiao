#include<iostream>
using namespace std;
const int N = 1e5 + 9;
double a[N];
double b[N];
int n;
double p;
bool check(double mid){
  double sum = mid * p;
  for(int i = 1; i <= n; i++){
    if(a[i]*mid < b[i]) continue;
    sum -= (b[i] - a[i]*mid);
  }
  if(sum >= 0) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> p;
  for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  double l = 0;
  double r = 1e10;
  while(r-l > 1e-6){
    double mid = (l+r)/2;
    if(check(mid)) l = mid;
    else r = mid;
  }
  if(check(1e10)) cout << -1;
  else cout << l;
  return 0;
}
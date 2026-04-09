#include<iostream>
using namespace std;

void proc(){
  long long a, b, c, k; cin >> a >> b >> c >>k;
  long long A = a;
  long long B = b;
  long long C = c;
  for(int i = 1; i <= k && i <= 60; i++){
    a = (B+C)/2;
    b = (A+C)/2;
    c = (A+B)/2;
    A = a, B = b, C = c;
  }
  cout << A << ' ' << B << ' ' << C << '\n';
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t; cin >> t;
  while (t--)
  {
    proc();
  }
  
  return 0;
}
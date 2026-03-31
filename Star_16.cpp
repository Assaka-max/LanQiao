#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> ans;
  for(int i = 1; i <= n / i; i++){
    if(n % i) continue;
    ans.push_back(i);
    if(i != n / i) ans.push_back(n/i);
  }
  sort(ans.begin(), ans.end());
  for(auto &x : ans){
    cout << x << ' ';
  }
  return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 2e9 + 5;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  vector<int> a;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    a.push_back(x);
  }

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  for(auto& x : a) cout << x << ' ';
  return 0;

}
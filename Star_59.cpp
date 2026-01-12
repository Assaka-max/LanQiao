#include<iostream>
#include<map>
#include<vector>
using namespace std;


void solve(){
  int n;
  map<string, int> a;
  vector<string> vec;
  string str;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> str;
    if(a.count(str)) a[str]++;
    else vec.push_back(str), a[str] = 1;
  }
  for(string i : vec) cout << i << ' ' << a[i] << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
  return 0;
}
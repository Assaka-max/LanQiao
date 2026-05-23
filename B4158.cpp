#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int t, n;
string s;
vector<int> res;

bool prime(string s){
  int num = stoi(s);
  if(num < 2) return false;
  for(int i = 2; i*i <= num; i++){
    if(num % i == 0) return false;
  }
  return true;
}

void dfs(int index){
  if(index == int(s.size())){
    if(prime(s)) res.push_back(stoi(s));
    return;
  }
  if(s[index] != '*') dfs(index + 1);
  else{
    for(int i = 0; i <= 9; i++){
      s[index] = i + '0';
      dfs(index + 1);
    }
    s[index] = '*';
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while(t--){
    cin >> s;
    dfs(0);
    sort(res.begin(), res.end());
    if(res.empty()) cout << -1 << endl;
    else cout << res[0] << endl;
    res.clear();
  }
  return 0;
}
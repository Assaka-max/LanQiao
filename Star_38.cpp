#include<iostream>
#include<stack>
#include<vector>
using namespace std;
const int N = 1e5+9;
int a[N];
vector<int> ans;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  stack<int> b;
  int point = 1;
  while (point <= n){
    if(b.empty()){
      b.push(a[point]);
      point++;
      continue;
    }
    if(a[point] > b.top()){
      ans.push_back(b.top());     
      b.pop();
      continue;
    }
    b.push(a[point]);
    point++;
  }
  while (!b.empty()){
    ans.push_back(b.top());
    b.pop();
  }
  for(int i = 0; i < n; i++){
    if(ans[i] != i+1) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
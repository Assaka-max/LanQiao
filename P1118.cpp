#include<iostream>
#include<vector>
using namespace std;
const int N = 15;
int n, sum;
bool isfind = false;
int a[N];
bool vis[N];
vector<int> current_row;
vector<int> new_row;
void res(){
  current_row.clear();
  new_row.clear();
  for(int i = 0; i < n; i++) current_row.push_back(a[i]);
  while(current_row.size() > 1){
    new_row.clear();
    for(int i = 0; i < current_row.size() - 1; i++){
      new_row.push_back(current_row[i] + current_row[i+1]);
    }
    current_row = new_row;
  }
  if(current_row[0] == sum){
    for(int i = 0; i < n; i++) cout << a[i] << ' ';
    isfind = true;
  }
}

void dfs(int step){
  if(isfind) return;
  if(step == n) {
    res();
    return;
  }
  for(int i = 1; i <= n; i++){
    if(!vis[i]){
      vis[i] = true;
      a[step] = i;
      dfs(step + 1);
      vis[i] = false;
      if(isfind) return;
    }
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> sum;
  dfs(0);
  return 0;
}
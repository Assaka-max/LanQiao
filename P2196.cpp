#include<iostream>
#include<vector>
using namespace std;
const int N = 24;
int n;
vector<int> graph[N];
int a[N];
int path[N];
int final_path[N];
int res = -1;

void update_path(){
  for(int i = 1; i <= n; i++) final_path[i] = path[i];
}

void dfs(int index, int sum){
  if(graph[index].empty()) {
    if(res >= max(res, sum)) return;
    res = sum;
    update_path();
    return;
  }
  for(auto &x : graph[index]){
    path[x] = 1;
    dfs(x, sum + a[x]);
    path[x] = 0;
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i < n; i++){
    int k = n - i;
    for(int j = 1; j <= k; j++){
      int f; cin >> f;
      if(f == 1) graph[i].push_back(i + j);
    }
  }
  for(int i = 1; i <= n; i++) graph[0].push_back(i);
  dfs(0, 0);
  for(int i = 1; i <= n; i++){
    if(final_path[i] == 1) cout << i << ' ';
  }
  cout << endl;
  cout << res;
  return 0;
}
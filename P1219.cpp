#include<iostream>
#include<vector>
using namespace std;
const int N = 14;
int n;
int total = 0;
bool vis_col[30] = {false};
bool vis_diag1[30] = {false};
bool vis_diag2[30] = {false};
vector<int> queen_pos;

void dfs(int row){
  if(row == n){
    total++;
    if(total <= 3){
      for(int i = 0; i < n; i++) cout << queen_pos[i] << ' ';
      cout << endl;
    }
    return;
  }
  for(int i = 0; i < n; i++){
    if(!vis_col[i] && !vis_diag1[row-i+N] && !vis_diag2[row+i]){
      queen_pos.push_back(i+1);
      vis_col[i] = true;
      vis_diag1[row-i+N] = true;
      vis_diag2[row+i] = true;
      dfs(row+1);
      vis_col[i] = false;
      vis_diag1[row-i+N] = false;
      vis_diag2[row+i] = false;
      queen_pos.pop_back();
    }
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  dfs(0);
  cout << total;
  return 0;
}
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

const vector<vector<int>> change = {
  {1, 1, 0, 1, 0, 0, 0, 0, 0},
  {1, 1, 1, 0, 1, 0, 0, 0, 0},
  {0, 1, 1, 0, 0, 1, 0, 0, 0},
  {1, 0, 0, 1, 1, 0, 1, 0, 0},
  {0, 1, 0, 1, 1, 1, 0, 1, 0},
  {0, 0, 1, 0, 1, 1, 0, 0, 1},
  {0, 0, 0, 1, 0, 0, 1, 1, 0},
  {0, 0, 0, 0, 1, 0, 1, 1, 1},
  {0, 0, 0, 0, 0, 1, 0, 1, 1}
};

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int initial_state = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++) {
      int x; cin >> x;
      if(x) initial_state |= (1 << (i*3 + j));
    }
  }

  const int target_state = (1 << 9) - 1;
  queue<int> q;
  unordered_set<int> visited;
  q.push(initial_state);
  visited.insert(initial_state);
  int steps = 0;

  while(!q.empty()){
    int level_size = q.size();
    for(int i = 0; i < level_size; i++){
      int current_state = q.front();
      q.pop();
      if(current_state == target_state){
        cout << steps;
        return 0;
      }

      for(int i = 0; i < 9; i++){
        int next_state = current_state;
        for(int j = 0; j < 9; j++){
          if(change[i][j]) next_state ^= (1 << j);
        }
        if(visited.find(next_state) == visited.end()){
          visited.insert(next_state);
          q.push(next_state);
        }
      }

    }
    steps++;
  }
  return 0;
}
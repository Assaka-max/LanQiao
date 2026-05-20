#include<iostream>
using namespace std;
const int N = 11;
int n;
char ops[N];

bool check(){
  int sum = 0;
  int num = 1;
  int sign = 1;
  for(int i = 1; i < n; i++){
    if(ops[i] == ' '){
      num = num * 10 + i + 1;
    }else{
      sum += sign * num;
      num = i+1;
      sign = (ops[i] == '+') ? 1 : -1;
    }
  }
  sum += sign * num;
  return sum == 0;
}

void dfs(int step){
  if(step == n){
    if (check()) {
      cout << "1";
      for (int i = 1; i < n; i++) {
        cout << ops[i] << i + 1;
      }
      cout << endl;
    }
    return;
  }
  ops[step] = ' ';
  dfs(step+1);

  ops[step] = '+';
  dfs(step+1);

  ops[step] = '-';
  dfs(step+1);
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  dfs(1);

  return 0;
}
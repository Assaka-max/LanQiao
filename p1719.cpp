#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
const int N = 125;
int a[N][N];
int prefix[N][N];

int main(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> a[i][j];
      prefix[i][j] = prefix[i-1][j] + a[i][j];
    }
  }
  int ans = INT_MIN;

  for(int top = 1; top <= n; top++){
    for(int bottom = top; bottom <= n; bottom++){
      int col_sum[N] = {0};
      for(int i = 1; i <= n; i++) col_sum[i] = prefix[bottom][i] - prefix[top-1][i];

      int max_so_far = col_sum[1];
      int max_ending = col_sum[1];

      for(int j = 2; j <= n; j++){
        max_ending = max(col_sum[j], max_ending + col_sum[j]);
        max_so_far = max(max_so_far, max_ending);
      }
      ans = max(ans, max_so_far);
    }
  }
  cout << ans << "\n";
  return 0;
}
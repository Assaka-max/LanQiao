#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 9;
int n;
int a[N];
int b[N];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];
  sort(a + 1, a + 1 + n, greater());
  sort(b + 1, b + 1 + n, greater());
  int res = 0;
  for(int i = 1, j = 1; i <= n && j <= n;){
    if(a[i] - b[j] <= 0) {
      j++;
      res++;
      continue;
    }
    i++;
    j++;
  }
  cout << res;
  return 0;
}
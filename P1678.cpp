#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5+9;
int a[N];
int b[N];
int n, m;

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= m; i++) cin >> b[i];
  sort(a+1, a+n+1);

  long long sum = 0;
  for(int i = 1; i <= m; i++){
    int close;
    int l = 1;
    int r = n;
    if(n == 1){
      sum += abs(a[1] - b[i]);
      continue;
    }
    while(l+1 != r){
      int mid = (l+r)/2;
      if(a[mid] <= b[i]) l = mid;
      else r = mid;
    }
    if(abs(a[l] - b[i]) <= abs(a[r] - b[i])) close = abs(a[l] - b[i]);
    else close = abs(a[r] - b[i]);
    sum += close;
  }

  cout << sum;
  return 0;
}
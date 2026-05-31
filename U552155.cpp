#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e5 + 9;
int a[N];
int t, n;
int prefix[N];

long long res(int x){
  long long sum = 0;
  int index = -1;
  for(int i = 1; i <= n; i++){
    if(a[i] > 0){
      index = i;
      break;
    }
  }
  if(index == 1){
    for(int i = 1; i < x; i++) sum += a[index-1+i] * i;
    sum += (prefix[n] - prefix[x-1]) * x;
  }else if(index == -1){
    sum += (prefix[n-x-1] - prefix[0]) * 1;
    for(int i = n-x; i <= n; i++) sum += a[i] * 
  }else{

  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while(t--){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i];
    sort(a + 1, a + n + 1);

  }
  return 0;
}
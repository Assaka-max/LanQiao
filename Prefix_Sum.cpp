#include<iostream>
using namespace std;
const long long N = 100005;
long long a[N];
long long prefix[N];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n, q;
    cin >> n >> q;
    prefix[0] = 0;
    for(int i = 0; i < n; i++){
      cin >> a[i];
      prefix[i+1] = a[i] + prefix[i];
    }

    while (q--){
      long long l, r;
      long long sum;
      cin >> l >> r;
      sum = prefix[r] - prefix[l-1];
      cout << sum << "\n";
    }
    
  }
  
  return 0;
}
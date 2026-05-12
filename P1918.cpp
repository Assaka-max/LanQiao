#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e5 + 9;
int n;
pair<int, int> ball[N];

int find(int m){
  int l = 1; int r = n;
  while(l + 1 != r){
    int mid = (l + r)/2;
    if(ball[mid].first <= m) l = mid;
    else r = mid;
  }
  if(ball[r].first == m) return ball[r].second;
  else if(ball[l].first == m) return ball[l].second;
  return 0;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    int a; cin >> a;
    ball[i] = {a, i};
  }
  sort(ball + 1, ball + 1 + n);
  int q; cin >> q;
  while (q--){
    int m; cin >> m;
    cout << find(m) << endl;;
  }
  
  return 0;
}
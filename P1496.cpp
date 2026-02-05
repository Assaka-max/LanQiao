#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 4e4 + 9;
int n;
vector<pair<int, int>> segs;
vector<int> alls;
int covered[N];
int getidx(int x) {return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;}

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    int a, b;
    cin >> a >> b;
    segs.push_back({a, b});
    alls.push_back(a);
    alls.push_back(b);
  }

  sort(alls.begin(), alls.end());
  alls.erase(unique(alls.begin(), alls.end()), alls.end());

  for(auto &x : segs){
    int l = getidx(x.first);
    int r = getidx(x.second);
    for(int i = l; i < r; i++) covered[i] = 1;
  }

  long long ans = 0;
  for(int i = 1; i < alls.size(); i++){
    if(covered[i]) ans += alls[i] - alls[i-1];
  }
  cout << ans;
  return 0;
}
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 1e5 + 9;
pair<int, int> a[N];
queue<pair<int, int>> q;
vector<int> ans;
int t[N];
int n, d, k;

void is_hot(int index){
  if(t[index] >= k) ans.push_back(index);
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> d >> k;
  for(int i = 1; i <= n; i++){
    int ts, id; cin >> ts >> id;
    a[i] = {ts, id};
  }
  sort(a + 1, a + 1 + n);
  for(int i = 1; i <= n; i++){
    while(!q.empty() && a[i].first - q.front().first >= d) {
      t[q.front().second]--;
      q.pop();
    }
    q.push(a[i]);
    t[a[i].second]++;
    is_hot(a[i].second);
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  for(auto &x : ans) cout << x << '\n';
  return 0;
}
#include<iostream>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int st[N], top;
int l[N], r[N];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];

  for(int i = 1; i <= n; i++){
    while(top && a[st[top]] >= a[i]) top--;
    if(!top) l[i] = i;
    else l[i] = i - st[top];
    st[++top] = i;
  }

  top = 0;

  for(int i = n; i > 0; i--){
    while(top && a[st[top]] > a[i]) top--;
    if(!top) r[i] = n - i + 1;
    else r[i] = st[top] - i;
    st[++top] = i;
  }

  long long ans = 0;
  for(int i = 1; i <= n; i++) ans += 1LL * a[i] * l[i] * r[i];
  cout << ans;
  return 0;
}
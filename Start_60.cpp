#include<iostream>
#include<stack>
using namespace std;
const int N = 2e5 + 9;
int a[N];
int st[N];
int ans[N];
int top;

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  
  for(int i = 1; i <= n; i++){
    while (top && a[st[top]] >= a[i]) top--;
    if(!top) ans[i] = -1;
    else ans[i] = a[st[top]];
    st[++top] = i;
  }
  
  for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}
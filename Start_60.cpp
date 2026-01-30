#include<iostream>
#include<stack>
using namespace std;
const int N = 2e5 + 9;
int a[N];
stack<int> st;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  int index = 1;
  while (index <= n){
    if(st.empty()) cout << -1 << ' ';
    else if(st.top() < a[index]) {
      cout << st.top() << ' ';
    }else {
      st.pop();
      continue;
    }
    st.push(a[index]);
    index++;
  }
  
  return 0;
}
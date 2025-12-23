#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
const int N = 2e5 + 9;
struct book{
  int h;
  int s;
  int w;
  bool operator < (const book& u) const{
    if(h == u.h && s == u.s) return w < u.w;
    if(h == u.h) return s < u.s;
    return h < u.h;
  } 
};
book books[N];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> books[i].h >> books[i].s >> books[i].w;
  }
  sort(books + 1, books + 1 + n);
  reverse(books + 1, books + 1 + n);
  for(int i = 1; i <= n; i++){
    cout << books[i].h << " " 
    << books[i].s << " " 
    << books[i].w << "\n";
  }
  return 0;
}